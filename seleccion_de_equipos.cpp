#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000;

vector<bool> is_prime(N+1, 1);

void sieve() {

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j <= N; j += i)
                is_prime[j] = false;
        }
    }

}

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<vector<int>> teams(k, vector<int>());

    int m = 0;

    for(int i = 0; i < n; i++) {
        if(!is_prime[a[i]]) continue;
        teams[m%k].push_back(a[i]);
        m++;
    }

    for(int i = 0; i < n; i++) {
        if(is_prime[a[i]]) continue;
        teams[m%k].push_back(a[i]);
        m++;
    }

    for(int i = 0; i < k; i++) {
        cout << i+1 << ": ";
        for(int x: teams[i]) cout << x << ' ';
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    sieve();

    while(t--) solve();

    return 0;

}