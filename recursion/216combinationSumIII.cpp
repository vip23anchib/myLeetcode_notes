class Solution {
public:

    void solve(int start, int k, int target,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        // We have selected exactly k numbers.
        if(ds.size() == k) {

            // Valid only if their sum is exactly n.
            if(target == 0) {
                ans.push_back(ds);
            }

            return;
        }

        // Try numbers from start to 9.
        for(int i = start; i <= 9; i++) {

            // No point choosing a number larger than
            // the remaining target.
            if(i > target)
                break;

            // Choose i.
            ds.push_back(i);

            // i + 1 because each number can be used
            // only once.
            solve(i + 1,
                  k,
                  target - i,
                  ds,
                  ans);

            // Undo the choice.
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, k, n, ds, ans);

        return ans;
    }
};
