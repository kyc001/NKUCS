#include<bits/stdc++.h>
using namespace std;
const double pi = 3.14159;
class sphere {
public:
	double r;
	sphere(double R) : r(R){};
	double get_s() {
		return 4 * pi * r * r;
	}
	double get_v() {
		return 4.0 / 3.0 * pi * r * r * r;
	}
}; 
double r;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r;
	sphere c(r);

	printf("%.2lf %.2lf",c.get_s(), c.get_v());
	
	return 0;
}



