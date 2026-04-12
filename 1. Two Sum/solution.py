class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n={}
        for i, num in enumerate(nums):
            if target-num in n:
                return [n[target-num],i]
            n[num] = i
        return []