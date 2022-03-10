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
bool isPalimdore(string s) {
    int n = s.size();
    bool ok = true;
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n-i-1]) {
            ok = false;
            break;
        }
    }
    return ok;
} 
void solve() {
    string n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n.size(); i++) {
        sum += ll(n[i]-'0');
    }
    //debug1(sum);
    bool ok1 = isPalimdore(n);
    bool ok2 = isPalimdore(to_string(sum));
    if(ok1&&ok2) {
        cout << "Y";
    } else {
        cout << "N";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
        if(i!=t) {
            cout << endl;
        }
    }
    return 0;
}
