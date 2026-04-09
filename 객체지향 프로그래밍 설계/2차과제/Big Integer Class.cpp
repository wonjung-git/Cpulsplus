#include <iostream>
#include <string>
using namespace std;
class BigInteger;
string Biginteger_add(string d, int n);
string Biginteger_sub(string d, int n);
int compare(string a, string b);

class BigInteger {
public:
	string number;

	BigInteger() {};

	BigInteger(string num) {
		if (num == "-0")
			number = "0";
		else number = num;
	}

	BigInteger operator + (const BigInteger& other) {
		string a = number, b = other.number, result;
		int sum, temp, m_flag=0;

		//add에 음수가 들어왔을 경우 -로 대신 처리하도록
		if (a[0] == '-' && b[0] != '-') {
			a[0] = '0';
			BigInteger temp1 = BigInteger(b);
			BigInteger temp2 = BigInteger(a);
			temp1 = temp1 - temp2;
			return temp1;
		}
		else if (a[0] != '-' && b[0] == '-') {
			b[0] = '0';
			BigInteger temp1 = BigInteger(a);
			BigInteger temp2 = BigInteger(b);
			temp1 = temp1 - temp2;
			return temp1;
		}
		else if (a[0] == '-' && b[0] == '-') m_flag = 1;

		if (a.length() == b.length()) a = "0" + a;
		while (a.length() < b.length()) a = "0" + a;
		while (b.length() < a.length()) b = "0" + b;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '-') a[i] = '0';
			if (b[i] == '-') b[i] = '0';
		}
		result = a;

		for (int i = result.length() - 1; i >= 0; i--) {
			sum = (result[i] - '0') + (b[i] - '0');
			temp = sum / 10;

			result[i] = sum % 10 + '0';
			if (temp > 0) {
				result = Biginteger_add(result, i);
			}
		}

		if(m_flag) result = "-" + result;

		BigInteger res = BigInteger(result);
		return res;
	}
	BigInteger operator - (const BigInteger& other) {
		string a = number, b = other.number, result = "0", sub_temp;
		int sub, temp, large;

		if (a[0] == '-' && b[0] != '-') {
			b = "-" + b;
			BigInteger temp1 = BigInteger(a);
			BigInteger temp2 = BigInteger(b);
			temp1 = temp1 + temp2;
			return temp1;
		}
		else if ((a[0] != '-' && b[0] == '-') || (a[0] == '-' && b[0] == '-')) {
			b[0] = '0';
			BigInteger temp1 = BigInteger(a);
			BigInteger temp2 = BigInteger(b);
			temp1 = temp1 + temp2;
			return temp1;
		}

		if (a.length() == b.length()) {
			temp = compare(a, b);
			if (temp == 0) large = 0;
			else if (temp == 1) large = 1;
			else if (temp == 2) {
				BigInteger res = BigInteger(result);
				return res;
			}
		}
		else if (a.length() > b.length()) large = 0;
		else large = 1;
		while (a.length() < b.length()) a = "0" + a;
		while (b.length() < a.length()) b = "0" + b;

		if (!large) {
			result = a;
			sub_temp = b;
		}
		else {
			result = b;
			sub_temp = a;
		}

		for (int i = result.length() - 1; i >= 0; i--) {
			if ((result[i] - '0') - (sub_temp[i] - '0') < 0) {
				result = Biginteger_sub(result, i);
				result[i] = 10 + (result[i] - '0') - (sub_temp[i] - '0') + '0';
			}
			else {
				result[i] = (result[i] - '0') - (sub_temp[i] - '0') + '0';
			}
		}
		if (large) result = '-' + result;

		BigInteger res = BigInteger(result);
		return res;
	}
	BigInteger operator * (const BigInteger& other) {
		string a = number, b = other.number, result = "";
		BigInteger res = BigInteger(result);
		BigInteger res_temp = BigInteger(result);
		int m = 0, temp;

		if ((a[0] == '-' || b[0] == '-') && (!(a[0] == '-' && b[0] == '-'))) m = 1;

		if (a.length() == b.length()) a = "0" + a;
		while (a.length() < b.length()) a = "0" + a;
		while (b.length() < a.length()) b = "0" + b;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '-') a[i] = '0';
			if (b[i] == '-') b[i] = '0';
		}

		result = a;

		for (int i = result.length() - 1, k = 0; i >= 0; i--, k++) {
			res_temp.number = "";
			for (int j = 0; j < b[i] - '0'; j++) {
				res_temp = res_temp + a;
			}
			for (int j = 0; j < k; j++)
				res_temp.number = res_temp.number + '0';

			res = res + res_temp;

		}
		if (m) res.number = '-' + res.number;

		return res;
	}

	void print() {
		int flag = 0, cnt=0;
		string result;

		for (int i = 0; i < this->number.length(); i++) {
			if (!flag) {
				if (this->number[i] == '0') continue;
				else if (this->number[i] == '-') result = "-";
				else {
					result = result + this->number[i];
					flag = 1;
				}
			}
			else result = result + this->number[i];
		}
		if (!flag) cout << '0';
		else cout << result;
	}
};



int compare(string a, string b) {
	for (int i = 0; i < a.length(); i++)
		if (a[i] > b[i]) return 0;
		else if (a[i] < b[i]) return 1;
	return 2;
}

string Biginteger_add(string d, int n) {
	if (d[n-1] - '0' + 1 > 9) {
		d[n - 1] = '0';
		d = Biginteger_add(d, n - 1);
	}

	else {
		d[n - 1] += 1;
	}
	return d;
}

string Biginteger_sub(string d, int n) {
	if (d[n - 1] == '0') {
		d = Biginteger_sub(d, n - 1);
		d[n - 1] = '9';
	}
	else {
		d[n - 1] -= 1;
	}
	return d;
}

int main() {
	string temp;
	BigInteger result;
	int i = 0;

	while (1) {
		cin >> temp;
		if (temp == "exit") break;
		BigInteger data1 = BigInteger(temp);
		cin >> temp;
		BigInteger data2 = BigInteger(temp);
		cin >> temp;

		if (temp == "add") {
			result = data1 + data2;
		}
		else if (temp == "sub") {
			result = data1 - data2;
		}
		else if (temp == "mul") {
			result = data1 * data2;
		}

		if (i != 0) cout << endl;
		else i = 1;
		result.print();
	}
	return 0;
}