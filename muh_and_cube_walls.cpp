#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> pfun(const vector<int>& s) {
    int n = (int)s.size(), j = 0;
    vector<int> pi(n);

    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

void solve() {

    int n, w; cin >> n >> w;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(w);
    for(int i = 0; i < w; i++) cin >> b[i];

    vector<int> s(n-1);
    for(int i = 0; i+1 < n; i++) s[i] = a[i]-a[i+1];

    vector<int> p(w-1);
    for(int i = 0; i+1 < w; i++) p[i] = b[i]-b[i+1];

    vector<int> ps;
    copy(all(p), back_inserter(ps));
    ps.push_back(INF);
    copy(all(s), back_inserter(ps));

    vector<int> pi = pfun(ps);

    cout << count(all(pi), w-1) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}