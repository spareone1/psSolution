an, am = map(int, input().split())

a = []
for i in range(an):
    temp = list(map(int, input().split()))
    a.append(temp)


bm, bk = map(int, input().split())

b = []
for i in range(bm):
    temp = list(map(int, input().split()))
    b.append(temp)


ans = []
for i in range(an):
    res = []
    for j in range(bk):
        temp = 0
        for k in range(am):
            temp += a[i][k] * b[k][j]
        res.append(temp)
    ans.append(res)

for i in ans:
    for j in i:
        print(j, end=' ')
    print('')
