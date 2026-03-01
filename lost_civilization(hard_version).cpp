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

    vector<int> leq(n, -1);
    stack<int> st;

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(!st.empty()) leq[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    vector<int> gre(n, -1);

    for(int i = n-1; i > 0; i--) {
        if(a[i] > a[i-1]+1) gre[i-1] = i;
        else gre[i-1] = gre[i];
    }

    vector<int> fail(n, -1);

    for(int i = 0; i < n-1; i++) {
        if(gre[i] != -1 && leq[i] != -1) fail[i] = min(leq[i], gre[i]);
        else if(gre[i] != -1) fail[i] = gre[i];
        else if(leq[i] != -1) fail[i] = leq[i];
    }

    int ans = 0;

    vector<int> partial(n);

    for(int i = n-1; i >= 0; i--) {
        partial[i] += n-i;
        if(fail[i] != -1) partial[i] += partial[fail[i]];
        ans += partial[i];
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