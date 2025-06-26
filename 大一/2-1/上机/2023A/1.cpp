#include<bits/stdc++.h>
using namespace std;
int maxx = INT_MIN, minn = INT_MAX, sum,a[20], len;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
        sum += a[i];
    }
    cin >> s;
    len = s.size();
    for(int i = 0; i < len; i ++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    cout << maxx << " " << minn << " " << sum << endl;
    cout << s;
    return 0;
}