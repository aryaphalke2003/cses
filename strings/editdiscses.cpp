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


// int dp[5001][5001];

// int sol(string a,string b,int ap,int bp)
// {
//     if(ap==a.size())
//     {
//         return dp[ap][bp] = b.size()-bp;
//     }

//     if(bp==b.size())
//     {
//         return dp[ap][bp] = a.size()-ap;
//     }

//     if(dp[ap][bp]!=-1)
//     return dp[ap][bp];

//     int ans = 0;

//     if(a[ap]==b[bp])
//     ans += sol(a,b,ap+1,bp+1);
//     else
//     ans += 1 + min({sol(a,b,ap+1,bp),sol(a,b,ap+1,bp+1),sol(a,b,ap,bp+1)});

//     return dp[ap][bp] = ans;

    
// }


void solve()
{
    string a,b;
    cin >> a >> b;
    

    int n = a.size();
    int m = b.size();

    vector<vi> dp(n+1,vi (m+1,0));

    for(int i=0;i<=m;i++)
    {
        dp[n][i] = m-i;
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][m] = n-i;
    }
    
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(a[i]==b[j])
            dp[i][j] = dp[i+1][j+1];
            else
            dp[i][j] = 1 + min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
        }
    }

    pen(dp[0][0]);

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