#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        if(n%2 == 0) {
            cout << -1 << endl;
            continue;
        }

        vector<int> ans;
        
        while(n != 1) {
            if(((n-1)/2)%2 == 1) {
                n = (n-1)/2;
                ans.push_back(2);
            }
            else {
                n = (n+1)/2;
                ans.push_back(1);
            }
        }

        cout << ans.size() << endl;
        for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}