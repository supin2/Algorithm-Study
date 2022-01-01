# 백준 1406번 : 에디터
import sys

if __name__ == "__main__":
    text = list(sys.stdin.readline().strip())
    temp = []
    M = int(input())

    for i in range(M):
        cmd = sys.stdin.readline().strip()
        if cmd[0] == 'L':
            if text:
                temp.append(text.pop())
        elif cmd[0] == 'D':
            if temp:
                text.append(temp.pop())
        elif cmd[0] == 'B':
            if text:
                text.pop()
        elif cmd[0] == 'P':
            text.append(cmd[2])

    print(''.join(text + list(reversed(temp))))