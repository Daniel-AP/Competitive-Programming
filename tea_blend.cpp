#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;
vector<int> spf(N+1);

void sieve() {

    for(int i = 2; i <= N; i++) spf[i] = i;

    for(int i = 2; i*i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

map<int, int> factors(int n) {

    map<int, int> ans;
    while(spf[n]) {
        ans[spf[n]]++;
        n /= spf[n];
    }

    return ans;

}

static mt19937_64 rng(
    chrono::steady_clock::now().time_since_epoch().count()
);

static int randomBase() {
    return uniform_int_distribution<int>(256, 999'999'999)(rng);
}

struct VectorHash { // Hash polinomial con exponentes decrecientes.
	static constexpr int ms[] = {1'000'000'007, 1'000'000'403};
	inline static const int b = randomBase();

	vector<int> hs[2], bs[2];

	VectorHash(vector<int> const& v) {
		int n = (int)v.size();

		for (int k = 0; k < 2; k++) {
			hs[k].resize(n+1), bs[k].resize(n+1, 1);

			for (int i = 0; i < n; i++) {
				int x = v[i] % (ms[k]-1);
				if (x < 0) x += ms[k]-1;
				x++;

				hs[k][i+1] = (hs[k][i] * b + x) % ms[k];
				bs[k][i+1] = bs[k][i] * b % ms[k];
			}
		}
	}

	int get(int idx, int len) const {
		int h[2];

		for (int k = 0; k < 2; k++) {
			h[k] = hs[k][idx+len] - hs[k][idx] * bs[k][len] % ms[k];
			if (h[k] < 0) h[k] += ms[k];
		}

		return (h[0] << 32) | h[1];
	}
};

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    int mx = 0;

    for(int i = 0; i < n; i++) {
        auto f = factors(a[i]);
        vector<int> odd;
        for(auto [k, v]: f) {
            if(v%2) odd.push_back(k);
        }
        VectorHash hs(odd);
        cnt[hs.get(0, odd.size())]++;
        mx = max(mx, (int)odd.size());
    }

    auto cur = factors(1);
    int ans = 0;

    set<int> odds;

    for(int i = 0; i < n; i++) {
        auto f = factors(a[i]);
        for(auto [k, v]: f) {
            if(odds.contains(k) && v%2) { odds.erase(k); continue; }
            if(!odds.contains(k) && v%2) { odds.insert(k); continue; }
        }
        if(odds.size() > mx) continue;
        vector<int> odd(all(odds));
        VectorHash hs(odd);
        ans += cnt[hs.get(0, odd.size())];
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    sieve();

    while(t--) solve();

    return 0;

}