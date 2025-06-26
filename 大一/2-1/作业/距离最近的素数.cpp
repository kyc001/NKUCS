#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
int T, n;
vector<int> prime;
bool book[M];

int main() {
    book[1] = 1;
    for	(int i = 2; i < M; i++) {
        if (!book[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && prime[j] * i < M; j++) {
            book[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    prime.push_back(M+3);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n >= 1e6 || n <= 0) {
            cout << "INCORRECT INPUT!" << endl;
            continue;
        }
        auto id = lower_bound(prime.begin(), prime.end(), n);
        if(*id == n) cout << n << " 0" << endl;
        else {
            int ans = *id;
            if(id != prime.begin() && abs(n - *(id - 1)) <= abs(ans - n)) ans = *(id - 1);
            cout << ans << " " << abs(ans - n) << endl;
        }
    }
    return 0;
}