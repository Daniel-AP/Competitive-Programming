#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct StrHash { // Hash polinomial con exponentes decrecientes.
	static constexpr int ms[] = {1'000'000'007, 1'000'000'403};
	static constexpr int b = 500'000'000;
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

void solve() {

    string s; cin >> s;
    string bad; cin >> bad;

    int n = s.length();
    int k; cin >> k;

    vector<int> px(n+1);

    for(int i = 1; i <= n; i++) {
        px[i] = px[i-1]+(1-(bad[s[i-1]-'a']-'0'));
    }

    StrHash h(s);
    unordered_set<int> seen;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int cnt = px[j]-px[j-i];
            if(cnt > k) continue;
            seen.insert(h.get(j-i, i));
        }
    }

    cout << seen.size() << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}