#include <math.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* left = root;
    struct TreeNode* right = root;
    int leftHeight = 0;
    int rightHeight = 0;

    while (left != NULL) {
        leftHeight++;
        left = left->left;
    }

    while (right != NULL) {
        rightHeight++;
        right = right->right;
    }

    // 'root' is a complete tree
    if (leftHeight == rightHeight) {
        return pow(2, leftHeight) - 1;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}