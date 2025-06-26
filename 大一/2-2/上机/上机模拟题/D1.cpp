#include<bits/stdc++.h>
using namespace std;
class Vec{
private:
    double x, y;
public:
    Vec() : x(0), y(0) {}
    Vec(double a, double b) : x(a), y(b){}
    Vec operator+ (const Vec& b) {
        Vec c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }
    Vec operator* (const int& b) {
        Vec c;
        c.x = b*x;
        c.y = b*y;
        return c;
    }// v * s
    friend Vec operator* (const int& a, const Vec& b) {
        Vec c;
        c.x = a * b.x;
        c.y = a * b.y;
        return c;
    }// s * v
    friend double operator* (const Vec& a, const Vec& b) {
        return a.x * b.x + a.y * b.y;
    }// v1 * v2
    friend ostream& operator<< (ostream& out, const Vec& b) {
        out << '(' << b.x << ',' << b.y << ')';
        return out;
    }
};
double x, y, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> x >> y;
    Vec v1(x, y);
    cin >> x >> y;
    Vec v2(x, y);
    cin >> s;

    cout << v1 + v2 << endl;
    cout << v1 * s << endl;
    cout << v1 * v2 << endl;

    return 0;
}