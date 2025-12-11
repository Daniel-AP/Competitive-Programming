#include <bits/stdc++.h>
using namespace std;

void solve() {

    int t;
    cin >> t;

    while(t--) {

        int n, l, r;
        cin >> n >> l >> r;
        l--; r--;

        vector<long long> a(n), back, front, prefix(r-l+1), prefix_back, prefix_front;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i < l) back.push_back(a[i]);
            if(i > r) front.push_back(a[i]);
        }

        sort(back.begin(), back.end());
        sort(front.begin(), front.end());

        prefix_back.resize(back.size());
        prefix_front.resize(front.size());

        partial_sum(a.begin()+l, a.begin()+r+1, prefix.begin());
        partial_sum(back.begin(), back.end(), prefix_back.begin());
        partial_sum(front.begin(), front.end(), prefix_front.begin());

        long long min_val = prefix[r-l];

        for(int i = 0; i < r-l+1 && i < back.size(); i++) {

            long long candidate1 = prefix_back[i];
            long long candidate2 = 0;

            if(prefix[i]-prefix_back[i] > prefix[r-l]-prefix[r-l-i-1]-prefix_back[i]) {
                candidate2 = prefix[r-l]-prefix[i];
            } else {
                candidate2 = prefix[r-l-i-1];
            }

            min_val = min(candidate1+candidate2, min_val);

        }
        for(int i = 0; i < r-l+1 && i < front.size(); i++) {
            
            long long candidate1 = prefix_front[i];
            long long candidate2 = 0;

            if(prefix[i]-prefix_front[i] > prefix[r-l]-prefix[r-l-i-1]-prefix_front[i]) {
                candidate2 = prefix[r-l]-prefix[i];
            } else {
                candidate2 = prefix[r-l-i-1];
            }

            min_val = min(candidate1+candidate2, min_val);

        }

        cout << min_val << endl;

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}