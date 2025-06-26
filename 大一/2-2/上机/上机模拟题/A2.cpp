#include<bits/stdc++.h>
using namespace std;
class employee {
public:
	double a;
	employee(double m) : a(m){};
	virtual double money()=0;
};
class manager : public employee {
public:
	manager() : employee(8000.0){};
	double money() {
		return a;
	}
};
class technician : public employee{
public:
	double t;
	technician(double T): employee(0), t(T){};
	double money() {
		return  a + t * 100; 
	}
};
class salesman : public employee {
public:
	double s;
	salesman(double S): employee(2000),s(S){};
	double money() {
		return a + s * 0.05; 
	}
};
int n, t, s;
char op; 
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	employee *p = 0;
	for(int i = 0; i < n; i ++) {
		cin >> op;
		if(op == 'm') {
			p = new manager();
			printf("%.2lf", (*p).money());
		}
		else if(op == 't') {
			cin >> t;
			p = new technician(t);
			printf("%.2lf", (*p).money());
		}
		else if(op == 's') {
			cin >> s;
			p = new salesman(s);
			printf("%.2lf", (*p).money());
		}
		cout << endl;
	} 

	return 0;
}



