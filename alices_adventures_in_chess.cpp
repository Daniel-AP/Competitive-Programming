#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        int x = 0, y = 0;
        bool can = false;

        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < n; j++) {
                if(x == a && y == b) can = true;
                if(s[j] == 'N') y++;
                if(s[j] == 'E') x++;
                if(s[j] == 'S') y--;
                if(s[j] == 'W') x--;
            }
            if(x == a && y == b) can = true;
        }

        cout << (can ? "YES" : "NO") << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}