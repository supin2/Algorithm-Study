# 백준 14425번 : 문자열 집합
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n, m = map(int, input().split())
    strings = {input().rstrip() for _ in range(n)}
    cnt = 0

    for idx in range(m):
        string = input().rstrip()
        if string in strings:
            cnt += 1

    print(cnt)