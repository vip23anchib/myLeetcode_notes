// check if a number contains duplicates using hashing

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxVal = *max_element(nums.begin(), nums.end());

        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if (it.second>1){
                return true;
            }
        }
        return false;
        
    }
};