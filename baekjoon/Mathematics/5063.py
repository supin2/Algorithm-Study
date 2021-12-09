# 백준 5063번 : TGN
if __name__ == "__main__":
    N = int(input())

    for _ in range(N):
        r, e, c = map(int, input().split())
        gain = e - c
        
        if gain > r :
            print("advertise")
        elif gain == r :
            print("does not matter")
        else:
            print("do not advertise")