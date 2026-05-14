#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stack>

using namespace std;

#define ll long long int
#define all(a) begin(a), end(a)

const ll mod = 1e9+7;

void solve(){
	int k,L; cin >> k >> L;
	vector<vector<int>> mt(k, vector<int>(k));
	for(int i = 0; i < k; i++) for(int j = 0; j < k; j++) cin >> mt[i][j];
	int n; cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n-1; i++) cin >> p[i];
	vector<vector<int>> dp(n, vector<int>(k));
	dp[0][0] = 1;
	for(int i = 0; i < n-1; i++){
		for(int j = 1; j < k; j++) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
		for(int j = 0; j < k; j++){
			int l = lower_bound(all(mt[j]),p[i]-L) - mt[j].begin();
			int r = upper_bound(all(mt[j]),p[i]+L) - mt[j].begin();
			if(l == k) continue;
			dp[i+1][l] = (dp[i+1][l] + dp[i][j]) % mod;
			if(r == k) continue;
			dp[i+1][r] = (dp[i+1][r] - dp[i][j] + mod) % mod;
		}
	}
	for(int i = 1; i < k; i++) dp[n-1][i] = (dp[n-1][i] + dp[n-1][i-1]) % mod;
	ll ans = 0;
	for(int i = 0; i < k; i++) ans = (ans + dp[n-1][i]) % mod;
	cout << ans << '\n';
}

signed main() { 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t; cin >> t; while(t--)
	solve();
	return 0;
}