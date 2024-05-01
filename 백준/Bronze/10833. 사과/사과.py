def sol(n):
    res = 0
    for i in range(n):
        students, apples = map(int, input().split())
        res += apples % students
    return res

if __name__ == "__main__":
    print(sol(int(input())))