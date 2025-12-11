#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    string s; cin >> s;
    int n = s.length();

    vector<int> cntr(26);

    for(int i = 0; i < n; i++) {
        cntr[s[i]-'A']++;
    }

    int odd(0), even(0);

    for(int i = 0; i < 26; i++) {
        if(cntr[i] == 0) continue;
        if(cntr[i]%2 == 0) even++;
        else odd++;
    }

    if(odd > 1) cout << "NO SOLUTION" << endl;
    else {
        string k, ans;
        for(int i = 0; i < 26; i++) {
            if(cntr[i]%2 == 1) continue;
            for(int j = 0; j < cntr[i]/2; j++) k += (char)('A'+i);
        }
        ans += k;
        for(int i = 0; i < 26; i++) {
            if(cntr[i]%2 == 0) continue;
            for(int j = 0; j < cntr[i]; j++) ans += (char)('A'+i);
        }
        reverse(k.begin(), k.end());
        ans += k;
        cout << ans << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}