def sol(n):
    lt = 0
    for i in range(3):
        lt += (ord(n[i]) - 65) * 26 ** (2 - i)
    return 'nice' if (lt - int(n[4:])) ** 2 <= 10000 else 'not nice'

if __name__ == '__main__':
    for i in range(int(input())):
        print(sol(input()))