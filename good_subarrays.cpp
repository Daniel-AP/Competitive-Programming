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

    int ans = 0;

    int curval = 0, curpos = 0;
    map<int, int> cnt;
    cnt[0]++;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') curval--;
        else curval += (s[i]-'0');
        curpos += (s[i]!='0');
        ans += cnt[curval-curpos];
        cnt[curval-curpos]++;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}