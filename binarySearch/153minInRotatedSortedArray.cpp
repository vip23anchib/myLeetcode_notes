// APPROACH 1: Brute force => o(n)
// linear search = not optimal


//APPROACH 2: 
//1. check which half is sorted 
//2. take min element from the sorted half and then eliminate the sorted half.
//3. compare the min with answer var and update 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high =nums.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[low]<=nums[mid]){ // check if left half sorted 
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{ //else right half sorted
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};
