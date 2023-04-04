def get_data(file_name):
    with open(file_name, 'r') as file:
        data = file.read().rstrip()
        rows = data.split('\n')
        assert(len(rows) == 249)
        return rows


two = get_data('two')
two_name = 'CountryAlpha2'
three = get_data('three')
three_name = 'CountryAlpha3'
full = get_data('full')
num = get_data('num')
# print(',\n'.join(full))

def match_print(leftname, left, rightname, right):
    assert(len(left) == len(right))
    assert(len(left) == 249)

    for i in range(len(left)):
        putleft = '::' if len(leftname) > 0 else ''
        putright = '::' if len(rightname) > 0 else ''
        print(leftname + putleft + left[i] + ' => ' + rightname + putright + right[i] + ',')

# match_print(two_name, two, 'Self', full)
# match_print('Country', full, '', num)
# match_print(three_name, three, 'Self', full)

for i in range(len(num)):
    print(num[i] + ' == ' + two[i] + ' == ' + three[i] + ' == ' + full[i])
