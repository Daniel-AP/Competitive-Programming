#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int m = n-1;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m);
    for(int i = 0; i < m; i++) b[i] = abs(a[i]-a[i+1]);

    vector<int> r(m, m), l(m, -1);
    stack<int> st;

    for(int i = m-1; i >= 0; i--) {
        while(!st.empty() && b[st.top()] > b[i]) st.pop();
        if(!st.empty()) r[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 0; i < m; i++) {
        while(!st.empty() && b[st.top()] >= b[i]) st.pop();
        if(!st.empty()) l[i] = st.top();
        st.push(i);
    }

    map<int, int> mp;

    for(int i = 0; i < m; i++) {
        int ll = i-l[i], rr = r[i]-i;
        mp[b[i]] += ll*rr;
    }

    vector<int> ans(m);
    ans[m-1] = mp[m];

    for(int i = m-2; i >= 0; i--) ans[i] = ans[i+1]+mp[i+1];
    for(int i = 0; i < m; i++) cout << ans[i] << ' ';

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