#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < 26; i++) {
        if(s.find(char('a'+i)) == string::npos) return void(cout << char('a'+i) << '\n');
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            string ss; ss += char('a'+i), ss += char('a'+j);
            if(s.find(ss) == string::npos) return void(cout << ss << '\n');
        }
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            for(int k = 0; k < 26; k++) {
                string ss;
                ss += char('a'+i), ss += char('a'+j), ss += char('a'+k);
                if(s.find(ss) == string::npos) return void(cout << ss << '\n');
            }
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}