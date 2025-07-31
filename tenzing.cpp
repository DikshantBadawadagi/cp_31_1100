#include <iostream>
#include <vector>
using namespace std;

bool canReachX(int n, int x, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    int knowledge = 0;
    vector<vector<int>> stacks = {a, b, c};

    for (const auto& stack : stacks) {
        for (int v : stack) {
            if ((v | x) == x) {
                knowledge |= v;
                if (knowledge == x) return true;
            } else {
                break; // Can't go further in this stack
            }
        }
    }

    return knowledge == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n), b(n), c(n);
        for (int& v : a) cin >> v;
        for (int& v : b) cin >> v;
        for (int& v : c) cin >> v;

        cout << (canReachX(n, x, a, b, c) ? "Yes" : "No") << '\n';
    }

    return 0;
}
