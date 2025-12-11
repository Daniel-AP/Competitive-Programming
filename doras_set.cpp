#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t;
    cin >> t;

    while(t--) {

        int l, r;
        cin >> l >> r;

        int i = l;
        int count = 0;

        while(i <= r) {
            if(i%2 == 0) i++;
            else {
                count += (i+2 <= r);
                i += 4;
            }
        }

        cout << count << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}