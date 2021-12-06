# 백준 2530번 : 인공지능 시계

def calc(HH, MM, SS, T) :
    SS += T % 60
    T = T // 60
    if SS >= 60:
        SS -= 60
        MM += 1

    MM += T % 60
    T = T // 60
    if MM >= 60:
        MM -= 60
        HH += 1

    HH += T % 24
    if HH >= 24:
        HH -= 24

    print(HH, MM, SS)


if __name__ == "__main__" :
    HH, MM, SS = map(int, input().split())
    time = int(input())
    calc(HH, MM, SS, time)

