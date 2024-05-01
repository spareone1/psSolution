def sol(n, m):
    m += int(input())
    if m >= 60:
        n += (m // 60)
        m = m % 60
    if n >= 24:
        n = n % 24
    return str(n) + ' ' + str(m)

if __name__ == "__main__":
    n, m = map(int, input().split())
    print(sol(n, m))