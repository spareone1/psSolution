def sol(n):
    count = 0
    for i in n:
        if i == 0: count+= 1
    if count == 1: return 'A'
    if count == 2: return 'B'
    if count == 3: return 'C'
    if count == 4: return 'D'
    else: return 'E'

if __name__ == '__main__':
    for i in range(3):
        print(sol(map(int, input().split())))