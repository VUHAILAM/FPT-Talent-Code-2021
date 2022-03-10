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
    string s;
    string k;
    cin >> s;
    cin >> k;
    string tmp = k;
    unordered_map<char, char> m;
    char base = 'J';
    for(char i = '0'; i <= '9'; i++) {
        m[i] = base++;
        //base++;

    }
    for(int i = 0; i < k.size(); i++) {
        if(isdigit(k[i])) {
            k[i] = m[k[i]];
            tmp[i] = m[tmp[i]];
        }
    }
    while (k.size() < s.size())
    {
        /* code */
        k=k+tmp;
    }
    //debug1(k);
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        if(isalpha(k[i])) {
            char c = ((s[i]-'A') + (k[i]-'A'))%26 + 'A';
            //debug1(c);
            ans += c;
        }
        
    }
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
