# 백준 1541번 : 잃어버린 괄호
if __name__ == "__main__":
    expr = input().split('-')
    nums = []

    for e in expr:
        sum = 0
        tmp = e.split('+')
        for t in tmp:
            sum += int(t)
        nums.append(sum)

    ret = nums[0]

    for i in range(1, len(nums)):
        ret -= nums[i]

    print(ret)