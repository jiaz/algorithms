#include "../helper.hpp"
#include "tree.cpp"
#include <queue>
#include <cstring>

using namespace std;

void printLevel(TreeNode *root, void (fn)(TreeNode *)) {
  if (root == NULL) return;
  queue<TreeNode *> tq;
  tq.push(root);
  int levelLen = 1;
  while(tq.size() > 0) {
    int nextLevelLen = 0;
    while(levelLen > 0) {
      TreeNode *n = tq.front();
      fn(n);
      if (n->children[0]) {tq.push(n->children[0]); nextLevelLen++;}
      if (n->children[1]) {tq.push(n->children[1]); nextLevelLen++;}
      tq.pop();
      levelLen--;
    }
    levelLen = nextLevelLen;
    //cout << endl;
  }
}

void print(TreeNode *n) {
  cout << n->value;
}

int main() {
  const char *pre = "abcdefg";
  const char *in = "cbdaefg";

  TreeNode *root = buildTree(pre, in, strlen(pre));
  printTree(root, 0);
  printLevel(root, &print);

  return 0;
}
