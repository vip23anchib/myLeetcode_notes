//This solution uses prefix sums and a hash map to store previous sums.
//For each position, it checks if (prefixSum − k) exists, and counts valid subarrays in O(N) time.

/*
🔹 Why This Works with Negative Numbers?
Sliding window ❌ fails with negatives.
Prefix sum + map ✅ works always.
That’s why LeetCode wants this approach.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;  

        int prefixSum = 0;
        int count = 0;

        for (int x : nums) {
            prefixSum += x;

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count
    }
};