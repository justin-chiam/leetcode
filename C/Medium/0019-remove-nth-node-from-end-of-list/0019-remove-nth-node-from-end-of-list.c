/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr = head;
    int length = 0;
    // 1st pass - count how many nodes in list
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }

    // if node to delete is head node
    if (length == n) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    curr = head;
    int target = length - n;
    // 2nd pass - find target node to delete
    for (int i = 1; i < target; i++) {
        curr = curr->next;
    }

    struct ListNode* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);

    return head;
}