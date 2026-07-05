//brute force
//checking if last 2 elements are same as current element and then removing

/*
Problem: Remove Duplicates from Sorted Array II

Goal:
- Keep each element AT MOST 2 times.
- Modify the array in-place.
- Return the new length (k).
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        for(int i=2;i<n;i++){
            if (nums[i-1]==nums[i] && nums[i-2]==nums[i]){
                nums.erase(nums.begin()+i);
                n--;
                i--;
            }
            else{
                continue;
            }
        }
        return nums.size();
    }
};


/*
Logic:

1. The first 2 elements are always valid because
   two duplicates are allowed.

2. Let k = index where the next valid element
   should be placed.

3. Traverse the array from index 2.

4. Compare current element with nums[k-2].

   Why k-2?

   - nums[0...k-1] already contains the valid answer.
   - nums[k-2] is the FIRST of the last two accepted elements.
   - If nums[i] == nums[k-2], then the last two accepted
     elements are already equal to nums[i].
     Adding another would make 3 copies.

5. If nums[i] != nums[k-2],
   place nums[i] at nums[k] and increment k.

----------------------------------------------------
Important Observation:

We never erase elements.
We only overwrite unwanted elements.

This avoids shifting the array and gives O(n) time.
----------------------------------------------------

Complexity:
Time  : O(n)
Space : O(1)

Pattern:
This is a Two Pointer problem.
Can be generalized:
- Keep at most 1 copy -> compare with previous.
- Keep at most 2 copies -> compare with k-2.
- Keep at most K copies -> compare with k-K.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if(n <= 2)
            return n;

        int k = 2;

        for(int i = 2; i < n; i++) {

            if(nums[i] != nums[k-2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

