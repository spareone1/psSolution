def solution(n):
    for i in range(n):
        for j in range(n + i):
            if i == n - 1 or j == n - i - 1 or j == n + i - 1:
                print("*", end = "")
            else:
                print(" ", end = "")
        print("")

if __name__ == "__main__":
    solution(int(input()))