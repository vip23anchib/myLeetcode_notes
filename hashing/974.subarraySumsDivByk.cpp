//Given an integer array nums and an integer k,
//  return the number of non-empty subarrays that have a sum divisible by k.

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp; // remainder -> frequency
        
        mp[0] = 1; // empty prefix
        
        int sum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            sum += nums[i];
            
            int rem = sum % k;
            
            // make remainder positive
            if (rem < 0) rem += k;
            
            // if seen before
            if (mp.count(rem)) {
                count += mp[rem];
            }
            
            // increase frequency
            mp[rem]++;
        }
        
        return count;
    }
};
