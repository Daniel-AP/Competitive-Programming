#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string s; cin >> s;

        vector<int> cnt(n);

        int found = 0;

        for(int i = n-2; i >= 0; i++) {
            cnt[i] = cnt[i+1]+(s[i+1]=='1');
        }

        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1' && s[i+1] == '0') {
                if(cnt[i] == 0) found = 2;
                else found = max(found, 1LL);
            }
        }

        int k = 0;

        for(int i = 1; i < n; i++) {
            if(s[i] != s[i-1]) k++;
        }

        if(s[0] == '1') k++;

        cout << s.length()+k-found << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}