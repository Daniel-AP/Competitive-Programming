#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

int n, k;

int score(vector<int>& p, vector<int>& a, int start) {

    vector<int> visited(n);
    stack<int> s;

    s.push(start);

    int sm = 0, cnt = 0, ans = 0;

    while(!s.empty()) {

        int x = s.top(); s.pop();
        visited[x] = 1;

        ans = max(ans, sm+(k-cnt)*a[x]);

        cnt++;
        sm += a[x];

        if(cnt == k) break;
        if(!visited[p[x]-1]) s.push(p[x]-1);

    }

    return ans;

}

void solve() {

    int pb, ps; cin >> n >> k >> pb >> ps;

    vector<int> p(n), a(n);

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    pb--; ps--;

    int s1 = score(p, a, pb);
    int s2 = score(p, a, ps);

    if(s1 > s2) cout << "Bodya";
    else if(s2 > s1) cout << "Sasha";
    else cout << "Draw";

    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}