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

void doInorderTraversal(struct TreeNode *t, int *array, int *returnSize) {
    if (t == NULL) return;

    doInorderTraversal(t->left, array, returnSize);

    array[*returnSize] = t->val;
    (*returnSize)++;

    doInorderTraversal(t->right, array, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *array = malloc(MAX_NODES * sizeof(int));
    *returnSize = 0;
    doInorderTraversal(root, array, returnSize);
    return array;
}