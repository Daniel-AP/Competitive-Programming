#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

map<int, int> primeFactors(int n) {

    map<int, int> factors;

    while(n%2 == 0) {
        factors[2]++;
        n /= 2;
    }

    while(n%3 == 0) {
        factors[3]++;
        n /= 3;
    }

    for(int i = 5; i*i <= n; i += 6) {
        while(n%i == 0) {
            factors[i]++;
            n /= i;
        }
        while(n%(i+2) == 0) {
            factors[i+2]++;
            n /= (i+2);
        }
    }

    if(n != 1) factors[n]++;

    return factors;

}

void solve() {

    int n, x; cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int ans = 0;

    auto factors = primeFactors(x);

    map<int, int> nums;

    for(auto [k, v]: factors) {
        for(int i = 0; i < n; i++) {
            if(a[i]%k == 0) nums[k] += a[i];
        }
    }

    for(auto [k, v]: factors) {
        ans = max(ans, nums[k]);
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