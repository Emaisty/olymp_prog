#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long q;
    double r;
    cin >> q;
    for (long long j = 0, c, t, R, L, M; j < q; ++j) {
        cin >> c >> t;
        L = 1;
        R = 1000000000000;
        while (R - L > 1) {
            M = (R + L) / 2;
            r = ceil(log2(M) * c * M);
            if (r > t)
                R = M;
            else
                L = M;
        }
        cout << L << endl;
    }
    return EXIT_SUCCESS;
}