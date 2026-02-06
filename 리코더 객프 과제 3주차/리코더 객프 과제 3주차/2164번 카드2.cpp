#include <iostream>
#include <string.h>

using namespace std;

class stack {
private:
	struct node {
		int value;
		struct node* prev;
		struct node* next;
	};

	int number;
	node* back;
	node* front;

public:
	stack() : number(0), back(NULL), front(NULL) {};

	void card(int x) {
		for (int i = 0; i < x; i++) {
			node* newnode = new node;

			if (NULL == back) {
				newnode->value = i+1;
				newnode->prev = NULL;
				newnode->next = NULL;
				back = newnode;
				front = newnode;
			}
			else {
				newnode->value = i + 1;
				newnode->prev = back;
				newnode->next = NULL;
				back->next = newnode;
				back = newnode;
			}
		}
	}

	void trash() {
		node* del = front;

		front = front->next;

		delete del;		
	}

	void bottom() {
		if (front == back) {
			cout << front->value;
		}

		else {
			back->next = front;
			front->prev = back;
			front->next->prev = NULL;
			front = front->next;
			back->next->next = NULL;
			back = back->next;
		}
	}

};

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}

	stack st = stack();
	st.card(n);

	for (int i = 1; i < n; i++) {
		st.trash();
		st.bottom();
	}


	return 0;
}