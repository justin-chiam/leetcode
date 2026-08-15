/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void doGetMinimumDifference(struct TreeNode* t, bool *firstVal, int *prev, int *min) {
    if (t == NULL) return;

    // in-order traversal
    doGetMinimumDifference(t->left, firstVal, prev, min);

    if (*firstVal) {
        *prev = t->val;
        *firstVal = false;
    } else {
        if (*min == 0 || abs(t->val - *prev) < *min) {
            *min = abs(t->val - *prev);
        }
        *prev = t->val;
    }

    doGetMinimumDifference(t->right, firstVal, prev, min);
}

int getMinimumDifference(struct TreeNode* root) {
    bool firstVal = true;
    int prev = 0;
    int min = 0;
    doGetMinimumDifference(root, &firstVal, &prev, &min);
    return min;
}