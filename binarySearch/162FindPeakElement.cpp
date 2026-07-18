/*
---------------------------------------------------------
APPROACH 1 : BRUTE FORCE (LINEAR SEARCH)
---------------------------------------------------------
INTUITION:
A peak element is an element greater than both of its neighbours.

So, simply check every element.
The first and last elements are special cases because
they have only one neighbour.

---------------------------------------------------------
HOW TO THINK

When no better observation comes to mind,
always start with the most natural approach.

Ask yourself:
"Can I check every element once and verify whether
it is a peak?"
Yes.
So,
1. Handle edge cases.
2. Traverse the array.
3. Return the first valid peak.

This immediately gives an O(n) solution.
---------------------------------------------------------
ALGORITHM

1. If only one element exists -> return index 0.
2. Check first element.
3. Check last element.
4. Traverse from index 1 to n-2.
5. If nums[i] > nums[i-1] && nums[i] > nums[i+1],
   return i.
---------------------------------------------------------
TIME  : O(n)
SPACE : O(1)
---------------------------------------------------------
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        // Only one element
        if(n == 1)
            return 0;

        // Check first element
        if(nums[0] > nums[1])
            return 0;

        // Check last element
        if(nums[n-1] > nums[n-2])
            return n-1;

        // Check middle elements
        for(int i = 1; i < n-1; i++){

            if(nums[i] > nums[i-1] &&
               nums[i] > nums[i+1])
                return i;
        }

        return -1;
    }
};



/*
---------------------------------------------------------
APPROACH 2 : BINARY SEARCH (OPTIMAL)
---------------------------------------------------------

INTUITION

The problem asks for O(log n),
which is a strong hint towards Binary Search.

The array is NOT sorted,
so ask yourself:

"What property helps me eliminate half of the array?"

Instead of searching for the peak directly,
observe the "slope".

Compare:
        nums[mid]
             |
             v
        nums[mid+1]

---------------------------------------------------------
HOW TO THINK

Binary Search is NOT about finding the answer directly.
It is about asking:
"Which half can I safely discard?"

---------------------------------------------------------

CASE 1
nums[mid] < nums[mid+1]
Meaning:
We are on an increasing slope (↗).

Example:
1 2 3 4 5

If the array keeps increasing,
the last element becomes the peak.

If it starts decreasing later,
1 2 3 4 5 4 2
then 5 becomes the peak.
So,
a peak is GUARANTEED to exist on the RIGHT.

Discard LEFT.

low = mid + 1;

---------------------------------------------------------

CASE 2

nums[mid] > nums[mid+1]
Meaning:
We are on a decreasing slope (↘).
Example:
7 6 5 4
The peak already lies on the LEFT.
Also, mid itself can be the peak.
Therefore,
Discard RIGHT.
high = mid;
(NOT high = mid-1 because mid might be the answer.)

---------------------------------------------------------

WHY while(low < high) ?
When low == high,
only ONE candidate remains.
That candidate is guaranteed to be a peak.
So there is no need to continue searching.

---------------------------------------------------------

ALGORITHM
1. Find mid.
2. Compare nums[mid] with nums[mid+1].
3. If increasing -> move right.
4. If decreasing -> move left.
5. Repeat until low == high.

---------------------------------------------------------

TRICK TO REMEMBER
Don't ask:
"Where is the peak?"
Ask:
"Which side definitely contains a peak?"
The slope tells you the answer.

---------------------------------------------------------

TIME  : O(log n)
SPACE : O(1)
---------------------------------------------------------
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if (nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int low=1;
        int high=n-1;

        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
    return low;  
    }
};
