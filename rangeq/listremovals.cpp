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


/*

     4
   2   2
  1 1 1 1

1st
     3
   1   2 //1
  0 1 1 1

2nd
     2
   1   1 //2-1   x-k
  0 1 0 1

    

*/


class Segtree{

    public:

    vi segarr;

    Segtree(int n)
    {
        segarr.resize(4*n+2,0);
    }

    void build(int id,int l,int r)
    {
        if(l==r)
        {
            segarr[id]=1;
            return;
        }

        int mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        segarr[id]=segarr[2*id]+segarr[2*id+1]; 

    }

    int query(int id,int l,int r,int x)
    {
       if(l==r)
       {
            return l;//index of the element
       }

       if(l>r)
       return -1;

        int md = (l+r)>>1;
        int lft = segarr[2*id];
        if(x<=lft)
        {
            return query(2*id,l,md,x);
        }
        else
        {
            return query(2*id+1,md+1,r,x-segarr[2*id]);
        }
    }
    

    void update(int id,int l,int r,int pos)
    {
        if(pos<l || pos>r)
        return;

        if(l==r)
        {
            segarr[id]=0;
            return;
        }   

        int md = (l+r)>>1;

        if(pos<=md)
        update(2*id,l,md,pos);
        else
        update(2*id+1,md+1,r,pos);
        segarr[id] = segarr[2*id]+segarr[2*id+1];
    }



};

void solve()
{

    int  n;
    cin >> n;
    vi vec(n);
    take(vec);

    vi pos(n);
    take(pos);
    Segtree at(n);
    at.build(1,0,n-1);

    vi ans;

    for(auto p: pos)
    {
        int xx = at.query(1,0,n-1,p);
        // show(at.segarr);
        
        if(xx!=-1)
        ans.pb(vec[xx]);
        at.update(1,0,n-1,xx);
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
