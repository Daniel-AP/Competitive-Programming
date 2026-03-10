#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int free = 0, desc = 0;
    set<int> cur;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') free++;
        else {
            if(free) {
                cur.insert(i+1);
                desc += i+1;
                free--;
            } else if(!cur.empty()) {
                desc -= *cur.begin();
                free++;
                desc += i+1;
                cur.erase(*cur.begin());
                cur.insert(i+1);
            } else {
                free++;
            }
        }
    }

    cout << n*(n+1)/2-desc << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}