#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    vector<int> s(4);
    for(int i = 0; i < 4; i++) cin >> s[i];

    sort(s.begin(), s.end());

    if(s[0]+s[1] > s[2] || s[1]+s[2] > s[3]) {
        cout << "TRIANGLE" << endl;
    } else if(s[0]+s[1] == s[2] || s[1]+s[2] == s[3]) {
        cout << "SEGMENT" << endl;
    } else cout << "IMPOSSIBLE" << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}