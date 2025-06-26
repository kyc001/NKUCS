#include<bits/stdc++.h>
using namespace std;
struct stu{
	double ma, ch, en;
	string num, name;
}a[110];
int n, op;
bool cmp(stu x, stu y) {
	if(op == 1) {
		if(x.ma == y.ma) return x.num < y.num;
		else return x.ma > y.ma;
	}
	else if(op == 2) {
		if(x.ch == y.ch) return x.num < y.num;
		else return x.ch > y.ch;
	}
	else if(op == 3) {
		if(x.en == y.en) return x.num < y.num;
		else return x.en > y.en;
	}
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].num >> a[i].name;
		cin >> a[i].ma >> a[i].ch >> a[i].en;
	}
	cin >> op;
	if(op != 1 && op != 2 && op != 3) {
		cout << "ERROR";
		return 0; 
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i ++) {
		cout << a[i].num << " " << a[i].name << endl;
	}
	return 0;
}
