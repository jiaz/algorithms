#include "../helper.hpp"
#include "tree.cpp"

void bst_to_list(TreeNode *root, TreeNode *&front, TreeNode *&end) {
  if (root == NULL) {
    front = NULL; end = NULL;
    return;
  }
  TreeNode *leftFront, *leftEnd, *rightFront, *rightEnd;
  bst_to_list(root->children[0], leftFront, leftEnd);
  bst_to_list(root->children[1], rightFront, rightEnd);
  front = (leftFront == NULL) ? root : leftFront;
  end = (rightEnd == NULL) ? root : rightEnd;
  root->children[0] = leftEnd;
  root->children[1] = rightFront;
  if (leftEnd != NULL) leftEnd->children[1] = root;
  if (rightFront != NULL) rightFront->children[0] = root;
}

int main() {
  const char pre[] = {'a' + 10,'a' + 6,'a' + 4,'a' + 8,'a' + 14,'a'+12,'a'+16};
  const char in[] = {'a'+4,'a'+6,'a'+8,'a'+10,'a'+12,'a'+14,'a'+16};
  TreeNode *root = buildTree(pre, in, 7);
  printTree(root, 0);
  TreeNode *front, *end;
  bst_to_list(root, front, end);
  while (front != NULL) {
    cout << front->value << ",";
    front = front->children[1];
  }
  cout << "END" << endl;
  while (end != NULL) {
    cout << end->value << ",";
    end = end->children[0];
  }
  cout << "END" << endl;
  return 0;
}
