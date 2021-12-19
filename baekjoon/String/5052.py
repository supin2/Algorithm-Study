# 백준 5052번 : 전화번호 목록
import sys

def sol(lst):
    for i in range(len(lst) - 1):
        if lst[i] == lst[i + 1][0:len(lst[i])]:
            return False
    return True

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())
        numList = []

        for _ in range(n):
            numList.append(sys.stdin.readline().strip())
        numList.sort()

        if sol(numList) == False:
            print("NO")
        else:
            print("YES")