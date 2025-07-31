#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            prefix[i + 1] = prefix[i] + a[i];
        }

        ll max_diff = 0;

        // Find all divisors of n
        vector<int> divisors;
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                divisors.push_back(k);
                if (k != n / k)
                    divisors.push_back(n / k);
            }
        }

        for (int k : divisors) {
            ll max_sum = LLONG_MIN, min_sum = LLONG_MAX;

            for (int i = 0; i < n; i += k) {
                ll group_sum = prefix[i + k] - prefix[i];
                max_sum = max(max_sum, group_sum);
                min_sum = min(min_sum, group_sum);
            }

            max_diff = max(max_diff, abs(max_sum - min_sum));
        }

        cout << max_diff << '\n';
    }

    return 0;
}
