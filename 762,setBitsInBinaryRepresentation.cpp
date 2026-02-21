class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        // Possible primes for set bits (<= 20)
        unordered_set<int> primes = {
            2, 3, 5, 7, 11, 13, 17, 19
        };
        
        int count = 0;
        
        for (int i = left; i <= right; i++) {
            
            // Count set bits
            int bits = __builtin_popcount(i);
            
            // Check if prime
            if (primes.count(bits)) {
                count++;
            }
        }
        
        return count;
    }
};