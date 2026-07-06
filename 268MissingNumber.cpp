// Brute Force Approach
// 1. Check every number from 0 to n.
// 2. Use find() to search if the number exists in the array.
// 3. The first number not found is the missing number.
//
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size()+1;
        
        for (int i=0;i<n;i++){
           if (find(nums.begin(), nums.end(), i) != nums.end()) {
                continue;
            }
            else{
                return i;
            }
        }
        return 0;
    }
};


//OR

// Sum Formula Approach
// 1. Calculate the expected sum of numbers from 0 to n using n*(n+1)/2.
// 2. Calculate the actual sum of all elements in the array.
// 3. Missing Number = Expected Sum - Actual Sum.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
