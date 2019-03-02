#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long n, timer = 0;
vector<vector<long long>> arr, err;
vector<bool> used;
vector<long long> fup, tin, er, br;

void dfs(long long u, long long p) {
    used[u] = true;
    tin[u] = fup[u] = timer;
    ++timer;
    for (long long i = 0; i < arr[u].size(); ++i) {
        if (arr[u][i] == p) {
            continue;
        } else {
            if (used[arr[u][i]]) {
                fup[u] = min(fup[u], tin[arr[u][i]]);
            } else {
                dfs(arr[u][i], u);
                fup[u] = min(fup[u], fup[arr[u][i]]);
            }
            if (fup[arr[u][i]] > tin[u]) {
                br.push_back(err[u][i] + 1);
            }
        }
    }
}

int main() {
    long long m;
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
        err[x].push_back(i);
        err[y].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs(i, -1);
    }
    sort(br.begin(), br.end());
    cout << br.size() << endl;
    for (long long i : br) {
        cout << i << ' ';
    }
    return EXIT_SUCCESS;
}