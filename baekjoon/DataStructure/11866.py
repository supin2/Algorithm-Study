# 백준 11866번 : 요세푸스 문제 0
import sys
from collections import deque
input = sys.stdin.readline

if __name__ == "__main__":
    N, K = map(int, input().split())

    lst = deque()
    ans = []
    idx = 0 

    for i in range(N):
        lst.append(i + 1)

    print("<", end='')
    while len(lst) > 0:
        for _ in range(K - 1):
            lst.append(lst.popleft())
        print(lst.popleft(), end='')

        if len(lst) > 0:
            print(", ", end='')
    print(">")
