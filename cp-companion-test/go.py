import http.server
import json
from pathlib import Path
import re

# Returns unmarshalled or None
def listen_once(*, timeout=None):
    json_data = None

    class CompetitiveCompanionHandler(http.server.BaseHTTPRequestHandler):
        def do_POST(self):
            nonlocal json_data
            json_data = json.load(self.rfile)

    with http.server.HTTPServer(('127.0.0.1', 10043), CompetitiveCompanionHandler) as server:
        server.timeout = timeout
        server.handle_request()

    if json_data is not None:
        print(f"Got data {json.dumps(json_data)}")
    else:
        print("Got no data")
    return json_data

def listen_many(*, num_items=None, num_batches=None, timeout=None):
    if num_items is not None:
        res = []
        for _ in range(num_items):
            cur = listen_once(timeout=None)
            res.append(cur)
        return res

    if num_batches is not None:
        res = []

        batches = {}
        while len(batches) < num_batches or any(need for need, tot in batches.values()):
            print(f"Waiting for {num_batches} batches:", batches)
            cur = listen_once(timeout=None)
            res.append(cur)

            cur_batch = cur['batch']
            batch_id = cur_batch['id']
            batch_cnt = cur_batch['size']
            if batch_id not in batches:
                batches[batch_id] = [batch_cnt, batch_cnt]
            assert batches[batch_id][0] > 0
            batches[batch_id][0] -= 1

        return res

    res = [listen_once(timeout=None)]
    while True:
        cnd = listen_once(timeout=timeout)
        if cnd is None:
            break
        res.append(cnd)
    return res

NAME_PATTERN = re.compile(r'^(?:Problem )?([A-Z][0-9]*)\b')

def save_samples(data, prob_dir):
    # with open(prob_dir / 'problem.json', 'w') as f:
    #     json.dump(data, f)

    for i, t in enumerate(data['tests'], start=1):
        with open(prob_dir / f'in{i}', 'w') as f:
            f.write(t['input'])
        with open(prob_dir / f'out{i}', 'w') as f:
            f.write(t['output'])

# Providing name = '.'
def make_prob(data):

    prob_dir = Path('.')

    print("Saving samples...")
    save_samples(data, prob_dir)

def main():

    datas = listen_many(num_batches=1)
    for data in datas:
        make_prob(data)

if __name__ == '__main__':
    main()
