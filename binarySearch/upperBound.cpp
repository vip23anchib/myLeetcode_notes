// Returns index of first element > target.
// Returns nums.size() if no such element exists.
// Time: O(log n)

int upperBound(vector<int>& nums, int target) {

    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}


//STL UPPER BOUND

// Returns iterator to first element > target.
auto it = upper_bound(nums.begin(), nums.end(), target);

//GET INDEX:
int index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

//example 
vector<int> nums = {1,2,2,2,4,5};
int index = upper_bound(nums.begin(), nums.end(), 2) - nums.begin();
// index = 4
