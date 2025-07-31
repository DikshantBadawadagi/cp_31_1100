#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long abs_sum = 0;
        int neg_count = 0;
        int min_abs = INT_MAX;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            abs_sum += abs(a[i]);
            if (a[i] < 0) neg_count++;
            min_abs = min(min_abs, abs(a[i]));
        }

        if (neg_count % 2 == 0) {
            cout << abs_sum << '\n';
        } else {
            cout << abs_sum - 2 * min_abs << '\n';
        }
    }

    return 0;
}
