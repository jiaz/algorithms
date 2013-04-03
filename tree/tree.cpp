#include "../helper.hpp"

using namespace std;

struct TreeNode {
  char value;
  TreeNode *children[2];
};

TreeNode *buildTree(const char *preorder, const char *inorder, size_t len) {
  if (len == 0) return NULL;
  char root = preorder[0];
  int i = 0;
  for (;;) {
    if (root == inorder[i]) break;
    i++;
  }
  TreeNode *rootNode = new TreeNode;
  rootNode->value = root;
  TreeNode *left = buildTree(preorder + 1, inorder, i);
  TreeNode *right = buildTree(preorder + i + 1, inorder + i + 1, len - i - 1);
  rootNode->children[0] = left;
  rootNode->children[1] = right;
  return rootNode;
}

void printTree(const TreeNode *root, int depth) {
  if (root == NULL) return;
  for (int i = 0; i < depth; ++i) cout << "  ";
  cout << (root == NULL ? ' ' : root->value) << " {" << endl;
  if (root != NULL) {
    printTree(root->children[0], depth+1);
    printTree(root->children[1], depth+1);
  }
  for (int i = 0; i < depth; ++i) cout << "  ";
  cout << "}" << endl;
}
