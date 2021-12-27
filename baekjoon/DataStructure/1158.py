# 백준 1158번 : 요세푸스 문제
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N, K = map(int, input().split())

    lst = [i for i in range(1, N + 1)]
    ans = []
    idx = 0

    for _ in range(N):
        idx += K - 1
        if idx >= len(lst):
            idx %= len(lst)
        
        ans.append(str(lst.pop(idx)))

    print('<', ", ".join(ans), '>', sep='')