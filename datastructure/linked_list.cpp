#include "../helper.hpp"

using namespace std;

struct ListNode {
  int data;
  ListNode *next;
public:
  ListNode() {
    next = NULL;
  }
};

class LinkedList {
private:
  ListNode *phead;
  ListNode *ptail;

public:
  LinkedList() {
    phead = ptail = NULL;
  }
  
  ListNode *getHead() {
    return phead;
  }

  void append(int value) {
    ListNode *n = new ListNode;
    n->data = value;
    if (phead == NULL) {
      phead = ptail = n;
    } else {
      ptail->next = n;
      ptail = n;
    }
  }

  bool isEmpty() {
    return (phead == NULL && ptail == NULL);
  }
  
  void remove(ListNode *node) {
    if (node == NULL) return;
    ListNode* pp = phead;
    if (node == phead) {
      phead = phead->next;
      if (node == ptail) {
	ptail = NULL;
      }
    } else {
      while(pp != NULL) {
        if (pp->next == node) {
  	  break;
        }
	pp = pp->next;
      }
      if (pp == NULL) return;
      pp->next = node->next;
      if (node == ptail) {
	ptail = pp;
      }
    }
    delete node;
  }
};

int main() {
  LinkedList list;
  list.append(10);
  list.append(20);
  for(ListNode *head = list.getHead(); head != NULL; head = head->next) {
    cout << head->data << endl;
    list.remove(head);
    cout << list.isEmpty() << endl;
  }
  return 0;
}
  
