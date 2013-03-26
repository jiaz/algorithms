#include "../helper.hpp"

using namespace std;

struct ListNode {
  int value;
  ListNode *next;
  ListNode(int value) {
    this->value = value;
    next = NULL;
  }
};

ListNode *reverse_list(ListNode *head) {
  ListNode *newHead = NULL;
  ListNode *current = head;
  while(current != NULL) {
    ListNode *tmp = current->next;
    current->next = newHead;
    newHead = current;
    current = tmp;
  }
  return newHead;
}

ListNode *merge_list(ListNode *left, ListNode *right) {
  ListNode *leftCurrent = left;
  ListNode *rightCurrent = right;
  ListNode *merged = NULL;
  ListNode *mergedTail = NULL;
  while(leftCurrent != NULL && rightCurrent != NULL) {
    if (leftCurrent->value < rightCurrent->value) {
      if (merged == NULL) {
	merged = leftCurrent;
	mergedTail = merged;
      } else {
	mergedTail->next = leftCurrent;
	mergedTail = leftCurrent;
      }
      leftCurrent = leftCurrent->next;
    } else {
      if (merged == NULL) {
	merged = rightCurrent;
	mergedTail = merged;
      } else {
	mergedTail->next = rightCurrent;
	mergedTail = rightCurrent;
      }
      rightCurrent = rightCurrent->next;
    }
  }
  if (leftCurrent != NULL) {
    if (merged == NULL) {
      merged = leftCurrent;
    } else {
      mergedTail->next = leftCurrent;
    }
  } else if (rightCurrent != NULL) {
    if (merged == NULL) {
      merged = rightCurrent;
    } else {
      mergedTail->next = rightCurrent;
    }
  }
  return merged;
}

int main() {
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);

  a.next = &b;
  b.next = &c;

  ListNode x(2);
  ListNode y(4);
  ListNode z(5);
  ListNode m(6);
  x.next = &y;
  y.next = &z;
  z.next = &m;

  ListNode *xa = &a;

  ListNode *aa = &x;

  ListNode *n = merge_list(xa, aa);
  for(;n != NULL; n = n->next) {
    cout << n->value << endl;
  }
  return 0;
}
