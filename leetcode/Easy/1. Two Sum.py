from ast import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = {}
        
        for idx, num in enumerate(nums):
            diff = target - num
            
            if num in hashMap:
                return [idx, hashMap[num]]
            else:
                hashMap[diff] = idx