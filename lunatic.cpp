#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll g = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] != a[n - i - 1]) {
                g = gcd(g, abs(a[i] - a[n - i - 1]));
            }
        }

        cout << g << '\n';
    }
    return 0;
}
