def solution(n):
    res = [0 for i in range(1000001)]
    res[2] = res[3] = 1

    if n <= 3:
        return res[n]
    
    for i in range(4, n + 1):
        if i % 3 != 0 and i % 2 != 0:
            res[i] = res[i - 1] + 1
        elif i % 2 == 0 and i % 3 == 0:
            res[i] = min(res[i - 1] + 1, res[int(i / 2)] + 1, res[int(i / 3)] + 1)
        elif i % 3 == 0:
            res[i] = min(res[i - 1] + 1, res[int(i / 3)] + 1)
        elif i % 2 == 0:
            res[i] = min(res[i - 1] + 1, res[int(i / 2)] + 1)

    return res[n]

if __name__ == "__main__":
    print(solution(int(input())))