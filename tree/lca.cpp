#include "../helper.hpp"
#include "tree.cpp"
#include <cstring>

using namespace std;

TreeNode *recFindLCA(TreeNode *root, char a, char b, bool &hasA, bool &hasB) {
	if (root == NULL) {
		hasA = false;
		hasB = false;
		return NULL;
	}
	bool leftA, leftB;
	TreeNode *left = recFindLCA(root->children[0], a, b, leftA, leftB);
	bool rightA, rightB;
	TreeNode *right = recFindLCA(root->children[1], a, b, rightA, rightB);
	hasA = leftA || rightA;
	hasB = leftB || rightB;
	if (left != NULL) {
		return left;
	}
	if (right != NULL) {
		return right;
	}
	if (root->value == a) hasA = true;
	if (root->value == b) hasB = true;
	if (hasA && hasB) return root;
	return NULL;
}

TreeNode *findLCA(TreeNode *root, char a, char b) {
	bool hasA, hasB;
	TreeNode *lca = recFindLCA(root, a, b, hasA, hasB);
	return lca;
}

int main() {
  const char *preorder = "abcdef";
  const char *inorder = "bcaedf";

  TreeNode *root = buildTree(preorder, inorder, strlen(inorder));  
  printTree(root, 0);
  
  TreeNode *lca = findLCA(root, 'b', 'd');
  
  if (lca != NULL) cout << lca->value << endl;
  else cout << "NO LCA" << endl;
  
  return 0;
}
