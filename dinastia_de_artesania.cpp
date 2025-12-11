#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x;
vector<int> obras;
vector<vector<int>> children;
vector<int> ans;
bool found = false;

void dfs(int node, int sum, int depth, vector<int>& path, unordered_map<int,int>& mp) {

    if(found) return;

    sum += obras[node];
    path.push_back(node);
    depth++;

    if(mp.find(sum - x) != mp.end()) {

        int start = mp[sum - x];

        ans = vector<int>(path.begin()+start, path.end());
        found = true;

    }

    bool inserted = false;
    if(mp.find(sum)==mp.end()) {
        mp[sum] = depth;
        inserted = true;
    }

    for(int child: children[node]) {
        if(found) break;
        dfs(child, sum, depth, path, mp);
    }

    if(inserted) mp.erase(sum);
    path.pop_back();
}

void solve() {

    cin >> n;

    children.assign(n, vector<int>());
    vector<int> parent(n, -1);

    for(int i=1; i<n; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    obras.resize(n);

    for(int i=0; i<n; i++) cin >> obras[i];

    cin >> x;

    unordered_map<int,int> mp;
    mp[0] = 0;

    vector<int> path;
    dfs(0, 0, 0, path, mp);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;

}
