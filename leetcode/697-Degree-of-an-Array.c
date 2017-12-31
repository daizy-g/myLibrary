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

struct count {
    int s;
    int e;
    int v;
};

int findShortestSubArray(int* nums, int numsSize) {
    int i;
    int max = 0;
    int len = numsSize;
    struct count cnt[50000];
    for (i = 0; i < 50000; i++) {
        cnt[i].v = 0;
        cnt[i].s = cnt[i].e = -1;
    }

    for (i = 0; i < numsSize; i++) {
        int t = nums[i];
        if (cnt[t].v == 0)
            cnt[t].s = i;
        cnt[t].e = i;
        cnt[t].v++;

        if (cnt[t].v > max)
            max = cnt[t].v;
    }

    for (i = 0; i < 50000; i++) {
        if (cnt[i].v == max) {
            if (len > (cnt[i].e - cnt[i].s + 1))
                len = cnt[i].e - cnt[i].s + 1;
        }
    }
    return len;
}
