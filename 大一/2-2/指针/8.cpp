#include<bits/stdc++.h>
using namespace std;

void sortDescending(int *arr, int n) {
    sort(arr, arr + n);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sortDescending(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[n-1-i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}