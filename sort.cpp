#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), a_prime(n);
        for (int &x : a) cin >> x;
        for (int &x : a_prime) cin >> x;

        int l = 0, r = n - 1;

        // Find the first and last positions where a and a' differ
        while (l < n && a[l] == a_prime[l]) l++;
        while (r >= 0 && a[r] == a_prime[r]) r--;

        // Expand left
        while (l > 0 && a[l - 1] <= a_prime[l]) {
            l--;
        }

        // Expand right
        while (r + 1 < n && a[r + 1] >= a_prime[r]) {
            r++;
        }

        cout << l + 1 << ' ' << r + 1 << '\n'; // 1-based indexing
    }
    return 0;
}
