# 백준 1874번 : 스택 수열
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    st = []
    ans = []
    now = 1

    for _ in range(n):
        num = int(input())

        while now <= num:
            st.append(now)
            ans.append('+')
            now += 1

        if st[-1] == num:
            st.pop()
            ans.append('-')
        else:
            print("NO")
            exit(0)
    
    for ch in ans:
        print(ch)