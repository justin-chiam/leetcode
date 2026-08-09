/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void doKthSmallest(struct TreeNode *t, int k, int *upTo, int *res) {
    if (t == NULL) return;

    doKthSmallest(t->left, k, upTo, res);

    (*upTo)++;
    if (*upTo == k) {
        *res = t->val;
        return;
    } else {
        doKthSmallest(t->right, k, upTo, res);
    }
}

int kthSmallest(struct TreeNode *root, int k) {
    int upTo = 0;
    int res = -1;
    doKthSmallest(root, k, &upTo, &res);
    return res;
}