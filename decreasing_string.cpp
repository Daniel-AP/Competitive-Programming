#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();
    int p; cin >> p;
    
    int l = 1, r = n, mid, pos;

    while(l <= r) {
        mid = l+(r-l)/2;
        if(mid*(n+(n-mid+1))/2 >= p) {
            pos = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    int k = pos-1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    for(int i = 0; i+1 < n; i++) {
        if(s[i] > s[i+1]) pq.push({ i, i+1 });
    }

    vector<bool> del(n);
    set<int> st;
    int ptr = n-1;

    for(int i = 0; i < n; i++) st.insert(i);

    while(k--) {
        if(!pq.empty()) {
            auto [i, j] = pq.top(); pq.pop();
            del[i] = 1;
            st.erase(i);
            if(!st.empty()) {
                if(st.lower_bound(j) == st.begin()) continue;
                int ii = *prev(st.lower_bound(j));
                if(s[ii] > s[j]) pq.push({ ii, j });
            }
        } else {
            while(del[ptr]) ptr--;
            del[ptr] = 1;
            st.erase(ptr);
        }
    }

    string si;
    for(int i = 0; i < n; i++) if(!del[i]) si += s[i];

    int idx = p-(pos-1)*(n+(n-(pos-1)+1))/2;

    cout << si[idx-1];
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}