#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);
    map<pair<int, int>, int> mp, match;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    for(int i = 0; i < n; i++) {
        mp[{ a[i], b[i] }] = i;
    }

    for(int i = 0; i < n; i++) {
        if(mp.find({ b[i], a[i] }) == mp.end()) return void(cout << -1 << '\n');
        match[{ a[i], b[i] }] = mp[{ b[i], a[i] }];
    }

    int cnt = n%2;
    pair<int, int> same = {-1, -1};

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) continue;
        if(!cnt) return void(cout << -1 << '\n');
        same = { a[i], b[i] };
        cnt--;
    }

    vector<pair<int, int>> ans;
    int l = 0, r = n-1;

    if(n%2) {

        int move1 = match[same];
        int move2 = match[{ a[n/2], b[n/2] }];

        match[{ a[move2], b[move2] }] = move1;
        match[{ same }] = n/2;

        swap(a[move1], a[n/2]);
        swap(b[move1], b[n/2]);

        if(move1 != n/2) ans.push_back({ move1+1, n/2+1 });
        
    }

    while(l < r) {

        int move1 = match[{ a[l], b[l] }];
        int move2 = match[{ a[r], b[r] }];

        match[{ a[move2], b[move2] }] = move1;
        match[{ a[l], b[l] }] = r;

        swap(a[move1], a[r]);
        swap(b[move1], b[r]);

        if(move1 != r) ans.push_back({ move1+1, r+1 });

        l++, r--;

    }

    cout << ans.size() << '\n';
    for(auto [p1, p2]: ans) cout << p1 << ' ' << p2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}