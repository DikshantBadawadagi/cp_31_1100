#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll manhattan(pair<ll, ll>& a, pair<ll, ll>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--, b--; // convert to 0-based index

        vector<pair<ll, ll>> cities(n);
        for (int i = 0; i < n; ++i) {
            cin >> cities[i].first >> cities[i].second;
        }

        // Base cost: direct flight
        ll min_cost = manhattan(cities[a], cities[b]);

        // If no major cities, that's the only option
        if (k == 0) {
            cout << min_cost << '\n';
            continue;
        }

        // Find min distance from a → any major, and b → any major
        ll min_from_a = LLONG_MAX;
        ll min_from_b = LLONG_MAX;

        for (int i = 0; i < k; ++i) {
            min_from_a = min(min_from_a, manhattan(cities[a], cities[i]));
            min_from_b = min(min_from_b, manhattan(cities[b], cities[i]));
        }

        // Cost via major network
        ll via_major = min_from_a + min_from_b;

        cout << min(min_cost, via_major) << '\n';
    }

    return 0;
}
