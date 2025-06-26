#include<bits/stdc++.h>
using namespace std;

int n, length;

template <class T>
void Print(T *p, int n) {
	for(int i = 0; i < n; i ++) {
		cout << p[i] << ' ';
	}
	return;
}

template <class T>
void GtLever(T *p, int n, T lever) {
	int res = 0;
	for(int i = 0; i < n; i ++) {
		if(p[i] > lever) {
			swap(p[i], p[res]);
			res ++;
		}
	}
	Print(p, res);
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s >> length >> n;
	if(s == "char") {
		char* arr = new char[length];
		for(int i = 0; i < length; i ++) {
			cin >> arr[i];
		}
		char lever; 
		cin >> lever;
		GtLever(arr, n, lever);
		delete[] arr;
	}
	else if(s == "int") {
		int* arr = new int[length];
		for(int i = 0; i < length; i ++) {
			cin >> arr[i];
		}
		int lever;
		cin >> lever;
		GtLever(arr, n, lever);
		delete[] arr;
	}
	else {
		float* arr = new float[length];
		for(int i = 0; i < length; i ++) {
			cin >> arr[i];
		}
		float lever;
		cin >> lever;
		GtLever(arr, n, lever);
		delete[] arr;	
	}
	return 0;
}



