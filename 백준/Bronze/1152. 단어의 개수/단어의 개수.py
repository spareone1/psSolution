string = input()
string = string.strip()
if string == '': print(0)
else: print(string.count(' ') + 1)