def fibo(n, arr):
    if arr[n] != 0 or n == 0:
        return arr[n]
    else:
        arr[n] = fibo(n - 1, arr) + fibo(n - 2, arr)
        return arr[n]

if __name__ == "__main__":
    arr = [0 for i in range(46)]
    arr[1] = 1
    print(fibo(int(input()), arr))