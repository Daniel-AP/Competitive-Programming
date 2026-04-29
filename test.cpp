#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int fromBase(string n, int b) {

    int ans = 0;

    for(char d: n) {
        
        int val = 0;

        if('0' <= d && d <= '9') val = d-'0';
        else val = d-'A'+10;

        ans *= b;
        ans += val;

        if(val >= b) return -1;

    }

    return ans;

}

vector<int> toBase(int n, int b) {

    vector<int> ans;

    while(n) {
        ans.push_back(n%b);
        n /= b;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

void solve() {

    int n, b; cin >> n >> b;

    vector<int> ans = toBase(n, b);

    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while(t--) solve();

    return 0;

}