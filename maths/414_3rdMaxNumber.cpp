#include <vector>
#include <climits>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        // We use LLONG_MIN because the array values can go as low as INT_MIN.
        // This ensures our initial values are always smaller than any number in nums.
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;
        
        for (int n : nums) {
            // Rule 1: Ignore duplicates. We only care about distinct numbers.
            if (n == max1 || n == max2 || n == max3) {
                continue;
            }
            
            // Rule 2: Cascade the rankings down if a larger number is found.
            if (n > max1) {
                max3 = max2; // Old 2nd place becomes 3rd
                max2 = max1; // Old 1st place becomes 2nd
                max1 = n;    // n becomes the new 1st
            } 
            else if (n > max2) {
                max3 = max2; // Old 2nd place becomes 3rd
                max2 = n;    // n becomes the new 2nd
            } 
            else if (n > max3) {
                max3 = n;    // n becomes the new 3rd
            }
        }
        
        // Rule 3: If max3 was never touched, we don't have 3 distinct maximums.
        // The problem states we must return the top maximum (max1) in this case.
        if (max3 == LLONG_MIN) {
            return max1;
        }
        
        return max3;
    }
};
