#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int maxi =(1<<30) -1;
        for(int i=0;i<n;i++){
            if(a[i] != i)
                maxi &= a[i];
        }
        cout << maxi << endl;
    }
}