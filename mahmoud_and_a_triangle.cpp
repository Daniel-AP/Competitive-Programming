#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> segments(n);
    for(int i = 0; i < n; i++) cin >> segments[i];

    sort(segments.begin(), segments.end());

    bool found = false;

    for(int i = 0; i+2 < n; i++) {

        int a = segments[i];
        int b = segments[i+1];
        int c = segments[i+2];

        if(a+b > c && a+c > b && c+b > a) {
            cout << "YES" << endl;
            found = true;
            break;
        }

    }

    if(!found) cout << "NO" << endl;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}