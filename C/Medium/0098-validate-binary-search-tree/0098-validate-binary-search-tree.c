/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool isValid(struct TreeNode* node, long long lo, long long hi) {
    if (node == NULL) return true;
    if (node->val <= lo || node->val >= hi) return false;
    return isValid(node->left, lo, node->val) && isValid(node->right, node->val, hi);
}

bool isValidBST(struct TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}