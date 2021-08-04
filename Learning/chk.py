def closest_smaller(N):
  
    N = str(N)
  
    l = list(map(int, N))
    length = len(l)
    pos = -1
    for i in range(length):
        if l[i] % 2 == 0:
            pos = i
            break
    if l[pos] == 0:
        l[pos] = 9
        for i in range(pos - 1, -1, -1):
            if l[i] == 1:
                if i == 0:
                    l[i] = 0
                    break
                      
                l[i] = 9
            else:
                l[i] -= 2
                break
    else:
        l[pos] -= 1
    for i in range(pos + 1, length):
        l[i] = 9
    if l[0] == 0:
        l.pop(0)
    result = ''.join(map(str, l))
    return result

def closest_greater(N):
  
    N = str(N)
  
    l = list(map(int, N))
    length = len(l)
    pos = -1
    for i in range(length):
        if l[i] % 2 == 0:
            pos = i
            break
    l[pos] += 1
  
    for i in range(pos + 1, length):
        l[i] = 1
  
    result = ''.join(map(str, l))
    return result

def check_all_digits_odd(N):
    N = str(N)
    l = list(map(int, N))
    length = len(l)
    pos = -1
    for i in range(length):
        if l[i] % 2 == 0:
            pos = i
            break
    if pos == -1:
        return True
    return False
  
def closestNumber(N):
    if check_all_digits_odd(N):
        print(N)
    else:
        l = int(closest_smaller(N))
        r = int(closest_greater(N))
        if abs(N - l) <= abs(N - r):
            print(l)
        else:
            print(r)
