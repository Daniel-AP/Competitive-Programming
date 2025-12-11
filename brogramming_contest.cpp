#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string s; cin >> s;

        if(s.find('1') == string::npos){
            cout << 0 << endl;
            continue;
        }
        if(s.find('0') == string::npos){
            cout << 1 << endl;
            continue;
        }
        
        int segments = 0;
        for (int i = 0; i < n - 1; i++){
            if(s[i] != s[i+1]) segments++;
        }
        
        int ans = segments + (s[0] == '1' ? 1 : 0);
        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}