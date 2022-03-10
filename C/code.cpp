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

struct Bignum {
    static const int BASE = 1000000000;
    static const int NBLOCK = 9;
    vector<int> data;
    Bignum() {data.push_back(0);}
    Bignum(long long x) {
        if (!x) data.push_back(0);
        while (x) data.push_back(x % BASE), x /= BASE;
    }
    void trim() {while (data.size() > 1 && !data.back()) data.pop_back();}
    int& operator[] (int i) {return data[i];}
    int len() {return data.size();}
    int iszero() const {return data.empty() || (data.size() == 1 && !data[0]);}
};
Bignum operator + (Bignum a, Bignum b) {
    if (a.len() < b.len()) swap(a, b);
    Bignum c; c.data = a.data, c.data.push_back(0);
    int r = 0;
    for (int i = 0; i < c.len(); i++) {
        c[i] += ((i < b.len()) ? b[i] : 0) + r;
        if ((r = (c[i] >= Bignum::BASE))) c[i] -= Bignum::BASE;
    }
    c.trim();
    return c;
}
Bignum operator * (Bignum a, int m) {
    long long r = 0;
    for (int i = 0; i < a.len(); i++) {
        r += (long long) a[i] * m;
        a[i] = r % Bignum::BASE;
        r /= Bignum::BASE;
    }
    while (r) a.data.push_back(r % Bignum::BASE), r /= Bignum::BASE;
    a.trim();
    return a;
}
pair<Bignum, int> divmod(Bignum a, int m) {
    long long r = 0;
    for (int i = a.len() - 1; i >= 0; i--) {
        r = r * Bignum::BASE + a[i];
        a[i] = r / m;
        r %= m;
    }
    a.trim();
    return make_pair(a, (int) r);
}
Bignum operator / (Bignum a, int m) {
    return divmod(a, m).first;
}
int operator % (Bignum a, int m) {
    return divmod(a, m).second;
}
Bignum operator * (const Bignum& a, const Bignum& b) {
    Bignum res;
    res.data.assign(a.data.size() + b.data.size(), 0);
    for (int i = 0; i < a.data.size(); i++) {
        long long carry = 0;
        for (int j = 0; j < b.data.size() || carry > 0; j++) {
            long long s = res[i + j] + carry + (long long) a.data[i] * (j < b.data.size() ? (long long) b.data[j] : 0);
            res[i + j] = s % Bignum::BASE;
            carry = s / Bignum::BASE;
        }
    }
    res.trim();
    return res;
}
ostream& operator << (ostream& stream, const Bignum& a) {
    stream << (a.data.empty() ? 0 : a.data.back());
    for (int i = (int) a.data.size() - 2; i >= 0; i--) stream << setw(Bignum::NBLOCK) << setfill('0') << a.data[i];
    return stream;
}

void solve() {
    ll x, n;
    cin >> x >> n;
    vector<Bignum> a(n+1);
    a[0] = Bignum(1);
    for(int i = 1; i <= n; i++) {
        a[i] = i*a[i-1];
        //debug1(a[i]);
    }
    Bignum ans = Bignum(x);
    for(int i = 1; i <= n; i++) {

        Bignum es = a[i]/x;
        //debug1(es);
        ans = ans + es;
        //debug1(ans);
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
