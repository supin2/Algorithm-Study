# 백준 10866번 : 덱
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())

    st = []
    for _ in range(N):
        cmd = input().split()

        if cmd[0] == "push_front":
            st.insert(0, cmd[1])
        elif cmd[0] == "push_back":
            st.append(cmd[1])
        elif cmd[0] == "pop_front":
            if st:
                print(st[0])
                st.pop(0)
            else:
                print(-1)      
        elif cmd[0] == "pop_back":
            if st:
                print(st[-1])
                st.pop()
            else:
                print(-1)
        elif cmd[0] == "size":
            print(len(st))
        elif cmd[0] == "empty":
            if st:
                print(0)
            else:
                print(1)
        elif cmd[0] == "front":
            if st:
                print(st[0])
            else:
                print(-1)
        elif cmd[0] == "back":
            if st:
                print(st[-1])
            else:
                print(-1)