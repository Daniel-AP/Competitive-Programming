#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m), prefix(n+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }

    partial_sum(a.begin(), a.end(), prefix.begin()+1);

    for(int j = 0; j < m; j++) {
        int room = lower_bound(prefix.begin(), prefix.end(), b[j])-prefix.begin();
        cout << room << " " << b[j]-prefix[room-1] << endl;
    }

    return 0;

}