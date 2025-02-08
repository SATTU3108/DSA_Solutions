/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

bool helperFunc(TreeNode* p,TreeNode* q) {
  if (p==NULL && q==NULL) return true;
  if (p==NULL || q==NULL) return false;
  return (p->val==q->val && helperFunc(p->left,q->right) && helperFunc(p->right,q->left));
}
bool isSymmetric(TreeNode* root) {
  return helperFunc(root->left,root->right);
}
