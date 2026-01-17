#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int cntl = count(all(s), '('), cntr = n-cntl;
    
    if(cntl != cntr) return void(cout << -1 << '\n');

    stack<int> st;
    vector<int> ans(n);

    bool one = false, br = false;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(i);
        } else {
            if(st.empty()) { br = true; break; }
            st.pop();
        }
    }

    if(st.empty() && !br) one = true;
    while(!st.empty()) st.pop();

    reverse(all(s));
    br = false;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(i);
        } else {
            if(st.empty()) { br = true; break; }
            st.pop();
        }
    }

    if(st.empty() && !br) one = true;
    while(!st.empty()) st.pop();

    reverse(all(s));

    if(one) {
        cout << 1 << '\n';
        for(int i = 0; i < n; i++) cout << 1 << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(i);
        } else {
            if(!st.empty()) {
                ans[st.top()] = ans[i] = 1;
                st.pop();
            } else ans[i] = 2;
        }
    }

    while(!st.empty()) {
        ans[st.top()] = 2;
        st.pop();
    }

    cout << 2 << '\n';
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