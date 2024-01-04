/* ZERO_ADVANCE DSA BOSSCODER 
114. Flatten Binary Tree to Linked List
link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
solution : https://www.youtube.com/watch?v=sWf7k1x9XR4&ab_channel=takeUforward
https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:
Input: root = []
Output: []
Example 3:
Input: root = [0]
Output: [0]
*/
TreeNode*prev=NULL;
void flatten(TreeNode* root) {
    TreeNode* curr=root;
    while(curr){
        if(curr->left){
            prev=curr->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}
TreeNode*prev=nullptr;
void flatten(TreeNode* root) {
    if(root==NULL){
        return ;
    }
    flatten(root->right);
    flatten(root->left);
    root->right=prev;
    root->left=NULL;
    prev=root;
}

