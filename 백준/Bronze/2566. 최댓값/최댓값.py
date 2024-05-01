if __name__ == '__main__':
    ans = -1
    x = 0
    y = 0
    for i in range(9):
        temp = list(map(int, input().split()))
        
        if ans < max(temp):
            ans = max(temp)
            x = i + 1
            y = temp.index(max(temp)) + 1
            
    print(ans)
    print(x, y)