if __name__ == "__main__":
    size = int(input())
    arr = list(map(int, input().split()))
    key = int(input())
    
    ans = 0
    for i in arr:
        if i == key:
            ans += 1
        
    print(ans)