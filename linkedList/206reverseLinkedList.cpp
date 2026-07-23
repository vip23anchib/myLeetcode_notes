// Definition for a singly-linked list node.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers: 'prev' tracks the reversed part, 'curr' tracks the remaining part
        ListNode* prev = NULL;      // Initially, there is no reversed part, so 'prev' is NULL
        ListNode* curr = head;      // Start traversing from the original head of the list

        // Traverse through the list until the end is reached
        while (curr != NULL) {
            // Step 1: Save the next node before breaking the link
            ListNode* front = curr->next;
            
            // Step 2: Reverse the current node's pointer to point backwards
            curr->next = prev;
            
            // Step 3: Move 'prev' one step forward to the current node
            prev = curr;
            
            // Step 4: Move 'curr' one step forward to the saved next node
            curr = front;
        }
        
        // 'prev' now points to the new head of the fully reversed linked list
        return prev;   
    }
};
