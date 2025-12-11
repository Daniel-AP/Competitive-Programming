#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout<<"Time elapsed: "<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count()<<" ms\n";

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {

        int mx =__builtin_popcountll(a[0]);

        for(int b = 0; b < 63; b++) {

            int base = (a[0]>>b)<<b;
            int y = base+((1LL<<b)-1);

            if(y < a[0] || y > a[0]+k) continue;

            mx = max(mx, (int)__builtin_popcountll(y));

        }

        cout << mx << "\n";
        return;

    }

    int base = 0, even = 0;

    for(int i = 0; i < n; i++) {
        base += __builtin_popcountll(a[i]);
        if((a[i]&1) == 0) even++;
    }

    int can = min(even, k);
    int kk = k-can;
    int pairs = kk/2;

    cout << base+can+pairs <<"\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}
