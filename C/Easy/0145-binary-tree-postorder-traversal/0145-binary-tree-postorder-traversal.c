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

void doPostOrderTraversal(struct TreeNode* t, int *array, int *returnSize) {
    if (t == NULL) return;

    doPostOrderTraversal(t->left, array, returnSize);
    doPostOrderTraversal(t->right, array, returnSize);

    array[*returnSize] = t->val;
    (*returnSize)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *array = malloc(MAX_NODES * sizeof(int));
    *returnSize = 0;
    doPostOrderTraversal(root, array, returnSize);
    return array;
}