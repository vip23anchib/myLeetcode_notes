// To find the factors of a number:
// The Concept (How it works)
// 1. Start with the smallest prime number, 2. Divide the number by 2 as long as it's even, 
//    and record each 2. 
// 2. Move to odd numbers. Once the number is odd, check if it can be divided by 3, 5, 7, etc.
// 3. The Square Root Optimization: You only ever need to check factors up to the square root ($\sqrt{n}$) of the number.
//    If a number has no factors left below its square root, whatever is left of the number must be a prime itself.

#include <iostream>
#include <cmath>

void printPrimeFactors(int n) {
    // Step 1: Handle the factor 2 explicitly to make n odd
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n /= 2;
    }

    // Step 2: n must be odd at this point. 
    // We can skip even numbers and loop through odd numbers up to sqrt(n)
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
    }

    // Step 3: If n is still greater than 2, the remaining n must be prime
    if (n > 2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    int num = 315;
    std::cout << "Prime factors of " << num << " are: ";
    printPrimeFactors(num); // Output: 3 3 5 7
    return 0;
}




// Function to find the UGLY NUMBERS:

// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.
  
// Example 1:
// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3

class Solution {
public:
    bool isUgly(int n) {

        if (n <= 0)
            return false;

        while (n % 2 == 0)
            n /= 2;

        while (n % 3 == 0)
            n /= 3;

        while (n % 5 == 0)
            n /= 5;

        return n == 1;
    }
};
