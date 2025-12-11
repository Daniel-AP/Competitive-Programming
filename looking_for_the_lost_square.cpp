#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, set<int>> points;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points[x].insert(y);
    }

    int mx = 0;

    for(auto [x, ys]: points) {
        for(auto i = ys.begin(); i != ys.end(); i++) {
            for(auto j = ys.begin(); j != ys.end(); j++) {
                if(i == j) continue;
                int diff = abs(*i-*j);
                int x1 = x-diff, x2 = x+diff;
                int y1 = *i, y2 = *j;
                bool can_x1 = (points[x1].count(y1) && points[x1].count(y2));
                bool can_x2 = (points[x2].count(y1) && points[x2].count(y2));
                if(can_x1 || can_x2) mx = max(diff, mx);
            }
        }
    }

    cout << mx << endl;

    return 0;

}