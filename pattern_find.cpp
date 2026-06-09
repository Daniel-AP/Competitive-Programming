#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> pfun(const string& s) {
    int n = (int)s.size(), j = 0;
    vector<int> pi(n);

    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

vector<int> match(const string& s, const string& pat) {
	vector<int> p = pfun(pat + '\0' + s), res;
	for (int i = (int)p.size() - (int)s.size(); i <= (int)p.size(); i++) {
		if (p[i] == (int)pat.size()) res.push_back(i - 2 * (int)pat.size());
	}
	return res;
}

void solve() {

    string s, p; cin >> s >> p;
    vector<int> matches = match(s, p);

    if(matches.empty()) cout << "Not Found" << '\n';
    else {
        cout << matches.size() << '\n';
        for(int x: matches) cout << x+1 << ' ';
        cout << '\n';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}