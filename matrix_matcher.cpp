#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct StrHash { // Hash polinomial con exponentes decrecientes.
	int ms[2] = {1000000007, 1000000403};
	int b = 500000000;
	vector<int> hs[2], bs[2];
	StrHash(string const& s) {
		int n = (int)s.size();
		for (int k = 0; k < 2; ++k) {
			hs[k].resize(n+1), bs[k].resize(n+1, 1);
			for (int i = 0; i < n; ++i) {
				hs[k][i+1] = (hs[k][i] * b + s[i]) % ms[k];
				bs[k][i+1] =  bs[k][i] * b         % ms[k];
			}
		}
	}
	int get(int idx, int len) const { // Hashes en `s[idx, idx+len)`.
		int h[2];
		for (int k = 0; k < 2; ++k) {
			h[k] = hs[k][idx+len] - hs[k][idx] * bs[k][len] % ms[k];
			if (h[k] < 0) h[k] += ms[k];
		}
		return (h[0] << 32) | h[1];
	}
};

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

    int n, m; cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int x, y; cin >> x >> y;
    
    vector<string> p(x);
    for(int i = 0; i < x; i++) cin >> p[i];

    if(x > n || y > m) return void(cout << 0 << '\n');

    vector<StrHash> shs;
    shs.reserve(n);
    for(int i = 0; i < n; i++) shs.push_back(StrHash(s[i]));

    vector<StrHash> phs;
    phs.reserve(x);
    for(int i = 0; i < x; i++) phs.push_back(StrHash(p[i]));

    vector<int> pp(x);
    for(int i = 0; i < x; i++) pp[i] = phs[i].get(0, y);

    StrHash sep(string(y, '?'));

    int ans = 0;

    for(int j = 0; j+y-1 < m; j++) {

        vector<int> ss(n);
        for(int i = 0; i < n; i++) ss[i] = shs[i].get(j, y);

        vector<int> ps(x+n+1);
        for(int i = 0; i < x; i++) ps[i] = pp[i];
        ps[x] = sep.get(0, y);
        for(int i = x+1; i < x+n+1; i++) ps[i] = ss[i-x-1];

        vector<int> pi = pfun(ps);

        ans += count(all(pi), x);

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