#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> zfun(const string& s) {
    int n = (int)s.size(), l = 0, r = 0;
    vector<int> z(n);

    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }

    return z;
}

void solve(const string& s) {

    string rs = s; reverse(all(rs));
    string t = rs+"#"+s;

    vector<int> z = zfun(t);
    int best = 0;

    for(int i = t.length()-1; i > s.length(); i--) {
        if(z[i] != t.length()-i) continue;
        best = z[i];
    }

    cout << s+rs.substr(best) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    string s;

    while(cin >> s) solve(s);

    return 0;

}