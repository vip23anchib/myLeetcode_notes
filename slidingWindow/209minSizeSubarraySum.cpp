// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or 
// equal to target. If there is no such subarray, return 0 instead.

// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.


// APPROACH 1 : Brute Force Approach 
// high time complexity => TLE
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();
        int curr_index=-1;
        int index=INT_MAX;
        for (int i=0;i<n;i++){
            int sum=0;
           
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    index=min(index,j-i+1);
                    break;
                }
            }
        }

    if ( index==INT_MAX){
        return 0;
    }
    return index;

    }
};


// OPTIMAL : SLIDING WINDOW 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();

        int left=0;
        int sum=0;
        int ans=INT_MAX;
        
        for(int right=0;right<n;right++){
            sum+=nums[right];

            while(sum>=target){
                ans=min(ans,right-left+1);

                sum-=nums[left];
                left++;
            }

        }
        return ans == INT_MAX ? 0 : ans;
        
    }
};
