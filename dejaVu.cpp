#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> x(q);
        for (int &v : x) cin >> v;

        int min_x = 31;  // Start larger than any possible xi (since 1 ≤ xi ≤ 30)

        for (int i = 0; i < q; ++i) {
            if (x[i] < min_x) {
                int add_val = 1 << (x[i] - 1); // 2^(xi - 1)
                for (int j = 0; j < n; ++j) {
                    if ((a[j] % (1 << x[i])) == 0) {
                        a[j] += add_val;
                    }
                }
                min_x = x[i];
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
