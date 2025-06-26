#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 20;

int n;
char a[N][N];

int min(int a, int b) {
    return a < b ? a : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int op = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n / 2; i ++) {
        for(int j = 1; j <= n / 2; j ++) {
            int sum = a[i][j] + a[j][n + 1 - i] + a[n + 1 - j][n + 1 - i] + a[n + 1 - j][i] - 4 * '0';
            op += min(sum, 4 - sum);
        }
    }
    
    if(n % 2) {
        for(int i = 1; i <= n / 2; i ++) {
            int sum = a[i][n / 2 + 1] + a[n / 2 + 1][n + 1 - i] + a[n + 1 - i][n / 2 + 1] + a[n / 2 + 1][i] - 4 * '0';
            op += min(sum, 4 - sum);
        }
    }

    cout << op << endl;

    return 0;
}
/*
7
1110000
1111000
1110000
0000000
0001000
0000001
0000011
*/