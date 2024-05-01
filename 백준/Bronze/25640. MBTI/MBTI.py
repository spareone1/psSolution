def solution(jin):
    ans = 0
    for i in range(int(input())):
        if jin == input(): ans += 1
    return ans

if __name__ == "__main__":
    print(solution(input()))