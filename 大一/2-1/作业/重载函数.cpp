#include <bits/stdc++.h>
using namespace std;

void oddFilter(int a[], int size) {
    int oddArray[size];
    int oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2!= 0) {
            oddArray[oddCount++] = a[i];
        }
    }
    if (oddCount == 0) {
        cout << "No Odd!" << endl;
    } else {
        sort(oddArray, oddArray + oddCount);
        for (int i = 0; i < oddCount; i++) {
            cout << oddArray[i] << " ";
        }
        cout << endl;
    }
}

void oddFilter(double a[], int size)
{
    int roundedArray[size];
    int oddCount = 0;
    for (int i = 0; i < size; i++)
    {
        int roundedValue = static_cast<int>(a[i] + 0.5);
        roundedArray[i] = roundedValue;
        if (roundedValue % 2 != 0)
        {
            roundedArray[oddCount++] = roundedValue;
        }
    }
    if (oddCount == 0)
    {
        cout << "No Odd!" << endl;
    }
    else
    {
        sort(roundedArray, roundedArray + oddCount);
        for (int i = 0; i < oddCount; i++)
        {
            cout << roundedArray[i] << " ";
        }
        cout << endl;
    }
}

void oddFilter(char a[], int size) {
    int charCount[256] = {0};
    for (int i = 0; i < size; i++) {
        charCount[a[i]]++;
    }
    bool foundOdd = false;
    for (int i = 0; i < 256; i++) {
        if (charCount[i] % 2!= 0) {
            cout << static_cast<char>(i) << " ";
            foundOdd = true;
        }
    }
    if (!foundOdd) {
        cout << "No Odd!" << endl;
    } else {
        cout << endl;
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    int intArray[M];
    double doubleArray[N];
    char charArray[1000];
    for (int i = 0; i < M; i++) {
        cin >> intArray[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> doubleArray[i];
    }
    cin >> charArray;
    oddFilter(intArray, M);
    oddFilter(doubleArray, N);
    oddFilter(charArray, strlen(charArray));
    return 0;
}