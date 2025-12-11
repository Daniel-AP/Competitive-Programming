#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    string s; cin >> s;

    int ans = 1, temp = 1;

    for(int i = 1; i < s.length(); i++) {
        if(s[i-1] == s[i]) temp++;
        else {
            ans = max(ans, temp); 
            temp = 1;
        }
    }

    ans = max(ans, temp);

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}