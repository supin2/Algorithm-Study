import sys
input = sys.stdin.readline

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        text = input().strip()
        left, right = [], []
        
        for ch in text:
            if ch == '>':
                if right:
                    left.append(right.pop())
            elif ch == '<':
                if left:
                    right.append(left.pop())
            elif ch == '-':
                if left:
                    left.pop()
            else:
                left.append(ch)
                
        print(''.join(left) + ''.join(reversed(right)))