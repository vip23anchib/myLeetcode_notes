// Question : The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

// Example 1:
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

//APPROACH :

/**
 * ============================================================================
 * BIT-FLIPPING IN C++
 * ============================================================================
 * * THE GOAL: 
 * Flip the bits of a number (e.g., 5 -> Binary "101" should become "010" -> 2).
 *
 * ----------------------------------------------------------------------------
 * 1. WHY WE CANNOT USE THE BLIND BITWISE NOT (~)
 * ----------------------------------------------------------------------------
 * How it works: 
 * ~ is an automated operator that blindly inverts ALL 32 bits in memory as all
     integer numbers are stored as 32 bits in memory.
 *
 * The Problem:
 * For the number 5, the computer sees 29 leading zeros:
 * Input (5):   00000000 00000000 00000000 00000101
 * Using (~):   11111111 11111111 11111111 11111010
 * * Result: 
 * It flips the invisible leading zeros, turning a small positive number into 
 * a massive negative/garbage number. It cannot isolate just the active bits.
 *
 * ----------------------------------------------------------------------------
 * 2. THE SOLUTION: WHY WE USE BITWISE XOR (^) AND A MASK
 * ----------------------------------------------------------------------------
 * The XOR Rule:
 * - Any bit XORed with 0 stays the SAME (bit ^ 0 = bit) -> Protects zeros!
 * - Any bit XORed with 1 gets FLIPPED  (bit ^ 1 = !bit) -> Flips our target!
 *
 * What is a Mask?
 * A custom binary number we build that matches the exact length of our number 
 * but contains all 1s (e.g., for "101" (5), the mask is "111" (7)).
 *
 * How it executes across 32 bits:
 * Num (5):     00000000 00000000 00000000 00000101
 * Mask (7):    00000000 00000000 00000000 00000111
 * └───────── XOR with 0 ────┘ └─ XOR 1 ┘
 * Leaves these alone       Flips these
 * --------------------------------------------------
 * Result (2):  00000000 00000000 00000000 00000010
 * ============================================================================
 */

#include <iostream>
#include <bitset>

// APPROACH 1: Using std::bitset (Fastest to write/visualize)
int flipWithBitset(int num) {
    // We must declare a size (e.g., 32 bits)
    std::bitset<32> b(num);
    
    // Step through and flip only up to the highest active bit
    int temp = num;
    int index = 0;
    while (temp > 0) {
        b.flip(index); // .flip() manually toggles 0 to 1 and vice versa
        index++;
        temp >>= 1;
    }
    return static_cast<int>(b.to_ulong());
}

// APPROACH 2: Pure Integer Bitwise XOR (Most efficient / No extra memory)
int flipWithXOR(int num) {
    if (num == 0) return 1; // Edge case for 0
    
    int temp = num;
    int mask = 0;
    
    // Build the mask of 1s to match the exact bit-length of num
    while (temp > 0) {
        mask = (mask << 1) | 1; // Shifts mask left and pushes a '1' to the end
        temp >>= 1;             // Shift num right to check the next bit
    }
    
    // XOR the number with the mask to execute the targeted flip
    return num ^ mask;
}

int main() {
    int input = 5;
    
    std::cout << "Original: " << input << " (Binary: 101)" << std::endl;
    std::cout << "XOR Method Result: " << flipWithXOR(input) << " (Binary: 010)" << std::endl;
    std::cout << "Bitset Method Result: " << flipWithBitset(input) << std::endl;
    
    return 0;
}
