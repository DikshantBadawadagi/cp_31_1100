#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<long long>& nums, long long x, long long h) {
    long long total = 0;
    for (auto a : nums) {
        total += max(0LL, h - a);
        if (total > x) return false;
    }
    return true;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        vector<long long> nums(n);
        for (long long i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long l = 1;
        long long r = *max_element(nums.begin(), nums.end()) + x;
        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (isPossible(nums, x, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
