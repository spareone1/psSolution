def solution():
    n, k = map(int, input().split())
    item = []
    for i in range(n):
        w, v = map(int, input().split())
        item.append([w, v])

    p = [[0 for i in range(k + 1)] for i in range(n + 1)]
    
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if item[i - 1][0] > j:
                p[i][j] = p[i - 1][j]
            else:
                p[i][j] = max(item[i - 1][1] + p[i - 1][j - item[i - 1][0]], p[i - 1][j])

    print(p[n][k])

if __name__ == '__main__':
    solution()
