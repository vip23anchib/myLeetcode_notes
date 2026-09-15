// ============================================================
// LEETCODE 55 - JUMP GAME
// ============================================================
//
// Problem:
// Given nums[i], it tells us the maximum number of steps
// we can jump forward from index i.
//
// Goal:
// Check whether we can reach the LAST index.
//
// ------------------------------------------------------------
// GREEDY IDEA
// ------------------------------------------------------------
//
// We don't need to actually make every possible jump.
//
// Instead, keep track of the FARTHEST INDEX we can currently
// reach.
//
// maxInd = maximum index reachable so far.
//
// At every index i:
//
//     maxInd = max(maxInd, i + nums[i])
//
// i + nums[i] = farthest index we can reach from i.
//
// ------------------------------------------------------------
// IMPORTANT CHECK
// ------------------------------------------------------------
//
// if(i > maxInd)
//
// This means:
//     The current index i is beyond our maximum reachable
//     position.
//
// Therefore, we can never reach i or anything after it.
//
// So return false.
//
// ------------------------------------------------------------
// WHY IS THIS GREEDY?
// ------------------------------------------------------------
//
// At every index, we only care about:
//
//     "What is the farthest position I can reach?"
//
// We don't care which exact jump got us there.
//
// We always keep the BEST/FARTHEST reachable position.
//
// ------------------------------------------------------------
// EXAMPLE
//
// nums = [2,3,1,1,4]
//
// i = 0:
//     maxInd = max(0, 0 + 2) = 2
//
// i = 1:
//     maxInd = max(2, 1 + 3) = 4
//
// We can reach index 4 → last index.
// Answer = true.
//
// ------------------------------------------------------------

class Solution {
public:
    bool canJump(vector<int>& nums) {

        // Farthest index that we can reach so far.
        int maxInd = 0;

        for(int i = 0; i < nums.size(); i++) {

            // If current index is beyond our reachable range,
            // there is no way to reach this index.
            if(i > maxInd) {
                return false;
            }

            // Update the farthest index we can reach.
            //
            // i + nums[i] = farthest position reachable
            // from the current index.
            maxInd = max(maxInd, i + nums[i]);
        }

        // If we never got stuck, the last index is reachable.
        return true;
    }
};


// ============================================================
// QUICK GLANCE
// ============================================================
//
// maxInd = farthest index reachable so far
//
// For every i:
//
//     if(i > maxInd)
//         return false;
//
//     maxInd = max(maxInd, i + nums[i]);
//
// If loop finishes:
//     return true;
//
// Time Complexity:  O(n)
// Space Complexity: O(1)
//
// KEY IDEA:
// "Keep extending the farthest reachable position."
// ============================================================
