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
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define ps(x) cout << (x) << " "
#define pen(x) cout << (x) << en
#define p2(x, y) cout << (x) << " " << (y) << en
#define int long long
#define ln(s) (int)(s.length())
#define mpi map<int, int>
#define vpi vector<pair<int, int>>

class Segtree{
    public:

    struct node{
        int mx;
        node(){
            this->mx =0;
        }
        node(int val)
        {
            this->mx = val;
        }
    };

    vector<node> segarr;


    Segtree(int n)
    {
        segarr.resize(4*n+3);
    }

    node merge(node &a,node &b)
    {
        node ans;
        ans.mx= max(a.mx,b.mx);
        return ans;
    }

    void build(int id,int l,int r,vi &vec)
    {
        if(l==r)
        {
            segarr[id] = node(vec[l]);
            return;
        }

        int md= l + (r-l)/2;
        build(2*id,l,md,vec);
        build(2*id+1,md+1,r,vec);
        segarr[id] = merge(segarr[2*id],segarr[2*id+1]);
        return;
    }

    void update(int id,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            segarr[id].mx -= val;
            return;
        }

        if(pos<l || pos>r)
        return;

        int md = l+(r-l)/2;
        if(pos<=md)
        update(2*id,l,md,pos,val);
        if(pos>md)
        update(2*id+1,md+1,r,pos,val);
        segarr[id] = merge(segarr[2*id],segarr[2*id+1]);
        return;
    }

    int query(int id,int l,int r,int x)
    {
        if(l==r)
        {
            return segarr[id].mx >= x ? l : -1;
        }

        int lt = segarr[2*id].mx;
        int rt = segarr[2*id+1].mx;

        int md = l+(r-l)/2;

        if(lt>=x)
        return query(2*id,l,md,x);

        if(rt>=x)
        return query(2*id+1,md+1,r,x);

        return -1;
    }

};

void solve()
{
    
    int n,m;
    cin >> n>>m;
    vi vec(n);
    vi grp(m);
    take(vec);
    take(grp);
    vi ans;

    Segtree at(n);
    at.build(1,0,n-1,vec);

    for(auto i: grp)
    {
        int pos = at.query(1,0,n-1,i);
        if(pos==-1)
        {
            ans.pb(0);
            continue;
        }
        ans.pb(pos+1);
        at.update(1,0,n-1,pos,i);
    }
    show(ans);
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