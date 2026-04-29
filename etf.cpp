#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000005;
vector<int> phi(N+1);

void sieve() {

	for(int i = 1; i < N; i++) phi[i] = i;
	for(int i = 2; i < N; i++) {
		if(phi[i] == i) {
			for(int j = i; j < N; j += i) { phi[j] -= phi[j] / i; }
		}
	}

}

void solve() {

    int n; cin >> n;

    cout << phi[n] << '\n';
    
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