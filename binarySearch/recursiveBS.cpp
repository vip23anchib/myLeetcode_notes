// Recursive Binary Search.
// Returns index of target if found, else -1.
// Time: O(log n), Space: O(log n) due to recursion stack.

int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;

    if (nums[mid] > target)
        return binarySearch(nums, low, mid - 1, target);

    return binarySearch(nums, mid + 1, high, target);
}
