/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* curr1 = l1;
    struct ListNode* curr2 = l2;
    int carry = 0;

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while (curr1 != NULL || curr2 != NULL || carry != 0) {
        int val1 = curr1 ? curr1->val : 0;
        int val2 = curr2 ? curr2->val : 0;
        int sum = val1 + val2 + carry;

        carry = sum / 10;

        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        if (curr1) curr1 = curr1->next;
        if (curr2) curr2 = curr2->next;
    }
    
    return head;
}