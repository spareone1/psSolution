def solution(a, b, c):
    if a == b == c == 60: return "Equilateral"
    if a + b + c != 180: return "Error"
    if a != b and b != c and a != c: return "Scalene"
    return "Isosceles"

if __name__ == "__main__":
    a = int(input())
    b = int(input())
    c = int(input())
    print(solution(a, b, c))