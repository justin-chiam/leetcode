/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int val) {
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct TreeNode* doSortedArrayToBST(int *nums, int lo, int hi) {
    if (lo > hi) return NULL;

    int mid = lo + (hi - lo) / 2;
    struct TreeNode *n = newNode(nums[mid]);

    n->left = doSortedArrayToBST(nums, lo, mid - 1);
    n->right = doSortedArrayToBST(nums, mid + 1, hi);

    return n;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return doSortedArrayToBST(nums, 0, numsSize - 1);
}