def factorization(n):
    if n == 1: return
    else:
        for i in range(2, n + 1):
            while(True):
                if n % i == 0:
                    print(i)
                    n /= i
                else:
                    break

if __name__ == "__main__":
    factorization(int(input()))