# 백준 11652번 : 카드
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    dic = {}

    for _ in range(N):
        card = int(input())
        if card in dic:
            dic[card] += 1
        else:
            dic[card] = 1

    ans = sorted(dic.items(), key = lambda x : (-x[1], x[0]))
    print(ans[0][0])