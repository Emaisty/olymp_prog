#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


long long n, timer = 0;
vector<vector<long long>> arr, err;
vector<bool> used;
vector<long long> fup, tin, er;
set<long long> br;

void dfs(long long v, long long p) {
    used[v] = true;
    tin[v] = fup[v] = timer;
    ++timer;
    int chl = 0;
    for (long long i = 0; i < arr[v].size(); ++i) {
        if (arr[v][i] == p) {
            continue;
        } else {
            if (used[arr[v][i]]) {
                fup[v] = min(fup[v], tin[arr[v][i]]);
            } else {
                dfs(arr[v][i], v);
                fup[v] = min(fup[v], fup[arr[v][i]]);
                if (fup[arr[v][i]] >= tin[v] && p != -1) {
                    br.insert(v + 1);
                }
                chl++;
            }

        }
    }
    if (p == -1 && chl > 1)
        br.insert(v + 1);
}

int main() {
    long long m;
    //freopen("points.in", "r", stdin);
    cin >> n >> m;
    for (long long i = 0; i < n; ++i) {
        arr.push_back(er);
        err.push_back(er);
        used.push_back(false);
        fup.push_back(0);
        tin.push_back(0);
    }
    for (long long i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        x--;
        y--;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs(i, -1);
    }
    //freopen("points.out", "w", stdout);
    cout << br.size() << endl;
    for (long long i : br) {
        cout << i << ' ';
    }
    return EXIT_SUCCESS;
}