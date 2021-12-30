# 백준 10799번 : 쇠막대기
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    lst = list(input())
    st = []
    ans = 0

    for i in range(len(lst)):
        ch = lst[i]
        if ch == '(':
            st.append('(')
        elif ch == ')':
            st.pop()
            if lst[i - 1] == '(':
                ans += len(st)
            else:
                ans += 1
    print(ans)