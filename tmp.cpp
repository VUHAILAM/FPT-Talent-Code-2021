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
vector<int> addEdge(string s) {
    vector<int> res;
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            res.push_back((s[i]-'A'));
        }
    }
    return res;
}
int val[27][27];
void solve() {
    int n;
    cin >> n;
    map<char, int> cost;
    g = vector< vector<int> >(26, vector<int>());
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            val[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < n; i++) {
        int stt;
        char e;
        int c;
        string s;
        cin >> stt >> e >> c >> s;
        cost[e] = c;
        val[e-'A'][e-'A'] = c;
        vector<int> tmp = addEdge(s);
        for(int j = 0; j < tmp.size(); j++) {
            val[tmp[j]][e-'A'] = val[tmp[j]][tmp[j]]+ c;
            val[e-'A'][tmp[j]] = val[tmp[j]][tmp[j]]+ c;
            debug3(tmp[j], e-'A', val[tmp[j]][e-'A']);
        }
    }
    int ans = 0;
    for (int i = 1; i < 26; i++)
        val[i][i] = 0;
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if(val[i][k] > 0 && val[k][j] > 0)
                    if(val[i][j] > val[i][k] + val[k][j]) {
                        //debug3(i,j, val[i][j]);
                        val[i][j] = val[i][k]+val[k][j];
                    }
                
    cout << val[0][3] << endl;
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
