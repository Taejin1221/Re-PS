# LeetCode0347.py
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        table = {}
        for n in nums:
            if n not in table:
                table[n] = 1
            else:
                table[n] += 1

        ans = sorted(table.items(), key=lambda x: x[1], reverse=True)

        return [a[0] for a in ans[:k]]
