#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

__int128_t read() {
    string s;
    cin >> s;
    __int128_t x = 0;
    bool neg = false;
    size_t i = 0;
    if(s[0] == '-') { neg = true; i = 1; }
    for(; i < s.size(); i++) {
        x = x*10+(s[i]-'0');
    }
    return neg ? -x : x;
}

void print(__int128_t x) {
    if(x == 0) {
        cout << '0';
        return;
    }
    if(x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while(x > 0) {
        s.push_back(char('0'+x%10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve() {

    int n; cin >> n;

    vector<__int128_t> f(n);
    for(int i = 0; i < n; i++) f[i] = read();

    if(n == 2) {
        print(f[n-1]);
        cout << ' ';
        print(f[0]);
        cout << '\n';
        return;
    }

    vector<__int128_t> ans(n);

    ans[0] = (-(n-2)*f[0]+(n-1)*f[1]+f[n-1])/(2*(n-1));
    ans[n-1] = (f[0]+(n-1)*f[n-2]-(n-2)*f[n-1])/(2*(n-1));

    for(int i = 1; i < n-1; i++) ans[i] = (f[i-1]-2*f[i]+f[i+1])/2;

    for(int i = 0; i < n; i++) {
        print(ans[i]);
        cout << ' ';
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