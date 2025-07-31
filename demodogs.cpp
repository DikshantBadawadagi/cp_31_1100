#include <bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;

ll modmul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

void solve() {
    ll n;
    cin >> n;

    ll part1 = modmul(n, n + 1);
    ll part2 = modmul(part1, 4 * n - 1);
    ll ans = modmul(part2, 337);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); // important for large inputs
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
