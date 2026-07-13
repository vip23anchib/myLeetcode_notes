// Finds the index of target in a sorted array.
// Returns -1 if target is not found.
// Time: O(log n), Space: O(1)

int binarySearch(vector<int>& nums, int target) {

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
