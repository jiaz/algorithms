#include "../helper.hpp"
#include "tree.cpp"
#include <vector>

using namespace std;

void print_parent(vector<const TreeNode*> &parent) {
  for(int i = 0; i < parent.size(); ++i) {
    cout << (int)parent[i]->value << ",";
  }
  cout << "END" << endl;
}

void print_path(const TreeNode *root, int target, vector<const TreeNode*> &parent) {
  if (root == NULL) return;
  parent.push_back(root);
  if (root->children[0] == NULL && root->children[1] == NULL && root->value == (char)target) {
    print_parent(parent);
  } else {
    print_path(root->children[0], target - root->value, parent);
    print_path(root->children[1], target - root->value, parent);
  }
  parent.pop_back();
}
  
int main() {
  const char in[] = {4,5,7,10,12};
  const char pre[] = {10,5,4,7,12};
  TreeNode *root = buildTree(pre, in, 5);
  vector<const TreeNode*> p;
  print_path(root, 22, p);
  return 0;
}
