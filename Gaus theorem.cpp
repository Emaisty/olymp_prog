#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    int a;
    double h, t;
    cin >> a;
    Point arr[a + 1];
    for (int i = 0; i < a; ++i) {
        cin >> arr[i].x >> arr[i].y;
        if (i == 0) {
            h = arr[i].x;
            t = arr[i].y;
        }
    }
    arr[a].x = h;
    arr[a].y = t;
    double an1 = 0, an2 = 0;
    for (int i = 0; i < a; ++i) {
        an1 += (arr[i].x * arr[i + 1].y);
    }
    for (int i = 1; i < a + 1; ++i) {
        an2 += (arr[i].x * arr[i - 1].y);
    }
    double ans;
    ans = abs(an1 - an2);
    cout << fixed << setprecision(3) << ans / 2;
    return EXIT_SUCCESS;
}