#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int color[200000], ma = 0;
vector<vector<int>> arr(200000, vector<int>());

void cl(int a, vector<int> &err) {
    for (int i = 0; i < arr[a].size(); ++i) {
        err.push_back(color[arr[a][i]]);
    }
}

void df(int a) {
    vector<int> err;
    for (int i = 0; i < arr[a].size(); ++i) {
        err.push_back(color[arr[a][i]]);
        cl(arr[a][i], err);
    }
    sort(err.begin(), err.end());
    int u = 1;
    for (int i = 0; i < err.size(); ++i) {
        if (err[i] == u)
            u++;
    }
    if (u > ma)
        ma = u;
    color[a] = u;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        x--;
        y--;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for (int i = 0; i < 200000; ++i) {
        color[i] = 0;
    }
    color[0] = 1;
    df(2);
    for (int i = 1; i < n; ++i) {
        if (i != 2)
            df(i);
    }
    cout << ma << endl;
    for (int i = 0; i < n; ++i) {
        cout << color[i] << ' ';
    }
    return EXIT_SUCCESS;
}