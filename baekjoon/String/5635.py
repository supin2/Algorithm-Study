# 백준 5635번 : 생일
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    students = []

    for _ in range(n):
        name, dd, mm, yyyy = input().rstrip().split()
        if len(dd) == 1:
            dd = '0' + dd
        if len(mm) == 1:
            mm = '0' + mm

        students.append((yyyy + mm + dd, name))

    students.sort(key=lambda x: int(x[0]))
    print(students[-1][1])
    print(students[0][1])