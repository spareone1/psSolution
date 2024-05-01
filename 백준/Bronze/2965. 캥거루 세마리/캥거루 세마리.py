a, b, c = map(int, input().split())

print(b - a - 1 if b - a - 1 > c - b - 1 else c - b - 1)