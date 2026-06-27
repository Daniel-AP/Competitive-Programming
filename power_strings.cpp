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

void solve(const string& s) {

    int n = s.length();
    vector<int> pi = pfun(s);

    int k = n-pi[n-1];

    if(n%k != 0) cout << 1 << '\n';
    else cout << n/k << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    string s;

    while(true) {
        cin >> s;
        if(s == ".") break;
        solve(s);
    }

    return 0;

}