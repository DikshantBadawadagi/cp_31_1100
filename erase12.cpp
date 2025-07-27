#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> pref(n, 0);
        vector<bool> seen(26, false);
        int unique_count = 0;

        for(int i = 0; i < n; ++i) {
            if (!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                ++unique_count;
            }
            pref[i] = unique_count;
        }

        int sum = 0;
        for(int val : pref)
            sum += val;

        cout << sum << '\n';
    }
}
