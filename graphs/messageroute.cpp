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
#define ll long long int
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


void print(vector<int> &par,int x)
{
    vi vv;
    vv.pb(x);
    int i=x;
    while(i!=-1)
    {
        vv.pb(par[i]);
        i=par[i];
    }
    vv.pop_back();
    reverse(vv.begin(),vv.end());
    pen(vv.size());
    for(auto i: vv)
    cout<<i+1<<" ";
   
}

void solve()
{
    
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n,0);
    vector<int> par(n,-1);
    vis[0]=1;
    queue<int> q;
    q.push(0);
    while(q.size())
    {
        auto it= q.front();
        q.pop();

        vis[it]=1;
        for(auto i: adj[it])
        {
            if(vis[i])
            continue;

            vis[i]=1;
            par[i]=it;
            q.push(i);

            if(i==n-1)
            {
                print(par,n-1);
                return;
            }
        }
    }

    pen("IMPOSSIBLE");
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