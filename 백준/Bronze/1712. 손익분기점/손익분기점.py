def solution(a, b, c):
    if (b >= c):
        return -1
    return a//(c - b) + 1

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    print(solution(a, b, c))
