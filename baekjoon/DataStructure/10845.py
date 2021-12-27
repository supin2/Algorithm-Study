# 백준 10845번 : 큐
import sys
input = sys.stdin.readline


def push(num):
    q.append(num)

def pop():
    if not q:
        return -1
    else:
        return q.pop(0)

def size():
    return len(q)

def empty():
    if not q:
        return 1
    else:
        return 0

def front():
    if not q:
        return -1
    else:
        return q[0]

def back():
    if not q:
        return -1
    else:
        return q[-1]

q = []

if __name__ == "__main__":
    N = int(input())

    for _ in range(N):
        cmd = input().split()

        if cmd[0] == "push":
            push(cmd[1])
        elif cmd[0] == "pop":
            print(pop())
        elif cmd[0] == "size":
            print(size())
        elif cmd[0] == "empty":
            print(empty())
        elif cmd[0] == "front":
            print(front())
        elif cmd[0] == "back":
            print(back())
