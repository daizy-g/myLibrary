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
