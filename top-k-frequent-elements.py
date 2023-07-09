from typing import List
from collections import defaultdict


class Solution:
    def topKFrequent1(self, nums: List[int], k: int) -> List[int]:
        result = []

        freq = defaultdict(lambda: 0)

        for num in nums:
            freq[num] += 1

        minimum_freq = sorted(freq.values(), reverse=True)[k - 1]

        for key, value in freq.items():
            if value >= minimum_freq:
                result.append(key)
        return result

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        result = []
        my_list = [[] for _ in range(len(nums) + 1)]
        freq = defaultdict(lambda: 0)

        for num in nums:
            freq[num] += 1

        for key, value in freq.items():
            my_list[value].append(key)

        i = len(my_list) - 1
        while i >= 0:
            if len(my_list[i]) > 0:
                result.extend(my_list[i])
            if len(result) >= k:
                if len(result) > k:
                    del result[k - len(result) :]
                return result
            i -= 1
        return result


s = Solution()
nums = [1, 1, 1, 2, 2, 3]
k = 2
result = s.topKFrequent(nums, k)
print(result)
