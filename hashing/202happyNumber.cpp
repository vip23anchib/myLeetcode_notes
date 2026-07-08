// LeetCode 202 - Happy Number
// Topic: Hashing, Cycle Detection

// -------------------- Approach 1: unordered_set --------------------
// Idea:
// Store every number we encounter.
// - If n becomes 1 -> Happy Number (true)
// - If a number repeats -> cycle detected -> Not Happy (false)
//
// Trick:
// A repeated number means the same sequence will repeat forever,
// so we'll never reach 1.
//
// Steps:
// 1. While n != 1
// 2. If n already exists in set -> return false
// 3. Insert n into set
// 4. Replace n with sum of squares of its digits
// 5. If n becomes 1 -> return true
//
// Time: O(log n) (practically constant)
// Space: O(k)


// ---------------- Also we can use : Floyd's Hare & Tortoise ----------------
//
// Why it works:
// Each number generates exactly ONE next number,
// so the sequence behaves like a linked list.
//
// If the sequence doesn't reach 1,
// it must eventually enter a cycle.
//
// Use:
// slow = next(slow)
// fast = next(next(fast))
//
// - If fast reaches 1 -> Happy Number
// - If slow == fast (before reaching 1) -> cycle exists -> Not Happy
//
// Time: O(log n)
// Space: O(1)



class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> visited;

        while (n!=1 && visited.find(n)==visited.end()){
            visited.insert(n);

            int totalSum=0;

            while(n>0){
                int digit= n % 10;
                totalSum+= digit*digit;
                n= n/10;
            }
            n=totalSum;
        }
        return n==1;
    }
};
