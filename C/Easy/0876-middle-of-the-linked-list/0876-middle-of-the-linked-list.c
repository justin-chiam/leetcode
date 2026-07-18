/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int count = 0;
    struct ListNode* curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    curr = head;
    for (int i = 0; i < count / 2; i++) {
        curr = curr->next;
    }

    return curr;
}