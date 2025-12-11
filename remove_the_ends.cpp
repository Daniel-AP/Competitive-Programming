#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, start = 0, end = n;

    for(int i = 0; i < n; i++) {
        if(a[i] < 0) break;
        ans += a[i];
        start++;
    }

    for(int i = n-1; i >= start; i--) {
        if(a[i] > 0) break;
        ans += -a[i];
        end--;
    }

    if(start == end) {
        cout << ans << '\n';
        return;
    }

    int m = end-start;

    vector<int> b1(m), b2(m);
    
    b1[0] = a[start] > 0 ? a[start] : 0;
    b2[m-1] = a[end-1] < 0 ? a[end-1] : 0;

    for(int i = 1; i+start < end; i++) {
        b1[i] = b1[i-1]+(a[i+start] > 0 ? a[i+start] : 0);
    }

    for(int i = m-2; i >= 0; i--) {
        b2[i] = b2[i+1]+(a[i+start] < 0 ? -a[i+start] : 0);
    }

    int ans1 = 0, ans2 = 0;

    for(int i = 0; i < m-1; i++) {
        ans1 = max(b1[i]+b2[i+1], ans1);
    }

    ans1 = max(b1[m-1], ans1);
    ans2 = max(b2[0], ans2);

    for(int i = 1; i < m; i++) {
        ans2 = max(b2[i]+b1[i-1], ans2);
    }

    cout << ans+max(ans1, ans2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}