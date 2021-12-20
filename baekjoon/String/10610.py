# 백준 10610번 : 30
if __name__ == "__main__":
    N = list(input())
    N.sort(reverse=True)

    sum = 0
    for num in N:
        sum += int(num)
    
    if sum % 3 != 0 or '0' not in N:
        print(-1)
    else:
        print(''.join(N))
