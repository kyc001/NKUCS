#include<bits/stdc++.h>
using namespace std;
class rational {
public:
	int zi, mu;
	rational(int z, int m) {
		int d = abs(__gcd(z, m));
		if(d < 0 ) cout << d <<endl; 
		this->zi = z/d;
		this->mu = m/d;
	}
	rational operator +(const rational& b) const {
		rational res(zi*b.mu + mu*b.zi, mu*b.mu);
		return res;
	}
	rational operator -(const rational &b) const {
		rational res(zi*b.mu - mu*b.zi, mu*b.mu);
		return res;
	}
	friend rational operator *(const rational& a, const rational& b) {
		rational res(a.zi*b.zi, a.mu*b.mu);
		return res;
	}
	friend rational operator /(const rational &a, const rational& b) {
		rational res(a.zi*b.mu, a.mu*b.zi);
		return res;
	}
	rational operator ++(int) {
		rational res(zi + mu, mu);
		return res;
	} 
	rational operator =(rational &b) {
		swap(zi, mu);
		swap(b.zi, b.mu);
		return *this;
	}
	friend ostream &operator <<(ostream &out, const rational &b) {
		if(b.mu == 1) {
			out << b.zi;
			return out;
		}
		out << b.zi << "/" << b.mu;
		return out;
	}

}; 
int zi1, zi2, mu1, mu2;
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> zi1 >> mu1 >> zi2 >> mu2;
	rational r1(zi1, mu1), r2(zi2, mu2);
	cout << r1+r2 << endl;
	cout << r1-r2 << endl;
	cout << r1*r2 << endl;
	cout << r1/r2 << endl;
	cout << r1 ++ << " " << r2 ++ << endl;
	r1 = r2;
	cout << r1 << " " << r2 << endl; 
	return 0;
}



