#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// GCC OPTIMISATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

// MACROS
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define vli vector<long long int>
#define vi vector<int>
#define mod 1000000007
#define INF 1000000000000000003
#define pi pair<int, int>
#define umap unordered_map
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define loop(i, a, b) for (auto i = a; i < b; i++)
#define revloop(i, a, b) for (auto i = a; i >= b; i--)
#define en '\n'
#define deb cout << "checking code"
#define vvi vector<vector<int>>
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define take(x)       \
    for (auto &y : x) \
    cin >> y
#define sz(x) (int)((x).size())
#define show(x)           \
    for (auto y : x)      \
        cout << y << " "; \
    cout << endl
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define ps(x) cout << (x) << " "
#define pen(x) cout << (x) << en
#define p2(x, y) cout << (x) << " " << (y) << en
#define int long long
#define ln(s) (int)(s.length())
#define mpi map<int, int>
#define vpi vector<pair<int, int>>


class Segtree
{

//Segtree at(n);
//at.build(1,0,n-1,arr);
//at.buildnoarr(1,0,n-1);
private:
    struct node
    {
        int sum;
        int mx;
        int mn;
        int andd;

        node()
        {
            this->sum = 0;
            this->mx = -INF;
            this->mn = INF;
            this->andd = (1ll << 32) - 1;
        }

        node(int val)
        {
            this->sum = val;
            this->mx = val;
            this->mn = val;
            this->andd = val;
        }

    };
    vector<node> segarr;

public:
    Segtree(int n)
    {
        segarr.resize(4 * n + 4);
    }

    node merge(node &a, node &b)
    {
        node ans;
        ans.sum = a.sum + b.sum;
        ans.mx = max(a.mx, b.mx);
        ans.mn = min(a.mn, b.mn);
        ans.andd = a.andd & b.andd;
        return ans;
    }

    void buildnoarr(int id,int l,int r)
    {
        if(l==r)
        {
            segarr[id]=node();
            return;
        }

        int md = (l + r) / 2;
        buildnoarr(2 * id, l, md);
        buildnoarr(2 * id + 1, md + 1, r);
        segarr[id] = merge(segarr[2 * id], segarr[2 * id + 1]);


    }

    void build(int id, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            segarr[id] = node(arr[l]);
            return;
        }

        int md = (l + r) / 2;
        build(2 * id, l, md, arr);
        build(2 * id + 1, md + 1, r, arr);
        segarr[id] = merge(segarr[2 * id], segarr[2 * id + 1]);
    }

    void update(int id, int l, int r, int pos, int val)
    {
        if (pos < l || pos > r)
        {
            return;
        }

        if (l == r)
        {
            segarr[id].sum += val;
            segarr[id].mx = max(segarr[id].mx, val);
            segarr[id].mn = max(segarr[id].mn, val);
            segarr[id].andd = segarr[id].andd & val;
            return;
        }

        int md = (l + r) / 2;
        if (pos <= md)
            update(2 * id, l, md, pos, val);
        else
            update(2 * id + 1, md + 1, r, pos, val);

        segarr[id] = merge(segarr[2 * id], segarr[2 * id + 1]);
    }

    node query(int id, int l, int r, int lq, int rq)
    {
        if (l > rq || lq > r)
        {
            return node();
        }

        if (lq <= l && rq >= r)
        {
            return segarr[id];
        }

        int md = (l + r) / 2;

        node a = query(2 * id, l, md, lq, rq);
        node b = query(2 * id + 1, md + 1, r, lq, rq);

        return merge(a, b);
    }
};

void solve()
{
    
    int n,q;
    cin >> n >> q;

    vi vec(n);
    take(vec);

    Segtree ta(n);
    ta.build(1,0,n-1,vec);

    while(q--)
    {
        int a,b;
        cin >> a>> b;
        
        cout << ta.query(1,0,n-1,a-1,b-1).mn<<endl;
    }


    return;
}

signed main()
{
    fastio();
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}