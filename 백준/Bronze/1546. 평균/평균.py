def sol(n):
    arr = list(map(int, input().split()))
    m = max(arr)
    for i in range(len(arr)):
        arr[i] = round(arr[i] / m * 100, 2)
    return sum(arr) / len(arr)

if __name__ == '__main__':
    print(sol(int(input())))