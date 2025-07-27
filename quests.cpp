#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        long long ans = 0;
        long long sum = 0;
        int max_b = 0;

        // Try doing first i quests once (i from 1 to min(n, k))
        for (int i = 0; i < min(n, k); ++i) {
            sum += a[i];
            max_b = max(max_b, b[i]);

            long long remaining = k - (i + 1); // remaining steps
            long long curr_exp = sum + remaining * 1LL * max_b;
            ans = max(ans, curr_exp);
        }

        cout << ans << "\n";
    }
}
