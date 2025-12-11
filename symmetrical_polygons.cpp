#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int, greater<int>> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int pol = 0, rep = 0;
    vector<int> single;

    for(auto [k, v]: cnt) {
        pol += v/2*2*k;
        rep += v/2*2;
        if(v&1) single.push_back(k);
    }

    sort(single.rbegin(), single.rend());

    if(single.size() == 1 && single[0] < pol) pol += single[0], rep++;
    if(single.size() >= 2) {
        bool found = false;
        for(int i = 0; i+1 < single.size(); i++) {
            if(single[i] < pol+single[i+1]) {
                pol += single[i]+single[i+1];
                rep += 2;
                found = true;
                break;
            }
        }
        if(!found && single.back() < pol) {
            rep++;
            pol += single.back();
            found = true;
        }
    }

    if(rep < 3) pol = 0;

    cout << pol << '\n';
     
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}