# 백준 9012번 : 괄호
if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        paren = str(input())
        lst = list(paren)
        sum = 0

        for ch in lst:
            if ch == '(':
                sum += 1
            elif ch == ')':
                sum -= 1
            
            if sum < 0:
                print('NO')
                break

        if sum > 0:
            print('NO')
        elif sum == 0:
            print('YES')