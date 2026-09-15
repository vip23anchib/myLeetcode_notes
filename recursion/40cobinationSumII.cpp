
// ============================================================
// COMBINATION SUM II — LEETCODE 40
// ============================================================
//
// Given an array that may contain duplicates, find all unique
// combinations whose sum = target.
//
// RULES:
// 1. Each element/index can be used AT MOST ONCE.
// 2. The input can contain duplicate numbers.
// 3. Answer must NOT contain duplicate combinations.
//
// Example:
// candidates = [1,2,2,5], target = 5
// Answer = [[1,2,2], [5]]
//
// ------------------------------------------------------------
// APPROACH 1: LOOP-BASED BACKTRACKING
// ------------------------------------------------------------
//
// Main idea:
//
// At every recursion level, try every possible element
// starting from 'index'.
//
// i = the element we are currently trying.
// index = where this recursion level is allowed to start.
//
// After choosing candidates[i], call:
//
// solve(i + 1, ...)
//
// because the same INDEX cannot be reused.
//
// IMPORTANT DUPLICATE CONDITION:
//
// if(i > index && candidates[i] == candidates[i-1])
//     continue;
//
// This means:
//
// "At the SAME recursion level, if we already tried this
// value, don't start another branch with the same value."
//
// But duplicates CAN still be selected at a DEEPER level.
//
// Example: [2,2]
//
// At the first level:
//     choose first 2
//         ↓
//     go to next level
//         ↓
//     choose second 2
//
// This gives [2,2], which is valid.
//
// So:
//
// SAME LEVEL + same value  → SKIP
// DEEPER LEVEL + same value → ALLOW
//
// ------------------------------------------------------------

class Solution {
public:

    void solve(int index,
               int target,
               vector<int>& candidates,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        // If target becomes 0, we found a valid combination.
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        // Try every possible element from this level onwards.
        for(int i = index; i < candidates.size(); i++) {

            // Since the array is sorted, all later elements
            // will also be too large.
            if(candidates[i] > target)
                break;

            // Skip duplicate values at the SAME recursion level.
            //
            // i > index means:
            // We are not looking at the first choice of this level.
            //
            // If the previous element has the same value,
            // we already created a branch with this value.
            if(i > index && candidates[i] == candidates[i-1])
                continue;

            // Choose current element.
            ds.push_back(candidates[i]);

            // i + 1 means:
            // Move to the next INDEX because each element
            // can be used only once.
            solve(i + 1,
                  target - candidates[i],
                  candidates,
                  ds,
                  ans);

            // Backtrack:
            // Remove the element so we can try another choice.
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        // Sorting is important because:
        // 1. It puts duplicates together.
        // 2. It allows the duplicate-skip condition.
        // 3. It allows us to break when candidates[i] > target.
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, target, candidates, ds, ans);

        return ans;
    }
};


// ============================================================
// APPROACH 2: TAKE / DON'T TAKE RECURSION
// ============================================================
//
// At every index we have TWO choices:
//
// 1. TAKE candidates[ind]
// 2. DON'T TAKE candidates[ind]
//
// Since Combination Sum II does NOT allow reusing an index:
//
// TAKE:
//     solve(ind + 1, ...)
//
// DON'T TAKE:
//     We don't simply do ind + 1.
//
//     Why?
//
//     Suppose:
//         [1,2,2,2,5]
//
//     If we DON'T TAKE the first 2, then starting another
//     branch by not taking the first 2 and taking the second 2
//     would produce the same combination as taking the first 2.
//
//     Therefore, when we DON'T TAKE a number, we skip ALL
//     consecutive duplicates of that number.
//
// Example:
//
//     1  2  2  2  5
//        ↑
//        current
//
// DON'T TAKE current 2:
//
//     skip 2
//     skip 2
//     skip 2
//        ↓
//        5
//
// This prevents duplicate combinations.
//
// IMPORTANT:
//
// TAKE only moves ONE index:
//
//     solve(ind + 1, ...)
//
// This is necessary because we may still want to choose
// another copy of the same value.
//
// Example:
//
//     [2,2], target = 4
//
//     TAKE first 2
//          ↓
//     ind + 1
//          ↓
//     TAKE second 2
//          ↓
//     [2,2]
//
// So:
//
// TAKE       → move one index forward
// DON'T TAKE → skip all duplicates
//
// ------------------------------------------------------------

class Solution {
public:

    void solve(int ind,
               int target,
               vector<int>& arr,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        // We have processed every element.
        if(ind == arr.size()) {

            // If target is exactly 0, this is a valid combination.
            if(target == 0)
                ans.push_back(ds);

            return;
        }


        // ----------------------------------------------------
        // TAKE
        // ----------------------------------------------------
        //
        // We can take the current element if it does not
        // make the target negative.

        if(arr[ind] <= target) {

            ds.push_back(arr[ind]);

            // Move to ind + 1 because the SAME INDEX
            // cannot be used again.
            //
            // Notice:
            // We move only ONE position.
            //
            // This allows another duplicate value at the
            // next index to still be selected.

            solve(ind + 1,
                  target - arr[ind],
                  arr,
                  ds,
                  ans);

            // Backtrack after returning from recursion.
            ds.pop_back();
        }


        // ----------------------------------------------------
        // DON'T TAKE
        // ----------------------------------------------------
        //
        // We don't want another branch starting with the
        // same value at this recursion level.
        //
        // So skip all consecutive duplicates.

        int next = ind + 1;

        while(next < arr.size() &&
              arr[next] == arr[ind]) {

            next++;
        }

        // Continue from the first DIFFERENT value.
        //
        // This removes duplicate combinations that would
        // otherwise be generated by choosing identical values
        // from different indices.

        solve(next,
              target,
              arr,
              ds,
              ans);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        // Sorting puts duplicate values next to each other,
        // which allows us to skip them easily.
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, target, candidates, ds, ans);

        return ans;
    }
};


// ============================================================
// QUICK COMPARISON
// ============================================================
//
// LOOP-BASED:
//
//     for(i = index; i < n; i++)
//
//     TAKE:
//         solve(i + 1, ...)
//
//     DUPLICATES:
//         if(i > index && arr[i] == arr[i-1])
//             continue;
//
//     Easier and more commonly used for Combination Sum II.
//
//
// TAKE / DON'T TAKE:
//
//     TAKE:
//         solve(ind + 1, ...)
//
//     DON'T TAKE:
//         skip all duplicate values
//         solve(next, ...)
//
//     This is possible, but duplicate handling is less intuitive.
//
//
// ------------------------------------------------------------
// MOST IMPORTANT CONCEPT
// ------------------------------------------------------------
//
// "ind + 1" prevents REUSING THE SAME INDEX.
//
// It does NOT prevent using another index containing
// the SAME VALUE.
//
// Example:
//
//     index 1 → 2
//     index 2 → 2
//
// These are different indices.
//
// Therefore:
//
//     No same index again       → prevents reuse
//     Skip same value at level  → prevents duplicate answers
//
// ============================================================
```
