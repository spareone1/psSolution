def sol(n, arr):
    res = 0
    flag = 0
    for i in arr:
        if i == 1:
            res += 1 + flag
            flag += 1
        else:
            flag = 0
    return res

if __name__ == "__main__":
    n = int(input())
    arr = map(int, input().split())
    print(sol(n, arr))