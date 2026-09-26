class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = prevGroup;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == NULL) {
                    return dummy->next;
                }
            }

            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* current = prevGroup->next;

            while (current != groupNext) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            // Connect previous part to reversed group
            ListNode* oldStart = prevGroup->next;
            prevGroup->next = kth;

            // Move to next group
            prevGroup = oldStart;
        }
    }
};