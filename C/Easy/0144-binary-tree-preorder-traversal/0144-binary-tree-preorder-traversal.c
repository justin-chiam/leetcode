/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_NODES 100

void doPreorderTraversal(struct TreeNode* t, int *array, int *returnSize) {
    if (t == NULL) return;

    array[(*returnSize)++] = t->val;

    doPreorderTraversal(t->left, array, returnSize);
    doPreorderTraversal(t->right, array, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *array = malloc(MAX_NODES * sizeof(int));
    *returnSize = 0;
    doPreorderTraversal(root, array, returnSize);
    return array;
}