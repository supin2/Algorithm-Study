# 백준 1966번 : 프린터 큐
import sys
from collections import deque
input = sys.stdin.readline

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        N, M = map(int, input().split())
        priority = list(map(int, input().split()))
        check = [False for i in range(N)]
        check[M] = True
        now = 0
        
        while True:
            if priority[0] == max(priority):
                now += 1
                if check[0] == True:
                    print(now)
                    break
                else:
                    del priority[0]
                    del check[0]
            else:
                priority.append(priority[0])
                check.append(check[0])
                del priority[0]
                del check[0]
