/*

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

 */

class Solution {
    public int findShortestSubArray(int[] nums) {
        final int MAX_SIZE = 50000;
        int[][] hash = new int[MAX_SIZE][3];
        int length = nums.length, degree = 0, shortest = Integer.MAX_VALUE;

        for (int i = 0; i < length; ++i) {
            if (hash[nums[i]][0] == 0)
                hash[nums[i]][1] = i;
            hash[nums[i]][2] = i;
            ++hash[nums[i]][0];
        }

        for (int i = 0; i < MAX_SIZE; ++i) {
            if (hash[i][0] != 0 && degree <= hash[i][0]) {
                if (degree < hash[i][0]) {
                    shortest = hash[i][2] - hash[i][1] + 1;
                    degree = hash[i][0];
                } else {
                    shortest = Integer.min(shortest, hash[i][2] - hash[i][1] + 1);
                }
            }
        }
        return shortest;
    }
}
