def solution(answers):
    answer = [0, 0, 0]
    lst1 = [1, 2, 3, 4, 5]
    lst2 = [2, 1, 2, 3, 2, 4, 2, 5]
    lst3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    for idx, ans in enumerate(answers):
        if ans == lst1[idx % len(lst1)]:
            answer[0] += 1
        if ans == lst2[idx % len(lst2)]:
            answer[1] += 1
        if ans == lst3[idx % len(lst3)]:
            answer[2] += 1
            
    ret = []
    for idx, score in enumerate(answer):
        if score == max(answer):
            ret.append(idx + 1)

    return ret