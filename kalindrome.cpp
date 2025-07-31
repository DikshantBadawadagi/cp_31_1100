#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            l++; r--;
        } else {
            if (a[l] == x) {
                l++;
            } else if (a[r] == x) {
                r--;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool is_kalindrome(const vector<int>& a) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            l++; r--;
        } else {
            return is_palindrome(a, a[l]) || is_palindrome(a, a[r]);
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        cout << (is_kalindrome(a) ? "YES" : "NO") << '\n';
    }
    return 0;
}
