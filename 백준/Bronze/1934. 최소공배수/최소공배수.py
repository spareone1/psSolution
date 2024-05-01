def gcd(m, n):
    if m < n: m, n = n, m
    while(m % n != 0):
        tmp = m % n
        m = n
        n = tmp
    return n
    
def lcm(m, n):
    return m * n // gcd(m, n)

if __name__ == "__main__":
    for i in range(int(input())):
        m, n = map(int, input().split())
        print(lcm(m, n))