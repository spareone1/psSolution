import sys

if __name__ == "__main__":
    input = sys.stdin.readline
    for i in range(int(input().rstrip())):
        print(sum(map(int, input().split())))