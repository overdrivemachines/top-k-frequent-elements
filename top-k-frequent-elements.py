from typing import List
from collections import defaultdict


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        result = []

        freq = defaultdict(lambda: 0)

        for num in nums:
            freq[num] += 1

        print(freq)

        minimum_freq = sorted(freq.values(), reverse=True)[k - 1]

        for key, value in freq.items():
            if value >= minimum_freq:
                result.append(key)
        return result


s = Solution()
nums = [1, 1, 1, 2, 2, 3]
k = 2
result = s.topKFrequent(nums, k)
print(result)
