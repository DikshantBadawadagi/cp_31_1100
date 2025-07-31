#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        // Prefix sum array
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        long long ans = 0;

        for (int i = 0; i <= k; ++i) {
            int left = 2 * i;
            int right = k - i;

            if (left > n || n - right < left) continue;

            long long current_sum = prefix[n - right] - prefix[left];
            ans = max(ans, current_sum);
        }

        cout << ans << '\n';
    }

    return 0;
}
