# 백준 9012번 : 괄호
import sys
input = sys.stdin.readline

def checkVPS(paren):
    st = []
    for ch in paren:
        if ch == '(':
            st.append('(')
        elif ch == ')':
            if st and st[-1] == '(':
                st.pop()
            else:
                return "NO"
                
    if st:
        return "NO"
    else:
        return "YES"

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        test = input().rstrip()
        print(checkVPS(test))