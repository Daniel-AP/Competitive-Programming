#include <bits/stdc++.h>
using namespace std;

void solve() {

    int t;
    cin >> t;

    while(t--) {

        int n, k;
        cin >> n >> k;

        long long prod = 1;
        for(int i = 0; i < n; i++) {
            int f; cin >> f;
            prod *= f;
        }
        
        if(2023%prod == 0) {
            cout << "YES" << endl;
            cout << 2023/prod << " ";
            for(int i = 1; i < k; i++) cout << 1 << " ";
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}