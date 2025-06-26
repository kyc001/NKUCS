#include<bits/stdc++.h>
using namespace std;
class Complex {
public:
	int real, im;
	Complex() : real(), im(){};
	Complex(int r, int i) : real(r), im(i){};
	friend Complex operator+ (const Complex &a, const Complex &b) {
		Complex c;
		c.real = a.real + b.real;
		c.im = a.im + b.im;
		return c; 
	}
	Complex operator- (const Complex &b) {
		Complex c;
		c.real = real - b.real;
		c.im = im - b.im;
		return c; 
	}
	Complex operator* (const Complex &b) const  {
		Complex c;
		c.real = real * b.real - im* b.im;
		c.im = real * b.im + im * b.real;
		return c;
	}
	friend ostream &operator <<(ostream& out, const Complex &c) {
		if(c.real == 0 && c.im == 0) {
			out << 0;
		} 
		else if(c.real == 0) {
			out << c.im << 'i';
		}
		else if(c.im == 0) {
			out << c.real;
		}
		else {
			out << c.real << '+' << c.im << 'i';
		}
		return out;
	}
};
int r, i;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> r >> i;
	Complex c1(r, i);
	cin >> r >> i;
	Complex c2(r, i);
	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 * c2 << endl;
	return 0;
}



