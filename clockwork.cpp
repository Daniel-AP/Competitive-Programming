#include <bits/stdc++.h>
using namespace std;

void solve() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        string ans = "YES";

        for(int i = 0; i < n; i++) {
            int m = 2*(max(n-i-1, i));
            int a; cin >> a;
            if(a <= m) ans = "NO";
        }
        
        cout << ans << endl;

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}