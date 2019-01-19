#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool c(vector<long long> a, vector<long long> b) {
    if (b[1] == a[1]) {
        return a[0] < b[0];
    } else {
        return a[1] < b[1];
    }
}

int main() {
    int a, b, c1 = 0, c2 = 0;
    cin >> a >> b;
    vector<vector<long long>> arr(a + b, vector<long long>(4));
    for (long long i = 0, x, t = 0; i < a; ++i) {
        cin >> x;
        arr[i][0] = t;
        t += x;
        arr[i][1] = t;
        arr[i][2] = 1;
        arr[i][3] = i;
    }
    for (long long j = a, x, t = 0; j < a + b; ++j) {
        cin >> x;
        arr[j][0] = t;
        t += x;
        arr[j][1] = t;
        arr[j][2] = 2;
        arr[j][3] = j - a;
    }
    sort(arr.begin(), arr.end(), c);
    long long timer = 0;
    vector<int> x, y;
    for (int i = 0; i < a + b; ++i) {
        if (timer <= arr[i][0]) {
            timer = arr[i][1];
            if (arr[i][2] == 1) {
                x.push_back(arr[i][3]);
                c1++;
            } else {
                y.push_back(arr[i][3]);
                c2++;
            }
        }
    }
    cout << c1 << ' ' << c2 << endl;
    if (c1 != 0) {
        for (int i = 0; i < c1; ++i) {
            cout << x[i] + 1 << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < c2; ++i) {
        cout << y[i] + 1 << ' ';
    }
    return EXIT_SUCCESS;
}