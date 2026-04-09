#include <iostream>
using namespace std;
char* arr_main(char* arr, char** words, int n);

int strlen(char *word) {
	int i = 0;
	while (word[i] != '\0')
		i++;
	return i;
}

void delete_arr(char** arr, int num, int& size) {
	if (num != size - 1) {
		for (int i = num; i < size - 1; i++)
			for(int j=0; j<=strlen(arr[i+1]); j++)
				arr[i][j] = arr[i + 1][j];
	}
	arr[size - 1][0] = '\0';
	size--;
}

void insert_arr(char* arr, char *word, int& idx) {
	int len = strlen(word);
	for (int i = 1; i <= len; i++)
		arr[idx++] = word[i];
}

void strcpy(char* d, char* s) {
	int len = strlen(s);
	for (int i = 0; i <= len; i++)
		d[i] = s[i];
}

class intersection {
public :
	char* arr;
	char** words;
	int n;
	int idx;
	int flag;
	int len;

	intersection() {
		this->arr = NULL;
		this->words = NULL;
		this->n = 0;
		this->idx = 0;
		this->flag = 0;
	}

	intersection(char* arr, char** words, int n, int idx, int flag) {
		char* this_arr = new char[strlen(arr)+1];
		strcpy(this_arr, arr);
		char** this_words = new char* [n];
		for (int i = 0; i < n; i++) {
			this_words[i] = new char[21];
			strcpy(this_words[i], words[i]);
		}
		this->arr = this_arr;
		this->words = this_words;
		this->n = n;
		this->idx = idx;
		this->flag = flag;
	}

	void start() {
		insert_arr(arr, words[flag], idx);
		delete_arr(words, flag, n);

		arr = arr_main(arr, words, n);
		len = strlen(arr);
	}

};

char* arr_main(char* arr, char** words, int n) {
	//나머지 단어들 연결
	int count = 0, flag[10], f_idx = 0, max_arr_number, idx = strlen(arr);
	for (int i = 0; i < n; i++) {
		if (arr[idx - 1] == words[i][0]) {
			flag[count++] = i;
		}
	}
	if (count == 1) {
		insert_arr(arr, words[flag[0]], idx);
		delete_arr(words, flag[0], n);
		if(n != 0) arr = arr_main(arr, words, n);
	}
	else if (count == 0 && n != 0) {
		return arr;
	}
	else {
		intersection* intersections = new intersection[count];
		int max = 0;
		for (int i = 0; i < count; i++) {
			intersections[i] = intersection(arr, words, n, idx, flag[i]);

			intersections[i].start();
			if (intersections[i].len > max) {
				max = intersections[i].len;
				max_arr_number = i;
			}
		}
		return intersections[max_arr_number].arr;
	}
	return arr;
}

int main() {
	int n, length = 0, idx = 0, temp;
	cin >> temp;
	n = temp;
	char** words = new char* [n];
	for (int i = 0; i < n; i++) {
		char temp[21];
		words[i] = new char[21];
		cin >> temp;
		strcpy(words[i], temp);
		length += strlen(words[i]);
	}
	length -= n - 1;

	char* arr = new char[length+1];
	arr[length] = '\0';

	//첫번째 단어 탐색
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int len = strlen(words[j]);
			if (words[i][0] == words[j][len - 1]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (int j = 0; j < strlen(words[i]); j++) {
				arr[idx++] = words[i][j];
			}
			arr[idx] = '\0';
			delete_arr(words, i, n);
			break;
		}
	}

	//나머지 단어들 연결
	arr = arr_main(arr, words, n);
	
	cout << arr;

	return 0;
}