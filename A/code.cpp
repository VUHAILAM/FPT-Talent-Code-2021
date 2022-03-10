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
map<char, int> cost;
vector<int> addEdge(string s) {
    vector<int> res;
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            res.push_back((s[i]-'A'));
        }
    }
    return res;
}
int ans = 0;
void dfs(int u, int val) {
    if(g[u].size() == 0) {
        ans = max(ans, val);
        return;
    }
    for(int v : g[u]) {
        dfs(v, val+cost[v+'A']);
    }
}

void solve() {
    int n;
    cin >> n;
   
    queue<char> q;
    g = vector< vector<int> >(26, vector<int>());
    for(int i = 0; i < n; i++) {
        int stt;
        char e;
        int c;
        string s;
        cin >> stt >> e >> c >> s;
        cost[e] = c;
        vector<int> tmp = addEdge(s);
        for(int j = 0; j < tmp.size(); j++) {
            g[tmp[j]].push_back(e-'A');
        }
        if(tmp.size() == 0) {
            q.push(e);
        }
    }
    dfs(q.front()-'A', cost[q.front()]);
    cout << ans;
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
