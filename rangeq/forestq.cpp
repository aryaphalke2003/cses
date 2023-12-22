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


void solve()
{
    int n,q;
    cin >> n >> q;

    vector<vector<int>> vec(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;

        for(int j=0;j<n;j++)
        if(s[j]=='*')
        vec[i][j]=1;
    }
    

    vector<vector<int>> pre(n+1,vector<int>(n+1,0));

    //2d prefix sum

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pre[i][j] = vec[i-1][j-1];
            pre[i][j] += pre[i][j-1];//one shot
            pre[i][j] += pre[i-1][j];//one shot
            pre[i][j] -= pre[i-1][j-1];//double counted
        }   
    }

    // for(int i=1;i<=n;i++)
    // for(int j=0;j<=n;j++)
    // pre[i][j] += pre[i-1][j];

    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        pen(pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1]);
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