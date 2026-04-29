#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> sieve(int n) {

    if(n <= 1) return {};

    int m = n/2;
    vector<bool> s(m, true);
    vector<int> primes{2};

    for(int i = 3; i*i < n; i += 2) {
        if(s[i/2]) {
            for(int j = (i*i)/2; j < m; j += i) {
                s[j] = false;
            }
        }
    }

    for(int i = 1; i < m; i++) {
        if(s[i]) primes.push_back(2*i+1);
    }

    return primes;

}

int binpow(int a, int b, int m) {

    a %= m;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%m;
        a = (a*a)%m;
        b /= 2;
    }

    return ans;

}

int inv(int a, int m) {
    return binpow(a, m-2, m);
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

    int l, r; cin >> l >> r;
    int gap = 1500;
    r += gap;
    int rr = sqrt(r)+1;

    vector<int> primes = sieve(rr+1);
    vector<bool> s(r-l+1, true);

    for(int p: primes) {
        for(int j = max((l+p-1)/p*p, 2*p); j <= r; j += p) {
            s[j-l] = false;
        }
    }

    __int128_t ans = 0;

    primes.clear();

    for(int i = 0; i < r-l+1; i++) {
        if(s[i] && i+l > 1) primes.push_back(i+l);
    }

    r -= gap;

    for(int i = 0; primes[i] <= r; i++) {
        int p1 = primes[i], p2 = primes[i+1];
        int k = 1;
        while(p1 > 0) k *= 10, p1 /= 10;
        p1 = primes[i];
        ans += ((inv(k, p2)*(p2-p1%p2)%p2)%p2)*k+p1;
    }

    print(ans);
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