n = int(input())
k = input().split('C')
cnt = len(k)
for s in k:
    cnt -= 1
    a = s.count('A')
    b = s.count('B')
    for i in range(a):
        print('A', end = '')
    for i in range(b // 2):
        print('A', end = '')
    if (b % 2 == 1):
        print('B', end = '')
    if (cnt > 0) : print('C', end = '')