# 백준 2480번 : 주사위 세개
if __name__ == "__main__":
    nums = input().split(" ")
    list = []

    for i in nums:
        list.append(int(i))

    list.sort()
    st = set(list)

    if len(st) == 1:
        print(10000 + list[0]*1000)
    elif len(st) == 2:
        print(1000 + list[1]*100)
    else:
        print(list[-1]*100)
    