#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int flag = 0;
vector<vector<int>> arr, trr;
vector<int> color;
int y;


void dfs(int a, int cl, int h) {
    if (h == 1)
        color[a] = (cl + 1) % 3;
    else {
        if (cl == 0)
            color[a] = 2;
        else
            color[a] = (cl - 1) % 3;
    }
    for (int i = 0; i < arr[a].size(); ++i) {
        if (trr[a][i] == 1 && i < arr[a].size()) {
            if (color[arr[a][i]] == -1 && i < arr[a].size())
                dfs(arr[a][i], color[a], 1);
            else {
                if ((color[arr[a][i]] == color[a] || (color[a] + 1) % 3 != color[arr[a][i]]) && i < arr[a].size() &&
                    trr[a][i] == 1)
                    flag++;
            }
        } else {
            if (color[arr[a][i]] == -1 && i < arr[a].size())
                dfs(arr[a][i], color[a], 2);
            else {
                if (i < arr[a].size()) {
                    if (color[a] == 0 && i < arr[a].size())
                        y = 3;
                    else
                        y = color[a];
                    if ((color[arr[a][i]] == color[a] || (y - 1) % 3 != color[arr[a][i]]) && trr[a][i] == 2)
                        flag++;
                }
            }
        }
    }
}


int main() {
    int n, m;
    vector<int> err;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        arr.push_back(err);
        trr.push_back(err);
        color.push_back(-1);
    }
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        if (x == y) {
            cout << "NO";
            return EXIT_SUCCESS;
        }
        x--;
        y--;
        arr[x].push_back(y);
        trr[x].push_back(1);
        arr[y].push_back(x);
        trr[y].push_back(2);
    }
    dfs(0, 2, 1);
    if (flag != 0)
        cout << "NO";
    else {
        cout << "YES" << endl;
        vector<int> a, b, c;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0 || color[i] == -1)
                a.push_back(i);
            else {
                if (color[i] == 1)
                    b.push_back(i);
                else
                    c.push_back(i);
            }
        }
        cout << a.size() << ' ';
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] + 1 << ' ';
        }
        cout << endl;
        cout << b.size() << ' ';
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i] + 1 << ' ';
        }
        cout << endl;
        cout << c.size() << ' ';
        for (int i = 0; i < c.size(); ++i) {
            cout << c[i] + 1 << ' ';
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}