#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void fill(vector<long long> &a, long long n, long long start) {
    a.resize(n);
    a[0] = start;
    for (int i = 1; i < n; ++i)
        a[i] = (1103515245LL * a[i - 1] + 12345) % (1LL << 31);
}

long long find_k_number(vector<long long> &arr, long long pre_left, long long pre_right, long long k) {
    long long x = arr[(pre_left + pre_right) / 2];
    long long left = pre_left, right = pre_right;
    while (left <= right) {
        while (arr[left] < x)
            left++;
        while (arr[right] > x)
            right--;
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    if (pre_left <= k && k <= right)
        return find_k_number(arr, pre_left, right, k);
    if (left <= k && k <= pre_right)
        return find_k_number(arr, left, pre_right, k);
    return arr[k];
}

int main() {
    long long n, a0, k;
    cin >> n >> a0 >> k;
    vector<long long> arr(n);
    fill(arr, n, a0);
    cout << find_k_number(arr, 0, arr.size(), k + 1);
    return EXIT_SUCCESS;
}
