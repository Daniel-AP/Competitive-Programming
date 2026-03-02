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

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    set<int> st;

    for(int i = 0; i < n; i++) {
        vector<int> b = a;
        int j = i, cnt = 0, last = i;
        while(cnt < s) {
            if(b[j] == 0) j = (j+1)%n;
            else {
                b[j]--;
                cnt++;
                last = j;
                j = (j+1)%n;
            }
        }
        st.insert(last);
    }

    cout << st.size() << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}