#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, count;
    cin >> n >> a;
    vector<int> arr;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            arr.push_back(i);
            if (i != n / i)
                arr.push_back(n / i);
        }
    }
    if (arr.size() < a)
        cout << -1;
    else {
        sort(arr.begin(), arr.end());
        cout << arr[a-1];
    }
    return EXIT_SUCCESS;
}