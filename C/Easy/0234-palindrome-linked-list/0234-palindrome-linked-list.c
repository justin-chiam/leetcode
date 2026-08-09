/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    // count number of nodes in list
    int count = 0;
    struct ListNode *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    // allocate memory for array to store list elements
    int *arr = malloc(count * sizeof(int));
    if (arr == NULL) return false;

    // fill up array with list elements
    curr = head;
    for (int i = 0; i < count; i++) {
        arr[i] = curr->val;
        curr = curr->next;
    }

    // check for palindrome in arr
    int left = 0;
    int right = count - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            free(arr);
            return false;
        }
        left++;
        right--;
    }
    
    free(arr);
    return true;
}