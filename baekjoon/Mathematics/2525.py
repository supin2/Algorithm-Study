# 백준 2525번 : 오븐 시계
def calc(HH, MM, T):
    HH += T // 60
    MM += T % 60

    if MM >= 60 :
        HH += 1
        MM -= 60
    if HH >= 24 :
        HH -= 24
    
    print('%d %d' % (HH, MM))

if __name__ == "__main__":
    HH, MM = map(int, input().split())
    time = int(input())
    calc(HH, MM, time)