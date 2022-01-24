def solution(clothes):
    answer = 1
    dic = {}

    for _, ctype in clothes:
        if ctype in dic:
            dic[ctype] += 1
        else:
            dic[ctype] = 2

    for num in dic.values():
        answer *= num

    return answer - 1