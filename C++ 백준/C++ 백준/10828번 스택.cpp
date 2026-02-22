#include <iostream>
#include <string.h>

using namespace std;

class stack {
private :
	struct node {
		int value;
		struct node* prev;
		struct node* next;
	};

	int number;
	node* head;

public :
	stack() : number(0), head(NULL) {};

	void push() {
		int x;
		cin >> x;
		node* newnode = new node;

		if (NULL == head) {
			newnode->value = x;
			newnode->prev = NULL;
			newnode->next = NULL;
			head = newnode;
		}
		else {
			newnode->value = x;
			newnode->prev = head;
			newnode->next = NULL;
			head->next = newnode;
			head = newnode;
		}
		number++;
	}

	void pop() {
		if (head == NULL)
			cout << -1 << '\n';
		else {
			cout << head->value << '\n';
			node* del = head;
			head = head->prev;
			delete del;

			if (NULL != head)
				head->next = NULL;
			
			number--;
		}
	}

	void size() {
		cout << number << '\n';
	}

	void empty() {
		if (head == NULL)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	void top() {
		if (head == NULL)
			cout << -1 << '\n';
		else
			cout << head->value << '\n';
	}
};

int main() {
	int n;
	char temp[6];
	cin >> n;
	stack st = stack();

	for (int i = 0; i < n; i++) {
		cin >> temp;
		
		if (!strcmp(temp, "push"))
			st.push();

		else if (!strcmp(temp, "pop"))
			st.pop();
		
		else if (!strcmp(temp, "size"))
			st.size();

		else if (!strcmp(temp, "empty"))
			st.empty();

		else if (!strcmp(temp, "top"))
			st.top();
	}

	return 0;
}