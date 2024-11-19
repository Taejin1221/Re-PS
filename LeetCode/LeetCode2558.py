# LeetCode2558.py
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for _ in range(k):
            gifts.sort()
            maximum = gifts.pop()
            gifts.append(int(maximum ** 0.5))

        return sum(gifts)
