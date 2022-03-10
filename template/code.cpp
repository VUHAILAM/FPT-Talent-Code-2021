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

ll a[66][66];

void calc() {
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    for(int i = 2; i <= 64; i++) {
        
        a[i][0] = 1;
        a[i][i] = 1;
        for(int j = 1; j <= i-1; j++) {
            a[i][j] = a[i-1][j]+a[i-1][j-1];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> dp(n+2, 0);
    calc();

    ll s1 = 0;
    for(int i = 0; i <= n; i++) {
        s1 += a[n][i];
    }
    ll s2 = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            s2+=a[i][j];
        }
    }
    cout << s1 << " " <<s2 << endl;
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
