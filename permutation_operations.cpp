#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    stack<int> st;
    st.push(n-1);

    int op = 1, cur = 0;

    vector<pair<int, int>> b;

    for(int i = n-2; i >= 0; i--) {
        if(a[st.top()] < a[i]) b.push_back({a[i]-a[st.top()], i+2});
        st.push(i);
    }

    sort(all(b));

    vector<int> ans(n, 1);

    int j = 0, i = 0;

    while(j < b.size() && i < n) {
        while(b[j].first > 0 && i < n) {
            b[j].first -= i+1;
            ans[i] = b[j].second;
            i++;
        }
        j++;
    }

    for(int x: ans) cout << x << ' ';
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