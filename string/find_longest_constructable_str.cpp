#include "../helper.hpp"
#include <cstring>

using namespace std;

struct ListNode {
	const char *str;
	ListNode *next;
};

struct TrieNode {
	TrieNode *children[26];
	ListNode *str_head;
	ListNode *str_last;
};

class MatchStringFinder {
private:
	TrieNode *root;
	
	void sort(const char *str, int len, char *buff) {
		strncpy(buff, str, len);
		buff[len] = 0;
		if (len <= 1) return;
		for (int i = 1; i < len; ++i) {
			char target = buff[i];
			int j = i - 1;
			while(j >= 0 && (buff[j] > target)) {
				buff[j + 1] = buff[j];
				--j;
			}
			buff[j + 1] = target;
		}
	}
	
	void make_trie(const char *str) {
		int len = strlen(str);
		char *buff = new char[len + 1];
		sort(str, len, buff);
		TrieNode **current = &root;
		for (int i = 0; i < len; ++i) {
			int pos = buff[i] - 'a';
			current = &((*current)->children[pos]);
			if (*current == NULL) {
				*current = new TrieNode();
			}
		}
		if ((*current)->str_head == NULL) {
			(*current)->str_head = new ListNode;
			(*current)->str_last = (*current)->str_head;
			(*current)->str_last->str = str;
		} else {
			(*current)->str_last->next = new ListNode;
			(*current)->str_last->next->str = str;
			(*current)->str_last = (*current)->str_last->next;
		}
		delete [] buff;
	}
	
	const char *rec_find_match(const char *buff, size_t len, TrieNode *root) {
		if (len == 0) {
			if (root->str_head != NULL) {
				return root->str_head->str;
			} else return NULL;
		}
		const char *res = rec_find_match(buff + 1, len - 1, root);
		int max = 0;
		if (res != NULL) max = strlen(res);
		for (int i = 0; i < len; ++i) {
			int pos = buff[i] - 'a';
			if (root->children[pos] != NULL) {
				//cout << "match " << i << ", " << buff[i] << endl;
				const char *currentRes =
					rec_find_match(buff + i + 1, len - i - 1, root->children[pos]);
				if (currentRes != NULL) {
					int currentLen = strlen(currentRes);
					if (currentLen > max) {
						max = currentLen;
						res = currentRes;
					}
				}
			}
		}
		//if (res != NULL) cout << "found " << res << endl;
		return res;
	}
	
	void deleteChildren(TrieNode *root) {
		if (root == NULL) return;
		for (int i = 0; i < 26; ++i) {
			deleteChildren(root->children[i]);
		}
		ListNode *head = root->str_head;
		while (head != NULL) {
			ListNode *temp = head->next;
			delete head;
			head = temp;
		}
		delete root;
	}

public:
	MatchStringFinder() {
		root = new TrieNode;
		root->str_head = NULL;
		root->str_last = NULL;
	}
	
	~MatchStringFinder() {
		deleteChildren(root);
	}

	void build(const char **dict, size_t size) {
		for (int i = 0; i < size; ++i) {
			make_trie(dict[i]);
		}
	}
	
	const char *find_longest_match(const char *sets, size_t len) {
		char *buff = new char[len];
		sort(sets, len, buff);
		cout << buff << endl;
		return rec_find_match(buff, len, root);
	}
	
	const char *straight_find_longest_match(const char **dict, int dict_size,
		const char *letters, int letter_size) {
		int req[26] = {0};
		for (int i = 0; i < letter_size; ++i) {
			req[letters[i] - 'a']++;
		}
		const char *res = NULL;
		int max = 0;
		int tr[26] = {0};
		for (int i = 0; i < dict_size; ++i) {
			int len = strlen(dict[i]);
			memcpy(tr, req, sizeof(tr));
			bool flag = true;
			for (int j = 0; j < len; ++j) {
				int vec = dict[i][j] - 'a';
				tr[vec]--;
				if (tr[vec] < 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				int currentLen = strlen(dict[i]);
				if (max < currentLen) {
					max = currentLen;
					res = dict[i];
				}
			}
		}
		return res;
	}
};

int main() {
	const char* dict[] = {
		"abacus",
		"deltoid",
		"gaff",
		"giraffe",
		"microphone",
		"reef",
		"qar"
	};
	const char *sets = "abcdefghijklmnopqrstuvwphonemicro";
	MatchStringFinder finder;
	//finder.build(dict, 7);
	const char *res = finder.straight_find_longest_match(dict, 7, sets, strlen(sets));
	cout << res << endl;
	return 0;
}
	