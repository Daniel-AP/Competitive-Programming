#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string a, b; cin >> a >> b;

    int rev = 0, l = 0, r = n-1;
    vector<int> ans;

    for(int i = n-1; i >= 0; i--) {

        if((a[r]-'0'+rev)%2 == (b[i]-'0')) {
            if(r > l) r--;
            else r++;
            continue;
        }

        if((a[l]-'0'+rev)%2 == (b[i]-'0')) ans.push_back(1);

        rev++;
        swap(l, r);

        if(r > l) r--;
        else r++;

        ans.push_back(i+1);

    }

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ';
    
    if(ans.size()) cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}