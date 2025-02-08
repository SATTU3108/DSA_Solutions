/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/

vector<vector<int>> levelOrder(TreeNode* root) {
  if (root==NULL) return {};
  vector<vector<int>> ans;
  queue <TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
      int q_size=q.size();
      vector <int> temp;
      for (int i=0;i<q_size;i++) {
          TreeNode* curr=q.front();
          q.pop();
          temp.push_back(curr->val);
          if (curr->left!=NULL) q.push(curr->left);
          if (curr->right!=NULL) q.push(curr->right);
       }
      ans.push_back(temp);
  }
  return ans;
}
