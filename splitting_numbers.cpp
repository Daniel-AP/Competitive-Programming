#include <bits/stdc++.h>
using namespace std;

#define int unsigned int

void solve() {

    int n;

    while(true) {

        cin >> n;    
        if(n == 0) break;

        int a = n, b = n;
        int cnt = 0;

        for(int i = 0; i < 32; i++) {
            if((a>>i)&1) cnt++;
            if((a>>i)&1 && cnt%2 == 0) a ^= (1<<i);
        }

        cnt = 0;

        for(int i = 0; i < 32; i++) {
            if((b>>i)&1) cnt++;
            if((b>>i)&1 && cnt%2 == 1) b ^= (1<<i);
        }

        cout << a << " " << b << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}