def sol(n):
    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end = "")
        for j in range(i * 2 + 1):
            print("*", end = "")
        print("")

if __name__ == "__main__":
    sol(int(input()))