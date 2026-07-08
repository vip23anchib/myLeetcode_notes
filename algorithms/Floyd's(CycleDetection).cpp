/*
-------------------- Floyd's Cycle Detection (Tortoise & Hare) --------------------

WHAT IS IT?
- Detects whether a cycle exists using O(1) extra space.
- Uses two pointers:
    Slow -> moves 1 step
    Fast -> moves 2 steps

WHY DOES IT WORK?
- If there is NO cycle, fast eventually reaches the end.
- If there IS a cycle, fast can never leave it.
- Since fast moves one extra step than slow every iteration,
  it eventually catches (meets) slow inside the cycle.

WHEN SHOULD THIS COME TO MIND?
Whenever you see:

    x -> f(x) -> f(f(x)) -> ...

or

    Node -> Next Node

where EVERY state/node has EXACTLY ONE next state.

Examples:
1. Linked List Cycle
2. Happy Number
3. Find Duplicate Number (Array as Linked List)

INTERVIEW CHECKLIST:
Can I keep moving forever?
        ↓
Can values repeat (cycle)?
        ↓
Am I NOT allowed extra space?
        ↓
Think Floyd's Cycle Detection.

TIME  : O(n)
SPACE : O(1)
*/


// Code for Floyd's:
slow = start;
fast = start;

while(fast != NULL && fast->next != NULL){

    slow = slow->next;

    fast = fast->next->next;

    if(slow == fast)
        return true;
}

return false;

// ------------------------------------------------------------------------------------------------------------------

//Solving 202.Happy Number using Floyd's Algorithm

class Solution {
public:
    // Returns the next number by summing squares of digits.
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        // Move slow by 1 step and fast by 2 steps.
        // If a cycle exists, they will eventually meet.
        do {
            slow = getNext(slow);

            fast = getNext(fast);
            fast = getNext(fast);

        } while (slow != fast);

        // If they meet at 1, number is happy.
        // Otherwise they met inside a cycle.
        return slow == 1;
    }
};
