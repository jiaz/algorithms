#include "../helper.hpp"

struct ListNode {
  int value;
  ListNode *random;
  ListNode *next;
  ListNode(int v) {
    value = v;
    random = next = NULL;
  }
};

ListNode *copyList(ListNode *head) {
  ListNode *current = head;
  ListNode *newHead = NULL;
  while(current != NULL) {
    ListNode *newCurrent = new ListNode(current->value);
    if (newHead == NULL) newHead = newCurrent;
    newCurrent->next = current->next;
    current->next = newCurrent;
    current = newCurrent->next;
  }
  current = head;
  while(current != NULL) {
    current->next->random = ((current->random == NULL) ? NULL : current->random->next);
    current = current->next->next;
  }
  current = head;
  while(current != NULL) {
    ListNode *nc = current->next;
    ListNode *n = nc->next;
    ListNode *nnc = (n == NULL ? NULL : n->next);
    current->next = n;
    nc->next = nnc;
    current = n;
  }
  return newHead;
}

void printList(ListNode *n) {
  while(n != NULL) {
    cout << n->value << "," << (n->random == NULL ? 0 : n->random->value) << endl;
    n = n->next;
  }
}

int main () {
  ListNode *a = new ListNode(1);
  ListNode *b = new ListNode(2);
  ListNode *c = new ListNode(3);
  ListNode *d = new ListNode(4);
  a->next = b; b->next = c; c->next = d;
  a->random = NULL; b->random = c; c->random=NULL; d->random = NULL;

  ListNode *n = copyList(b);
  printList(n);
  return 0;
}
