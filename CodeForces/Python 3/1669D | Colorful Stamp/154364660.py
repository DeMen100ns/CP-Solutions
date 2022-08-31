t = int(input())
for i in range(t):
    n = int(input())
    s = input().split('W')
    f = True
    for x in s:
        if (len(x) == 0):continue
        g = x[0] * len(x)
        f &= (g != x)
    if f:
        print("YES")
    else:
        print("NO")