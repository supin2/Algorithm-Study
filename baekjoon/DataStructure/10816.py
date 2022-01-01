# 백준 10816번 : 숫자 카드 2
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    nums = list(map(int, input().split(' ')))
    M = int(input())
    find = list(map(int, input().split(' ')))

    dic = {}

    for num in nums:
        if num in dic:
            dic[num] += 1
        else:
            dic[num] = 1
    
    print(' '.join(str(dic[ret]) if ret in dic else '0' for ret in find))