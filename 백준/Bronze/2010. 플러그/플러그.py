import sys

if __name__ == "__main__":
    res = 0
    
    input = sys.stdin.readline
    n = int(input().rstrip())
    
    for i in range(n):
        res += int(input().rstrip())
    print(res - n + 1)