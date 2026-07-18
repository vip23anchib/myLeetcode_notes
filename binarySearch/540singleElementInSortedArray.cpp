/*
=========================================================
PROBLEM : Single Element in a Sorted Array
=========================================================

Observation
-----------
- Array is sorted.
- Every element appears exactly twice.
- Only one element appears once.
Example:
1 1 2 3 3 4 4 8 8
Answer = 2

---------------------------------------------------------
BRUTE FORCE
---------------------------------------------------------

Approach 1 : Linear Scan
Since duplicates are adjacent in a sorted array,
check every element with its neighbours.
Steps
-----
1. Handle first element.
2. Handle last element.
3. Traverse from index 1 to n-2.
4. If current element != left && != right,
   then it is the answer.
Time  : O(N)
Space : O(1)

---------------------------------------------------------
BETTER (XOR)
---------------------------------------------------------

Take XOR of every element.
Reason:
x ^ x = 0
0 ^ x = x

Every duplicate cancels itself.
Only single element remains.
Time  : O(N)
Space : O(1)
Works even if array is NOT sorted.

---------------------------------------------------------
OPTIMAL (Binary Search)
---------------------------------------------------------

Core Observation
----------------

Before the single element:

Pairs start at EVEN indices.

Index:
0 1 2 3 4 5 6 7

Array:
1 1 2 2 3 3 4

Pair starts:
0
2
4

-----------------------------------

After the single element:

Everything shifts by one.
Pairs now start at ODD indices.

Index:
0 1 2 3 4 5 6 7 8

Array:
1 1 2 3 3 4 4 5 5

Pair starts:
3
5
7

So...

LEFT SIDE
---------
even index == first of pair
odd index == second of pair

RIGHT SIDE
----------
odd index == first of pair
even index == second of pair

This change tells us which side contains the answer.
---------------------------------------------------------
HOW TO THINK
---------------------------------------------------------

Step 1
-------
Notice array is SORTED.

Whenever problem says
"sorted + minimum/maximum/first/last/single"
always think:
Can Binary Search be used?

---------------------------------------------------------

Step 2
-------
Ask:

What property changes after the answer?

Here,
pair alignment changes.

Before answer:
(Even, Odd)

After answer:
(Odd, Even)

That means answer is exactly where this pattern breaks.

---------------------------------------------------------

Step 3
-------
At every mid,
check whether mid follows the correct pairing pattern.

If pattern is correct,
single element must be on the RIGHT.

If pattern is broken,
single element lies on the LEFT.

Thus eliminate half every iteration.

---------------------------------------------------------
Why these conditions?
---------------------------------------------------------

if ((mid%2==1 && nums[mid-1]==nums[mid]) ||
    (mid%2==0 && nums[mid]==nums[mid+1]))

Meaning:

Case 1
-------
mid is ODD

Expected:
second element of pair

So compare with left.

If equal,
pattern is still correct.

Move RIGHT.

-----------------------------------

Case 2
-------
mid is EVEN

Expected:
first element of pair

So compare with right.

If equal,
pattern is still correct.

Move RIGHT.

-----------------------------------

Otherwise,
pair alignment is broken.

Single element is on LEFT.

Move LEFT.

---------------------------------------------------------
Finding the answer
---------------------------------------------------------

If

nums[mid] != nums[mid-1]
AND
nums[mid] != nums[mid+1]

then mid itself is the unique element.

---------------------------------------------------------
Boundary Cases
---------------------------------------------------------

1. Array size = 1

2. First element is unique

3. Last element is unique

Handle these before binary search,
so we can safely check
mid-1 and mid+1.

---------------------------------------------------------
Complexity
---------------------------------------------------------

Brute:
Time  : O(N)
Space : O(1)

Optimal:
Time  : O(log N)
Space : O(1)

---------------------------------------------------------
INTERVIEW TRICK
---------------------------------------------------------

Whenever you see:

✔ Sorted array
✔ Duplicate pairs
✔ One special element

Ask yourself:

"Does something change before and after the answer?"

If YES,
that changing property becomes your Binary Search condition.

Binary Search is NOT about searching values.

Binary Search is about searching where a PROPERTY changes.
=========================================================
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }
        else if (nums[0]!=nums[1]){
            return nums[0];
        }
        else if (nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int low=1;
        int high=n-2;

        while(low<=high){
            int mid=(low+high)/2;

            if (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) {
                return nums[mid];
            }

            if ((mid %2==1 && nums[mid-1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    return -1;
    }


