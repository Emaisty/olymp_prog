#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int main() {
    int a, b, s1 = 0, s2 = 0, c1 = 0, c2 = 0;
    cin >> a >> b;
    vector<vector<int>> arr(a + b, vector<int>(4));
    for (int i = 0, x, y = 0; i < a; ++i) {
        cin >> x;
        arr[i][0] = y;
        arr[i][1] = y + x;
        y += x;
        arr[i][2] = 1;

    }
    for (int i = 0, x, y = 0; i < b; ++i) {
        cin >> x;
        arr[i + a][0] = y;
        arr[i + a][1] = y + x;
        y += x;
        arr[i][2] = 2;
    }

    sort(arr.begin(), arr.end(), cmp);
    vector<int> r, t;
    for (int i = 0, x = 0; i < a + b; ++i) {
        if (arr[i][2] == 2)
            s1++;
        else
            s2++;
        if (arr[i][0] >= x) {
            if (arr[i][2] == 2) {
                c1++;
                r.push_back(s1);
            } else {
                c2++;
                t.push_back(s2);
            }
            x = arr[i][1];
        }

    }
    cout << c1 << ' ' << c2 << endl;
    for (int i = 0; i < c1; ++i) {
        cout << r[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < c2; ++i) {
        cout << t[i] << ' ';
    }

    return EXIT_SUCCESS;
}