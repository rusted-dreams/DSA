from typing import List

class Solution:
    def minimumTime(self, mountainHeight: int, workerTimes: List[int]) -> int:
        def can_reduce_height(time: int) -> bool:
            total_reduction = 0
            for worker_time in workerTimes:
                # Calculate the maximum height this worker can reduce in the given time
                reduction = 0
                current_time = 0
                for i in range(1, mountainHeight + 1):
                    current_time += worker_time * i
                    if current_time > time:
                        break
                    reduction = i
                total_reduction += reduction
                if total_reduction >= mountainHeight:
                    return True
            return False

        # Binary search to find the minimum time
        left, right = 1, min(workerTimes) * mountainHeight * (mountainHeight + 1) // 2
        while left < right:
            mid = (left + right) // 2
            if can_reduce_height(mid):
                right = mid
            else:
                left = mid + 1
        
        return left

# Test cases
solution = Solution()

# Example 1
print(solution.minimumTime(4, [2, 1, 1]))  # Output: 3

# Example 2
print(solution.minimumTime(10, [3, 2, 2, 4]))  # Output: 12

# Example 3
print(solution.minimumTime(5, [1]))  # Output: 15