#include<bits/stdc++.h>
using namespace std;
const string s0 = "1234567890";
const int l = 10;
class String{
public:
	char s[1010];
	int len;
	string get() {
		return s;
	}
	int get_size() {
		return len;
	}
};
class EditableString : public String {
public:
	EditableString(int l) {
		for(int i = 0; i < 10; i ++) {
			this -> s[i] = s0[i];
		}
		this->len = 10;
	}
	void insertt(int index, char ch) {
		if(index > len + 1 || index < 1) return;
		for(int i = len; i >= index; i --) {
			s[i] = s[i - 1];
		}
		s[index - 1] = ch;
		len ++;
	}
	void deletee(int index) {
		if(index > len || index < 1) return;
		for(int i = index - 1; i < len; i ++) {
			s[i] = s[i + 1];
		}
		len --; 
	}
	void replace(int index, char ch) {
		if(index > len || index < 1) return;
		s[index - 1] = ch;
	}
	friend ostream&  operator <<(ostream& out, EditableString a) {
		for(int i = 0; i < a.len; i ++) {
			out << a.s[i];
		}
		return out;
	} 
};
int id;
char op, c;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	EditableString a(l);
	while(1) {
		cin >> op; 
		if(op == 'i') {
			cin >> id >> c;
			a.insertt(id, c);
		}
		else if(op == 'd') {
			cin >> id;
			a.deletee(id);
		}
		else if(op == 'r') {
			cin >> id >> c;
			a.replace(id, c);
		}
		else {
			break;
		}
		cout << a.s << endl;
	}
	return 0;
}



