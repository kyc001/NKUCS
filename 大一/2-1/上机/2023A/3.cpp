#include<bits/stdc++.h>
using namespace std;
char ch;
int r, g, b;
float c, m, y, k;
char d(int x) {
    if(x < 10) return x + '0';
    else return x - 10 + 'a';
}
string trans(int x) {
    string res = "";
    res = d(x%16) + res;
    x /= 16;
    res = d(x%16) + res;
    return res;
}
void Color2Hex(int r, int g, int b) {
    cout << "#";
    cout << trans(r) << trans(g) << trans(b) << endl;
    return;
}
void Color2Hex(float c, float m, float y, float k) {
    int r = (int) 255.0*(1.0-c)*(1.0-k);
    int g = (int) 255.0*(1.0-m)*(1.0-k);
    int b = (int) 255.0*(1.0-y)*(1.0-k);
    Color2Hex(r, g, b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ch;
    if(ch == 'r' || ch == 'R') {
        cin >> r >> g >> b;
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            cout << "Wrong Input!" << endl;
            return 0;
        }
        Color2Hex(r, g, b);
    }
    else if(ch == 'c' || ch == 'C') {
        cin >> c >> m >> y >> k;
        if(c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1) {
            cout << "Wrong Input!" << endl;
            return 0;
        }
        Color2Hex(c, m, y, k);
    }
    else {
        cout << "Wrong Input!" << endl;
        return 0;
    }
    return 0;
}