if __name__ == "__main__":
    for i in range(int(input())):
        a, b = map(int, input().split())
        print((lambda x, y : 2 - x + y)(a, b))