#include "../helper.hpp"
#include "tree.cpp"
#include <cstring>

using namespace std;

int main() {
  const char *preorder = "abcdef";
  const char *inorder = "bcaedf";

  TreeNode *root = buildTree(preorder, inorder, strlen(inorder));
  
  printTree(root, 0);
  return 0;
}
