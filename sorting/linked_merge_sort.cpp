#include "../helper.hpp"

struct ListNode {
	int value;
	ListNode *next;
	ListNode(int v) {
		this->value = v;
		this->next = NULL;
	}
	
	~ListNode () {
		if (this->next != NULL) {
			delete this->next;
		}
	}
};

int getLen(ListNode *head) {
	if (head == NULL) return 0;
	int count = 0;
	while(head->next != NULL) {
		count++;
		head = head->next;
	}
	return count + 1;
}

void printList(ListNode *head) {
	while (head != NULL) {
		cout << head->value << ", ";
		head = head->next;
	}
	cout << "END" << endl;
}

ListNode *mergeBySize(ListNode *head, int size) {
	ListNode *left;
	ListNode *right;
	ListNode *nextLeft;
	ListNode placeHolder(0);
	ListNode **currentTail;
	currentTail = &(placeHolder.next);
	left = head;
	while (left != NULL) {
		int leftCount = 0;
		int rightCount = 0;
		right = left;
		for (int i = 0; i < size; ++i) {
			right = right->next;
			if (right == NULL) break;
		}
		if (right != NULL) {
			cout << "Current Left: " << left->value << endl;
			cout << "Current Right: " << right->value << endl;
			nextLeft = right;
			for (int i = 0; i < size; ++i) {
				nextLeft = nextLeft->next;
				if (nextLeft == NULL) break;
			}
			while (leftCount < size && right != NULL && rightCount < size) {
				if (left->value > right->value) {
					*currentTail = right;
					currentTail = &(right->next);
					right = right->next;
					rightCount++;
				} else {
					*currentTail = left;
					currentTail = &(left->next);
					left = left->next;
					leftCount++;
				}
			}
		} else {
			nextLeft = NULL;
		}
		if (right == NULL || leftCount != size) {
			*currentTail = left;
			while(*currentTail != NULL && leftCount++ < size) currentTail = &((*currentTail)->next);
			*currentTail = NULL;
		} else if (rightCount != size && right != NULL) {
			*currentTail = right;
			while(*currentTail != NULL && rightCount++ < size) currentTail = &((*currentTail)->next);
			*currentTail = NULL;
		}
		left = nextLeft;
	}
	ListNode *result = placeHolder.next;
	placeHolder.next = NULL;
	return result;
}

ListNode *mergeSort(ListNode *head) {
	int len = getLen(head);
	int size = 1;
	ListNode *newHead = head;
	while (size < len) {
		// merge size by size
		newHead = mergeBySize(newHead, size);
		printList(newHead);
		size <<= 1;
	}
	return newHead;
}

ListNode *toListNode(int *arr, int len) {
	ListNode *head;
	ListNode **current = &head;
	for (int i = 0; i < len; ++i) {
		(*current) = new ListNode(arr[i]);
		current = &((*current)->next);
	}
	return head;
}

int main() {
	int arr[] = {2,1,4,6,78,51,2,3,1,5,3,6,8,33,215,2,7,8};
	ListNode *head = toListNode(arr, ARRSIZE(arr, int));
	mergeSort(head);
	
	return 0;
}