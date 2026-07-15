//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.

//APPROACH 1:
//Iterate through the array with linear search and find
// but TC= o(n)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i]==target){
                first=i;
                last=i;
                break;
            }
        }
        if(first!=-1){
            for(int i=first+1;i<n;i++){
               if(nums[i]==target){
                last=i;
               } 
            }
        }
        return {first, last};
        
    }
};

// -----------------------------------------------------------------------------------------------------------------------
// APPROACH 2: use lower_bound to find first occurence if it exists (check) and then find last occurence by looping (if it exists)
// T.C. = o(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first=-1;
        int last=-1;
        first=lower_bound(nums.begin(),nums.end(),target) - nums.begin();
       
        if (first == nums.size() || nums[first] != target){ // check if first exists or not else return {-1,-1}
            return {-1, -1};
        }
        if (first != -1){
            for(int i=first+1;i<nums.size();i++){
                if (nums[i]== target){
                    last=i;
                }
            }
        }
        return {first , last};
    }
};


// -----------------------------------------------------------------------------------------------------------------------
// APPROACH 3: find first and last using (lower_bound , upper_bound -1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // Target doesn't exist
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return {first, last};
    }
};



// -----------------------------------------------------------------------------------------------------------------------
// APPROACH 3: find first and last using (lower_bound , upper_bound -1)
class Solution {
public:

    int findFirst(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;          // Possible answer
                high = mid - 1;     // Search left for first occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;          // Possible answer
                low = mid + 1;      // Search right for last occurence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findFirst(nums, target);

        if (first == -1)
            return {-1, -1};

        int last = findLast(nums, target);

        return {first, last};
    }
};
