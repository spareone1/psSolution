def solution():
    sum = 0
    for i in range(5):
        sum += (lambda x : x if x > 40 else 40)(int(input()))
    return sum // 5

if __name__ == "__main__":
    print(solution())