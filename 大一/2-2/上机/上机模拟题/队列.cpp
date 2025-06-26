#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = 20;
template<typename T>
class myqueue{
public:
	T* p;
	int h=0, t=0, num=0;
	myqueue(T array[], int len) {
		p = new T[MAXLEN];
		for(int i = 0; i < len; i ++) {
			p[i] = array[i];
		}
		t = len - 1;
		num = len;
	} 
	~myqueue() {
		delete[] p;
	}
	void push(const T& value) {
		if(num == MAXLEN) {
			h = (h + 1) % MAXLEN; 
			t = (t + 1) % MAXLEN;
			p[t] = value;
			return; 
		}
		num ++;
		t = (t + 1) % MAXLEN;
		p[t] = value;
		return;
	}
	T pop() {
		h = (h + 1) % MAXLEN;
		num --;
		return p[h];
	}
	bool empty() {
		return num == 0;
	}
	int count() {
		return num;
	}
	void show() {
		for(int i = 0; i < num; i ++) {
			cout << p[(h + i) % MAXLEN] << ' ';
		}
		cout << "size:" << num << endl;
	}
	void clear() {
		h = t = 0;
		num = 0;
		p = 0;
	}
}; 
char op;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int iarray[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	char carray[21] = "this_is_a_teststring";
	
	myqueue<int> q1(iarray, 12);
	while(cin >> op) {
		if(op == 's') {
			break;
		}
		else if(op == 'd') {
			if(!q1.empty())
				q1.show();
			else
				cout << "None" << endl;
		}
		else if(op == 'i') {
			int temp;
			cin >> temp;
			q1.push(temp);
		}
		else if(op == 'o') {
			int x;
			cin >> x;
			if(x > q1.count())
				cout << "None" << endl;
			else {
				for(int i = 0; i < x; i ++) {
					q1.pop();
				}
			} 
		}
	}
	
	myqueue<char> q2(carray, 20);
	while(cin >> op) {
		if(op == 's') {
			break;
		}
		else if(op == 'd') {
			if(!q2.empty())
				q2.show();
			else
				cout << "None" << endl;
		}
		else if(op == 'i') {
			char temp;
			cin >> temp;
			q2.push(temp);
		}
		else if(op == 'o') {
			int x;
			cin >> x;
			if(x > q2.count())
				cout << "None" << endl;
			else {
				for(int i = 0; i < x; i ++) {
					q2.pop();
				}
			} 
		}
	}
	
	return 0;
} 