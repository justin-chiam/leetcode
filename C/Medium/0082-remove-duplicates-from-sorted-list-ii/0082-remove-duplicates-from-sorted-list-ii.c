/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    struct ListNode *newHead = head;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *temp = NULL;
    while (curr != NULL) {
        if (curr->next != NULL && curr->val == curr->next->val) {
            // keep freeing if multiple duplicates
            while (curr->next != NULL && curr->val == curr->next->val) {
                temp = curr;
                curr = curr->next;
                free(temp);
            }
            // free last node of duplicates
            temp = curr;
            curr = curr->next;
            free(temp);

            // check if new head
            if (prev == NULL) {
                newHead = curr;
            } else {
                prev->next = curr;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return newHead;
}