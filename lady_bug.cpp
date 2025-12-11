#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    string a, b; cin >> a >> b;

    int even = 0, odd = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == '0') continue;
        if(i%2 == 0) even++;
        else odd++;
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == '1') continue;
        if(i%2 == 0) odd--;
        else even--;
    }

    if(odd <= 0 && even <= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}