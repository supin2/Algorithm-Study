# 백준 1021번 : 회전하는 큐
import sys
from collections import deque
input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())
    find = list(map(int, input().split()))
    
    q = deque(i for i in range(1, N + 1))
    ans = 0

    for i in range(M):
        totLen = len(q)
        idx = q.index(find[i])
        diff = totLen - idx

        if idx < diff:
            while True:
                if q[0] == find[i]:
                    q.popleft()
                    break
                else:
                    q.append(q.popleft())
                    ans += 1
        else:
            while True:
                if q[0] == find[i]:
                    q.popleft()
                    break
                else:
                    q.appendleft(q.pop())
                    ans += 1
    print(ans)