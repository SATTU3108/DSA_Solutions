/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

void helperFunc(TreeNode *root,vector <int> &ans) {
  if (root!=NULL) {
      helperFunc(root->left,ans);
      ans.push_back(root->val);
      helperFunc(root->right,ans);
  }
}
vector<int> inorderTraversal(TreeNode* root) {
  vector <int> ans;
  helperFunc(root,ans);
  return ans;
}
//Time complexity:O(N), Space complexity:O(N)
