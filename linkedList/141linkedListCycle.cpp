/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// --------------------------------------------------------------------------------------------
// Floyd's Cycle-Finding Algorithm (Tortoise and Hare) => O(N)
class Solution {
public:
    // Function to detect if a linked list contains a cycle (loop)
    // Uses Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
    bool hasCycle(ListNode *head) {

        // Initialize two pointers at the start of the list
        ListNode* slow = head; // Moves 1 step at a time (Tortoise)
        ListNode* fast = head; // Moves 2 steps at a time (Hare)

        // Traverse the list. If fast reaches NULL, there is no cycle.
        // We check 'fast' and 'fast->next' to prevent null pointer dereferencing.
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps

            // If there is a cycle, the fast pointer will eventually catch up 
            // to the slow pointer, meaning they will point to the exact same node.
            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        
        // If the loop terminates, the fast pointer reached the end of the list,
        // which means the list is linear and has no cycle.
        return false;   
    }
};
