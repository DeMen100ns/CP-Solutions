a=[0]*200007
n,w=[int(i) for i in input().split()]
for i in range(n):
    l,r,val=[int(i) for i in input().split()]
    a[l]+=val
    a[r]-=val
t=0
for i in range(200007):
    t+=a[i]
    if t>w:
        print("No")
        exit()
print("Yes")