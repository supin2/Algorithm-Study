# 백준 10828번 : 스택
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    st = []
    for _ in range(N):
        cmd = input().split()

        if cmd[0] == 'push':
            st.append(cmd[1])
        elif cmd[0] == 'pop':
            if len(st) == 0:
                print(-1)
            else:
                print(st.pop())
        elif cmd[0] == 'size':
            print(len(st))
        elif cmd[0] == 'empty':
            if st:
                print(0)
            else:
                print(1)
        elif cmd[0] == 'top':
            if st:
                print(st[-1])
            else:
                print(-1)