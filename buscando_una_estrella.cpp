#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    while(n--) {

        char s; cin >> s;

        switch(s) {
            case 'R':
                int x; cin >> x;
                pq.push(x);
                break;
            case 'S':
                if(pq.size() < 3) {
                    cout << "NO HAY SUFICIENTES PUNTAJES" << '\n';
                } else {
                    int a, b, c;
                    a = pq.top(); pq.pop();
                    b = pq.top(); pq.pop();
                    c = pq.top();
                    cout << a << ' ' << b << ' ' << c << '\n';
                    pq.push(a); pq.push(b);
                }
                break;
            case 'B':
                if(pq.size() != 0) pq.pop();
                break;
            default:
                break;
        }

    }

    if(pq.size() == 0) cout << "NO HUBO GANADOR" << '\n';
    else {

        cout << "EL PUNTAJE MAS ALTO FUE ";

        while(pq.size() > 1) pq.pop();
        cout << pq.top() << '\n';
        
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}