#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n, h, m;
        cin >> n >> h >> m;

        int minutes = h*60+m;
        int result = INFINITY;

        for(int i = 0; i < n; i++) {

            int h_i, m_i;
            cin >> h_i >> m_i;

            int minutes_i = h_i*60+m_i;
            int result_minutes = minutes_i >= minutes ? minutes_i - minutes : 24*60-minutes+minutes_i;
            
            result = min(result, result_minutes);

        }

        cout << result/60 << " " << result%60 << endl; 

    }

    return 0;

}