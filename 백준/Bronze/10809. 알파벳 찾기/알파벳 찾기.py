def solution(word):
    res = [-1 for i in range (26)]
    for i in range(len(word)):
        if res[ord(word[i]) - 97] == -1:
            res[ord(word[i]) - 97] = i
    return res
        
if __name__ == "__main__":
    for i in solution(input()):
        print(i, end=' ')
