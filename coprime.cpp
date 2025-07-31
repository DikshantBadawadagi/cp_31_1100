#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric> // for gcd
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1); // 1-based indexing
        vector<int> pos(1001, -1); // pos[val] = max index where val appeared

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]] = i; // only store the *last* index of each value
        }

        int ans = -1;

        for (int i = 1; i <= 1000; ++i) {
            if (pos[i] == -1) continue; // value i not in array

            for (int j = 1; j <= 1000; ++j) {
                if (pos[j] == -1) continue;

                if (gcd(i, j) == 1) {
                    ans = max(ans, pos[i] + pos[j]);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
