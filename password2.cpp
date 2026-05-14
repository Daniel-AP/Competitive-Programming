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
    int n = s.length();

    StrHash hash(s);
	string ans = "#";

	int sz = 1;

	while(sz < n) {
		if(hash.get(0, sz) == hash.get(n-sz, sz)) {
			ans = s.substr(0, sz);
			break;
		}
		sz++;
	}

	if(ans == "#") return void(cout << "Just a legend" << '\n');

	if(count(all(ans), ans[0]) == sz) {
		int cur = 0, best = 0;
		for(int i = 1; i < n-1; i++) {
			if(s[i] == ans[0]) {
				cur++;
			} else {
				best = max(cur, best);
				cur = 0;
			}
		}
		best = max(cur, best);
		while(sz < n && hash.get(0, sz) == hash.get(n-sz, sz)) {
			sz++;
		}
		sz--;
		cout << string(min(best, sz), ans[0]) << '\n';
	} else {
		s.pop_back();
		if(s.find(ans, 1) == string::npos) cout << "Just a legend" << '\n';
		else cout << ans << '\n';
	}
   
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}