n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()];t=0
for i in range(n):
    t+=a[i]*b[i]
if t==0:print("Yes")
else:print("No")