if __name__ == "__main__":
    for i in range(int(input())):
        s, n = input().split()
        for j in n:
            for k in range(int(s)):
                print(j, end="")
        print("")