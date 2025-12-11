#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    vector<int> cntS(26), cntT(26);

    for(int i = 0; i < n; i++) cntS[s[i]-'a']++;
    for(int i = 0; i < m; i++) cntT[t[i]-'a']++;
    
    for(int i = 0; i < 26; i++) {
        if(cntS[i] > cntT[i]) return void(cout << "Impossible" << '\n');
    }

    multiset<char> ms;

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < cntT[i]-cntS[i]; j++) ms.insert('a'+i);
    }

    for(int i = 0; i < n; i++) {
        while(!ms.empty() && *ms.begin() < s[i]) {
            cout << *ms.begin();
            ms.erase(ms.begin());
        }
        cout << s[i];
    }

    for(char ch: ms) cout << ch;
    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}