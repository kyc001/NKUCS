#include<bits/stdc++.h>
using namespace std;

template<typename T>
class C1{
public:
	int num;
	T* a;
	C1(int n) {
		num = n;
		a = new T[num];
	}
	~C1() {
		delete[] a;
	}
	void In() {
		for(int i = 0; i < num; i ++) {
			cin >> a[i];
		}
	}
	void Sort() {
		for(int i = 0; i < num-1; i ++) {
			for(int j = i + 1; j < num; j ++) {
				if(a[j] < a[i])
					swap(a[j], a[i]);
			}
		}
	}
	void Out() {
		for(int i = 0; i < num; i ++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
};
int n;
template<typename T1>
void solve(int num) {
	C1<T1> c1(num);
	c1.In();
	c1.Sort();
	c1.Out();
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 0; i < 3; i ++) {
		cin >> n;
		if(i == 0) {
			solve<int>(n); 
		}
		else if(i == 1) {
			solve<char>(n);
		}
		else {
			solve<string>(n);
		}
	}
	return 0;
}
