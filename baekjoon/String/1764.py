# 백준 1764번 : 듣보잡
if __name__ == "__main__":
    N, M = map(int, input().split())

    st1 = set()
    st2 = set()

    for _ in range(N):
        st1.add(input())
    
    for _ in range(M):
        st2.add(input())

    ans = sorted(list(st1 & st2))
    print(len(ans))

    for i in ans:
        print(i)