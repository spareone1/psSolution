if __name__ == "__main__":
    ans, idx = 0, 0
    for i in range(9):
        n = int(input())
        if n > ans:
            ans = n
            idx = i + 1
            
    print(ans)
    print(idx)