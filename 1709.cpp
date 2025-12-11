#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> swaps1, swaps2, swaps3, swaps4, swaps5;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swaps1.push_back(j+1);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(b[j] > b[j+1]) {
                swap(b[j], b[j+1]);
                swaps2.push_back(j+1);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
            swaps3.push_back(i+1);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swaps4.push_back(j+1);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(b[j] > b[j+1]) {
                swap(b[j], b[j+1]);
                swaps5.push_back(j+1);
            }
        }
    }

    cout << swaps1.size()+swaps2.size()+swaps3.size()+swaps4.size()+swaps5.size() << '\n';

    for(int i: swaps1) {
        cout << 1 << " " << i << '\n';
    }
    for(int i: swaps2) {
        cout << 2 << " " << i << '\n';
    }
    for(int i: swaps3) {
        cout << 3 << " " << i << '\n';
    }
    for(int i: swaps4) {
        cout << 1 << " " << i << '\n';
    }
    for(int i: swaps5) {
        cout << 2 << " " << i << '\n';
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}