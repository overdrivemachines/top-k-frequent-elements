# 347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


5 occurs 45 times
umap[5] = 45 *
umap[2] = 10
umap[9] = 44
umap[1] = 50 *
umap[3] = 1
umap[12] = 32
umap[7] = 90 *
umap[-1] = 51 *


top 4

result[0] = 5 | 45      lowest_index = 0 lowest_value = 45
result[1] = 2 | 10 **
result[2] = 9 | 44
result[3] = 1 | 50


can be evicted: result[1]
