import sys
input = sys.stdin.readline

def add(a, b):
    return a*b - 1

if __name__ == "__main__":
    a, b = map(int, input().strip().split())
    print(add(a, b))