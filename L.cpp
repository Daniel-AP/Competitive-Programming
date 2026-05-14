#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

#define ll long long int
#define all(a) begin(a), end(a)

const ll mod = 998244353;

#define int long long int

void solve(){
	int n,k; cin >> n >> k;
	vector<pair<int,int>> a(n);
	for(auto & [x,y] : a) cin >> x >> y;
	pair<int,int> ans = {1e9,1e9};
	for(int i = 0; i < 480; i++){
		int cnt = 0;
		for(auto & [x,y] : a){
			if(i > x + y) continue;
			int l = ((i % k) - (x % k) + k) % k;
			int xx = max(l + x, i); 
			int df = x + y - xx;
			if(df < 0) continue;
			cnt += 1 + (df / k);
		}
		if(cnt < ans.second) ans = {i,cnt};
	}
	cout << ans.first << ' ' << ans.second << '\n';
}

int32_t main() { 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t; cin >> t; while(t--)
	solve();
	return 0;
}