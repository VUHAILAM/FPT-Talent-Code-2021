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
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n <= m) {
        cout << "Not Enough Data" << endl;
    } else {
        vector<ll> ps(n+1,0);
        for(int i = 1; i <= n; i++) {
            ps[i] = ps[i-1]+a[i];
        }
        for(int i = 1; i <= n-m; i++) {
            ll ans = ps[i-1+m] - ps[i-1];
            ans = ans/m;
            cout << ans << " ";
        }
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
