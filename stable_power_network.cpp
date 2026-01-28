#include <bits/stdc++.h>

// macros
typedef long long int ll;
#define vec vector 
#define loop(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second
// constants
#define INF (1LL << 62)
#define int long long
#define printarr(a) cout << #a << ": "; \
	 	    for(auto x : a) cout << x << " "; \
		    cout << "\n";

using namespace std;

vector<unordered_multimap<int, array<int,2>>> g;

bool ok(int x) {
	int N = g.size();
	queue<int> q;
	vector<bool> vis(N, false);

	q.push(0);
	vis[0] = true;

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto ngb : g[node]) {
			if(ngb.S[1] > x) {
				continue;
			}
			if(ngb.F == N-1) return true;
			if(vis[ngb.F]) continue;
			q.push(ngb.F);
			vis[ngb.F] = true;
		}
	}

	return false;
}

int dijkstra(int maxRisk) {
    int N = g.size();
    vector<int> dist(N, INF);
    dist[0] = 0;
    
    // min-heap: {time, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while(!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();
        
        // if we found a better path to this node already, skip
        if(time > dist[node]) continue;
        
        // if we reached the destination, return the time
        if(node == N-1) return time;
        
        for(auto ngb : g[node]) {
            int neighbor = ngb.F;
            int edgeTime = ngb.S[0];
            int edgeRisk = ngb.S[1];
            
            // Only consider edges within the risk limit
            if(edgeRisk > maxRisk) continue;
            
            int newTime = time+edgeTime;
            if(newTime < dist[neighbor]) {
                dist[neighbor] = newTime;
                pq.push({newTime, neighbor});
            }
        }
    }
    
    return INF; // No path found
}

void add_node(int u, int w, int W, int R) {
	g[u].insert({ w, { W, R }});
}

void solve() {
    int n, m;
	cin >> n >> m;

	g.clear();
	g.resize(n);

	int r = -1;

	loop(i,0,m) {
		int u, w, W, R;
		cin >> u >> w >> W >> R;

		r = max(r, R);

		u--;
		w--;
		add_node(u, w, W, R);
		add_node(w, u, W, R);
	}

    if(!ok(r)) {
        cout << -1 << "\n";
        return;
    }

	int l = -1;
	while(r-l > 1) {
		int m = (r-l) / 2+l;
		if(ok(m)) r = m;
		else l = m;
	}

    int minTime = dijkstra(r);
    
    if(minTime == INF) {
        cout << -1 << "\n";
    } else {
        cout << r << " " << minTime << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--) solve();

	return 0;
}