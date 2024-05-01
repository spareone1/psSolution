arr = [0 for i in range(26)]
string = input()

for i in string:
    arr[ord(i) - 97] += 1
    
for i in arr:
    print(i, end = ' ')