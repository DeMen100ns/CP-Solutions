n = int(input())
a = [0] + [int(i) for i in input().split()]
p = [0] * (n + 1)
for i in range(1, n + 1):
 p[a[i]] = i
cnt = 0
for i in range(1, n + 1):
 if (i != a[i]):
  cnt += 1
  k = a[i]
  a[i], a[p[i]] = a[p[i]], a[i]
  p[k], p[a[i]] = p[a[i]], p[k]
 #print(a)
 #print(p)
if ((3 * n) % 2 == cnt % 2):
 print("Petr")
else : print("Um_nik")
#2 4 5 1 3
#1 4 5 2 3
#1 2 5 4 3
#1 2 3 4 5