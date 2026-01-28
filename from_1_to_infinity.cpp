#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

int cnt_digits(int n, int k) {
 
    int occ = 0;
    int place = 1;
 
    while(place <= n) {

        int r = n/(place*10);
        int curr = (n/place)%10;
        int l = n%place;
 
        occ += r*place;
 
        if(curr > k) occ += place;
        else if(curr == k) occ += l+1;
 
        place *= 10;

    }
 
    return occ;
}


int lg(int n) {
 
    int f = 10;
    int ans = 1;
 
    while(f < n) {
        ans++;
        f *= 10;
    }
 
    return ans;
 
}

int d(int n) {
    return to_string(n).length();
}

int before(int n) {
 
    int lg10 = lg(n);
    int f = 10, ans = 0;
 
    for(int i = 1; i <= lg10; i++) {
        ans += min(n-f/10, f-f/10)*i;
        f *= 10;
    }
 
    return ans+d(n);
 
}


void solve() {

    int k; cin >> k;
    int l = 1, r = 1e15, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;
        int digits = before(mid);

        if(digits <= k) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }

    }

    int cnt = 0, diff = k-before(ans);
    int m = (ans+1), f = 1;
    while(f*10 <= m) f *= 10;

    while(diff) {
        cnt += (m/f)%10;
        f /= 10;
        diff--;
    }

    for(int i = 1; i <= 9; i++) {
        cnt += cnt_digits(ans, i)*i;
    }

    cout << cnt << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}