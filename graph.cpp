#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector<vector<ll>> arr(200000, vector<ll>());

vector<ll> color;

bool flag;

ll g = 0;

vector<vector<ll>> err(200000, vector<ll>());

void dl(ll a, ll c) {
    color[a]--;
    /*for (int i = 0; i < color.size(); ++i) {
        cout << color[i] << ' ';
    }
    cout << endl;*/
    for (int i = 0; i < arr[a].size(); ++i) {
        if (arr[a][i] != c)
            dl(arr[a][i], a);
    }
}

void df(ll o) {
    /*cout << "-----" << endl;
    for (int i = 0; i < err[o].size(); ++i) {
        cout << err[o][i] << ' ';
    }
    cout << endl;
    cout << "------" << endl;*/
    for (int i = 1; i < err[o].size() - 1; ++i) {
        //cout << err[i] << endl;
        color[err[o][i]]--;
        /*for (int i = 0; i < color.size(); ++i) {
            cout << color[i] << ' ';
        }
        cout << endl;*/
        for (int j = 0; j < arr[err[o][i]].size(); ++j) {
            if (arr[err[o][i]][j] != err[o][i - 1] && arr[err[o][i]][j] != err[o][i + 1]) {
                dl(arr[err[o][i]][j], err[o][i]);
            }
        }
    }
}

ll dfs(ll a, ll b, ll c) {
    for (int i = 0; i < g; ++i) {
        /*for (int i = 0; i < g; ++i) {
            for (int j = 0; j < err[i].size(); ++j) {
                cout << err[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;*/
        for (int j = 0; j < arr[err[i][err[i].size() - 1]].size(); ++j) {
            if (arr[err[i][err[i].size() - 1]][j] == b) {
                err[i].push_back(b);
                df(i);
                return 0;
            } else {
                if (err[i].size() == 1) {
                    for (int k = 0; k < err[i].size(); ++k) {
                        err[g].push_back(err[i][k]);
                    }
                    err[g].push_back(arr[err[i][err[i].size() - 1]][j]);
                    g++;

                } else {
                    if (arr[err[i][err[i].size() - 1]][j] != err[i][err[i].size() - 2]) {
                        for (int k = 0; k < err[i].size(); ++k) {
                            err[g].push_back(err[i][k]);
                        }
                        err[g].push_back(arr[err[i][err[i].size() - 1]][j]);
                        g++;
                    }
                }
            }
        }
    }
    dfs(a, b, c);
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        x--;
        y--;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    cin >> m;
    for (int i = 0; i < n; ++i) {
        color.push_back(m);
    }
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        for (int j = 0; j < g; ++j) {
            err[j].clear();
        }
        g = 0;
        flag = 1;
        err[g].push_back(x - 1);
        g = 1;
        dfs(x - 1, y - 1, x - 1);
        /*cout << '1' << endl;
        for (int i = 0; i < n; ++i) {
            cout << color[i] << ' ';
        }
        cout << endl;*/
    }
    ll max = 0;
    for (int i = 0; i < n; ++i) {
        //cout << color[i] << ' ';
        if (color[i] > max)
            max = color[i];
    }
    //cout << endl;
    cout << max;
    return 0;
}