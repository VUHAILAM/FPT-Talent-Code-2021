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

struct Prd
{
    /* data */
    string name;
    string cas;
    ll a;
    ll b;
    ll k;
};


void solve() {
    int n;
    cin >> n;
    vector<Prd> a(n);
    ll s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].a >> a[i].b;
        a[i].k = a[i].a*a[i].b;
        s += a[i].k;
        a[i].cas = a[i].name;
        for(int j = 0; j < a[i].cas.size(); j++) {
            a[i].cas[j] = tolower(a[i].cas[j]);
        }
    }
    int m = n/5;
    ll s1 = (s*4ll+4ll)/5ll;
    sort(a.begin(), a.end(), [](Prd c, Prd d){
        if(c.k == d.k) {
            return c.cas < d.cas;
        } else {
            return c.k > d.k;
        }
    });
    //debug2(m,s1);
    vector<Prd> ans;
    for(int i = 0; i < m; i++) {
        ans.push_back(a[i]);
    }

    sort(ans.begin(), ans.end(), [](Prd c, Prd d){
        return c.cas < d.cas;
    });
    cout << "{";
    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i].name;
        if(i != ans.size()-1) {
            cout << ",";
        }
    }
    
    cout << "}";
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
