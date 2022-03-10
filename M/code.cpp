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

struct Node {
    int val;
    int cnt = 1;
    Node* left = nullptr;
    Node* right = nullptr;
};
Node* root = nullptr;

void buildTree(Node* &root, Node* val) {
    if(root == nullptr) {
        root = val;
        //debug1(root->val);
        return;
    }
    if(root->val == val->val) {
        root->cnt++;
    }
    if(root->val > val->val) {
        buildTree(root->left, val);
    }
    if(root->val < val->val) {
        buildTree(root->right, val);
    }
}
vector<int> inorder;
vector<int> preorder;
void Inorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    Inorder(root->left);
    //debug2(root->val, root->cnt);
    for(int i = 0; i < root->cnt; i++) {
        inorder.push_back(root->val);
    }
    Inorder(root->right);
}

void Preorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    for(int i = 0; i < root->cnt; i++) {
        preorder.push_back(root->val);
    }
    Preorder(root->left);
    Preorder(root->right);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //BST* tree;
    
    for(int i = 0; i < n; i++) {
        Node* v = new Node();
        v->val = a[i];
        //debug1(v->val);
        buildTree(root, v);
        if(root == nullptr) {
        debug1("Not OK");
    }
        //debug1("ok1");
    }
    if(root == nullptr) {
        debug1("Not OK");
    }
    Inorder(root);
    Preorder(root);
    for(int i = 0; i < inorder.size(); i++) {
        cout << inorder[i];
        if(i!=inorder.size()-1) cout << ",";
    }
    cout << endl;
    for(int i = 0; i < preorder.size(); i++) {
        cout << preorder[i];
        if(i!=preorder.size()-1) cout << ",";
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
