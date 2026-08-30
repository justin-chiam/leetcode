class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        runningSum = nums[0]
        for n in nums[1:]:
            runningSum = max(n, runningSum + n)
            maxSum = max(maxSum, runningSum)
        return maxSum