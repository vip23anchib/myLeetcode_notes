// APPROACH 1: BRUTE : linear search => o(n)

//APPROACH 2:
// Normal Binary Search:
// Whole array sorted
// → Compare with mid
// → Discard half

// Rotated Binary Search:
// Whole array NOT sorted
// ↓

// 1. Find WHICH HALF is sorted.
// 2. Is target inside that sorted half?
//       YES → Search there.
//       NO  → Search the other half.

// Reason:
// A rotated sorted array has only ONE pivot,
// so one half is ALWAYS sorted.

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // ==========================================================
            // KEY IDEA:
            // A rotated sorted array has ONLY ONE breaking point.
            // Therefore, in every iteration,
            // AT LEAST ONE HALF is guaranteed to be sorted.
            //
            // Binary Search works only on sorted arrays.
            // So first identify the sorted half,
            // then check if target lies inside it.
            // ==========================================================

            // Check if LEFT half is sorted
            if (nums[low] <= nums[mid]) {

                // Since left half is sorted,
                // if target lies between low and mid,
                // search left.
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }

                // Otherwise target MUST be in right half.
                else {
                    low = mid + 1;
                }
            }

            // Otherwise RIGHT half is sorted.
            else {

                // If target lies inside sorted right half,
                // search right.
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }

                // Otherwise search left.
                else {
                    high = mid - 1;
                }
            }
        }

        // Target not present
        return -1;
    }
};
