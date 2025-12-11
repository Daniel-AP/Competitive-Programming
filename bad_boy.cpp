#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<long long, long long>& a, const pair<long long, long long>& b, const long long& i, const long long& j) {

    long long d1 = abs(a.first-i)+abs(a.second-j);
    long long d2 = abs(b.first-i)+abs(b.second-j);
    
    return d1 > d2;

}

pair<long, long> opp(pair<long, long> c, long long n, long long m) {
    c.first = abs(c.first-n-1);
    c.second = abs(c.second-m-1);
    return c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n, m, i, j;
        cin >> n >> m >> i >> j;

        vector<pair<long long, long long>> corners = {{ 1, 1 }, { 1, m }, { n, 1 }, { n, m }};

        sort(corners.begin(), corners.end(), [&](const pair<long long, long long>& a, const pair<long long, long long>& b){
            return comp(a, b, i, j);
        });

        pair<long long, long long> yoyo1 = corners[0];
        pair<long long, long long> yoyo2 = opp(yoyo1, n, m);

        cout << yoyo1.first << " " << yoyo1.second << " " << yoyo2.first << " " << yoyo2.second << endl;

    }

    return 0;


}