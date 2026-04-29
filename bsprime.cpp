#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

const int N = 110000000;

vector<int> primes, width, ans;

int bit_width(unsigned int a) {
    if(a == 0) return 0;
    int ans = 1, cur = 1, e = 0;
    while(cur*2 <= a) cur *= 2, e++;
    ans += e;
    return ans;
}

void sieve(int n) {

    if(n <= 2) return;

    primes.push_back(2);

    int m = n/2;
    vector<char> s(m, 1);
    s[0] = 0;

    for(int i = 1; i < m; i++) {
        int x = 2*i+1;

        if(s[i]) primes.push_back(x);

        for(int k = 1; k < primes.size(); k++) {
            int p = primes[k];
            if(p > (n-1)/x) break;
            s[(x*p)>>1] = 0;
            if(x%p == 0) break;
        }

    }
}

void pre() {

    int prev = 0;
    width.assign(primes.size(), 0);

    for(int i = 0; i < width.size(); i++) {
        width[i] = prev+bit_width(primes[i]);
        prev = width[i];
    }

    prev = 0;
    ans.assign(primes.size(), 0);

    for(int i = 0; i < ans.size(); i++) {
        ans[i] = prev+__builtin_popcount(primes[i]);
        prev = ans[i];
    }

}

void solve() {

    int n; cin >> n;
    int i = upper_bound(all(width), n)-width.begin();
    int cnt = (i == 0 ? 0 : ans[i-1]);
    int pos = (i == 0 ? 1 : width[i-1]+1);
    int cur = bit_width((unsigned int)primes[i])-1;

    while(pos <= n) {
        if((primes[i]>>cur)%2) cnt++;
        cur--;
        pos++;
    }

    cout << cnt << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    sieve(N);
    pre();
    
    while(t--) solve();

    return 0;

}