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
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    if(s2.size() > s1.size()) {
        cout << "N" <<endl;
        return;
    }
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == s2[0] && n > 0) {
            int k = i;
            bool isT = true;
            for(int j = 0; j < s2.size(); j++) {
                if(s1[k] != s2[j]) {
                    isT = false;
                    break;
                }
                k++;
            }
            if(isT) {
                n--;
            }
        }
    }
    if(n==0) {
        cout << "Y" <<endl;
    } else {
        cout << "N" <<endl;
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
