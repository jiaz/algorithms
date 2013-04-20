#include "../helper.hpp"

struct PetroNode {
	int n;
	int maxPetro;
	int nextNodeDist;
};

struct ListNode {
	PetroNode *station;
	ListNode *next;
	ListNode *prev;
};

void printPossibleStartingPoint(ListNode *stations, int size) {
	int current = 0;
	ListNode *currentNode = stations;
	while (size > 1 && current < size) {
		if (currentNode->station->maxPetro < currentNode->station->nextNodeDist) {
			currentNode->prev->station->maxPetro += currentNode->station->maxPetro;
			currentNode->prev->station->nextNodeDist += currentNode->station->nextNodeDist;
			
			currentNode->next->prev = currentNode->prev;
			currentNode->prev->next = currentNode->next;
			currentNode = currentNode->prev;
			
			size--;
			if (current > 0) current--;
		} else {
			current++;
			currentNode = currentNode->next;
		}
	}
	for (int i = 0; i < size; ++i) {
		if (currentNode->station->maxPetro >= currentNode->station->nextNodeDist) {
			cout << currentNode->station->n << endl;
			currentNode = currentNode->next;
		} else {
			cout << "No solution." << endl;
		}
	}
}

int main() {
	PetroNode *arr = new PetroNode[4];
	arr[0].maxPetro = 1;
	arr[0].nextNodeDist = 2;
	arr[0].n = 0;
	arr[1].maxPetro = 2;
	arr[1].nextNodeDist = 1;
	arr[1].n = 1;
	arr[2].maxPetro = 3;
	arr[2].nextNodeDist = 6;
	arr[2].n = 2;
	arr[3].maxPetro = 9;
	arr[3].nextNodeDist = 1;
	arr[3].n = 3;
	ListNode a;
	a.station = &arr[0];
	ListNode b;
	b.station = &arr[1];
	ListNode c;
	c.station = &arr[2];
	ListNode d;
	d.station = &arr[3];
	a.next = &b;
	a.prev = &d;
	b.next = &c;
	b.prev = &a;
	c.next = &d;
	c.prev = &b;
	d.next = &a;
	d.prev = &c;
	printPossibleStartingPoint(&a, 4);
	return 0;
}