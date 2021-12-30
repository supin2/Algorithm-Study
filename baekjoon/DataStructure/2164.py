# 백준 2164번 : 카드2
import sys
from collections import deque
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    
    q = deque()

    for i in range(N):
        q.append(i + 1)
    
    while len(q) > 1:
        q.popleft()
        q.append(q.popleft())
    
    print(q.pop())