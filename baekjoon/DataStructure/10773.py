# 백준 10773번 : 제로
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    K = int(input())
    lst = []

    for _ in range(K):
        num = int(input())
        if num == 0:
            lst.pop()
        else:
            lst.append(num)

    print(sum(lst))