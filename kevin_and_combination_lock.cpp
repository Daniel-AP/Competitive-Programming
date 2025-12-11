#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        string x; cin >> x;
        int y = stoll(x);

        bool can = y%33 == 0;
        int i = 1;

        while(i < x.length()) {
            if(x[i-1] == '3' && x[i] == '3') {
                x.erase(i-1, 2);
                if(x.length()) y = stoll(x);
                i--;
            } else {
                i++;
            }
            if(y%33 == 0) can = true;
        }

        if(can) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}