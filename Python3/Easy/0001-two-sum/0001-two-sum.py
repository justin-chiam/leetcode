class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashTable = {}
        for i, num in enumerate(nums):
            needed = target - num
            if needed in hashTable:
                return [hashTable[needed], i]
            hashTable[num] = i
        
        return []