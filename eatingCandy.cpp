#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    int l = 0, r = n - 1;
    long long left_sum = w[l], right_sum = w[r];
    int max_candies = 0;

    while (l < r) {
        if (left_sum == right_sum) {
            // Update max candies eaten so far
            max_candies = max(max_candies, (l + 1) + (n - r));
        }

        if (left_sum <= right_sum) {
            ++l;
            left_sum += w[l];
        } else {
            --r;
            right_sum += w[r];
        }
    }

    cout << max_candies << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
