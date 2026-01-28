#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n), ans(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        ans[i] = a[i]/2;
        cnt += a[i]/2;
    }

    int i = 0;

    while(abs(cnt) > 0 && i < n) {

        if(abs(a[i])%2 == 0) { i++; continue; }

        int sign = (a[i]>0)-(a[i]<0);

        if(abs(cnt-a[i]/2+(a[i]+sign)/2) < abs(cnt)) {
            cnt = cnt-a[i]/2+(a[i]+sign)/2;
            ans[i] = (a[i]+sign)/2;
        }

        i++;
    }

    for(int j = 0; j < n; j++) cout << ans[j] << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}