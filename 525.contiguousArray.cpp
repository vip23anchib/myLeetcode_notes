//Given a binary array nums, 
// return the maximum length of a contiguous subarray with an equal number of 0 and 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        int sum = 0, maxi = 0;

        firstIndex[0] = -1; 

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);

            if (firstIndex.count(sum)) {
                maxi = max(maxi, i - firstIndex[sum]);
            } else {
                firstIndex[sum] = i;
            }
        }
        return maxi;
    }
};

