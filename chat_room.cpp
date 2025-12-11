#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    string s; cin >> s;
    string h = "hello";

    int i = 0;
    for(int j = 0; j < s.length(); j++) {
        if(s[j] == h[i]) i++;
        if(i == 5) break;
    }

    cout << (i == 5 ? "YES" : "NO") << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}