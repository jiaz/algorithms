#include "../helper.hpp"
#include "tree.cpp"

typedef void func_visit(TreeNode *);

void printNode(TreeNode *node) {
	cout << node->value << endl;
}

void non_rec_pre_order(TreeNode *root, func_visit *visit) {
	if (root == NULL) return;
	stack<TreeNode *> stk;
	stk.push(root);
	while(!stk.empty()) {
		TreeNode *current = stk.top();
		visit(current);
		stk.pop();
		for (int i = 0; i < 2; ++i) {
			if (current->children[1 - i] != NULL) {
				stk.push(current->children[1 - i]);
			}
		}
	}
}

void non_rec_in_order(TreeNode *root, func_visit *visit) {
	if (root == NULL) return;
	stack<TreeNode *> stk;
	stk.push(root);
	TreeNode *pre = NULL;
	while(!stk.empty()) {
		TreeNode *current = stk.top();
		if (current->children[0] == NULL && current->children[1] == NULL) {
			visit(current);
			pre = current;
			stk.pop();
		} else if (pre == current->children[0]) {
			visit(current);
			pre = current;
			if (current->children[1] != NULL) {
				stk.push(current->children[1]);
			} else {
				pre = NULL;
			}
		} else if (pre == current->children[1]) {
			pre = current;
			stk.pop();
		} else {
			if (current->children[0] != NULL) {
				stk.push(current->children[0]);
			} else {
				pre = NULL;
			}
		}
	}
}

void non_rec_post_order(TreeNode *root, func_visit *visit) {
	if (root == NULL) return;
	stack<TreeNode *> stk;
	stk.push(root);
	TreeNode *pre = NULL;
	while(!stk.empty()) {
		TreeNode *current = stk.top();
		if (current->children[0] == NULL && current->children[1] == NULL) {
			visit(current);
			pre = current;
			stk.pop();
		} else if (pre == current->children[1]) {
			visit(current);
			pre = current;
			stk.pop();
		} else if (pre == current->children[0]) {
			if (current->children[1] != NULL) {
				stk.push(current->children[1]);
			} else {
				pre = NULL;
			}
		} else {
			if (current->children[0] != NULL) {
				stk.push(current->children[0]);
			} else {
				pre = NULL;
			}
		}
	}
}

int main() {
    const char *preorder = "abcdef";
    const char *inorder = "bcaedf";

    TreeNode *root = buildTree(preorder, inorder, strlen(inorder));
	printTree(root, 0);
	
	non_rec_pre_order(root, printNode);
	
	cout << "----" << endl;
	
	non_rec_in_order(root, printNode);
	
	cout << "----" << endl;
	
	non_rec_post_order(root, printNode);
	
	return 0;
}