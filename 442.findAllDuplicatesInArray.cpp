/*
Problem: Find All Duplicates in an Array
Observation:
- Numbers are in the range [1, n].
- Values can be mapped directly to indices.
    value 1 -> index 0
    value 2 -> index 1
    value x -> index (x-1)
------------------------------------------------

Main Trick:
Use the input array itself as a "visited" array.
No extra space is needed.
Positive -> Number not seen before.
Negative -> Number already seen.

------------------------------------------------
Logic:

For every number:
1. Get its corresponding index:
      index = abs(nums[i]) - 1

   Why abs()?
   Previous iterations may have made numbers negative.
   We need the original value.

2. Go to that index.

3. If nums[index] is positive:
      -> First time seeing this number.
      -> Mark it visited by making it negative.

4. If nums[index] is already negative:
      -> We've already visited this number.
      -> Current number is a duplicate.
      -> Add it to the answer.

------------------------------------------------
Think of it like mailboxes:
Index 0 = mailbox for number 1
Index 1 = mailbox for number 2
Index 2 = mailbox for number 3
...

We don't care about the value stored there.
We ONLY use its sign:
Positive = mailbox never visited.
Negative = mailbox already visited.

------------------------------------------------

Example:
nums = [4,3,2,7,8,2,3,1]

See 4
-> Go to mailbox 4 (index 3)
-> Positive
-> Make negative

See another 2
-> Go to mailbox 2 (index 1)
-> Already negative
-> Therefore 2 is a duplicate.

------------------------------------------------

Complexity:

Time  : O(n)
Space : O(1) (excluding output vector)

Pattern:
Whenever a problem says:
- Values are from 1 to n
- O(1) extra space

Think:
"Can I use the array itself as a visited array?"
*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans;
        int index=0;
        
        for(int i=0;i<n;i++){
            index=abs(nums[i])-1;
            if (nums[index]<0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[index]=-nums[index];
            }
            
        }
        return ans;
    }
};
