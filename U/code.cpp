#include<bits/stdc++.h>
using namespace std;

// DEBUG
#define format(x) << #x << ": " << (x)
#define com << ", "
#define ndl << endl;
#define debug1(x) cerr format(x) ndl;
#define debug2(x, y) cerr format(x) com format(y) ndl;
#define debug3(x, y, z) cerr format(x) com format(y) com format(z) ndl;
#define debug4(x, y, z, w) cerr format(x) com format(y) com format(z) com format(w) ndl;
void debug_out() { cerr << "\n"; }
template <typename H, typename... T>
void debug_out(H h, T... t) { cerr << " " << (h); debug_out(t...); }
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// 

typedef long long ll;
typedef pair<int, int> ii;

vector< vector<int> > g;

vector< vector<int> >  scc;
vector<int> low;
vector<int> num;
vector<int> vis, curr, s;

int timer = 0;

void dfs(int u) {
    vis[u] = 1;
    low[u] = num[u] = timer++;
    s.push_back(u);
    curr[u] = 1;
    for(int v : g[u]) {
        if(vis[v] == 0) {
            dfs(v);
        }
        if (curr[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
            scc.push_back(vector<int>());
            while (true) {
                int v = s.back(); s.pop_back(); curr[v] = 0;
                scc.back().push_back(v);
                if (u == v) break;
            }
        }
}

void solve() {
    int n;
    cin >> n;
    g = vector< vector<int> >(n,vector<int>());
    int m = 0;
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        m = max(m, u);
        m = max(m, v);
        g[u].push_back(v);
    }
    num = vector<int>(m+1, 0);
    low = vector<int>(m+1, 0);
    vis = vector<int>(m+1,0);
    curr = vector<int>(m+1,0);
    for(int i = 0; i < m+1; i++) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }

    //debug1(scc.size());
    for(int i = 0; i < scc.size(); i++) {
        sort(scc[i].begin(), scc[i].end());
    }
    sort(scc.begin(), scc.end(), [](vector<int> a, vector<int> b){
        if(a.size() == b.size()) {
            bool ok = false;
            for(int i = 0; i < a.size(); i++) {
                if(a[i] > b[i]) {
                    ok = true;
                    break;
                }
            }
            return !ok;
        }
        return a.size() > b.size();
    });
    cout << scc.size() << endl;
    for(int i = 0; i < scc.size(); i++) {
        for(int j = 0; j < scc[i].size(); j++) {
            cout << scc[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
