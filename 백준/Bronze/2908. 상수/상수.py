def solution(n, m):
    return n if n > m else m

if __name__ == "__main__":
    n, m = input().split()
    print(solution(int(n[::-1]), int(m[::-1])))
