n = int(input())
cur = 2
print(2)
for i in range (2,n+1):
    newcur = i*(i+1)*(i+1)
    print(newcur - i + 1)
    cur = i*(i+1)