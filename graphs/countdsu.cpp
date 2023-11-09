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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

class DSU
{

public:
    vector<int> par, rank, size;

    DSU(int n)
    {
        par.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int find(int x)
    {
        if (par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void ubyr(int a, int b)
    {
        int upa = find(a);
        int upb = find(b);

        if (upa == upb)
            return;

        if (rank[upa] < rank[upb])
        {
            par[upa] = upb;
        }
        else if (rank[upa] > rank[upb])
        {
            par[upb] = upa;
        }
        else
        {
            par[upb] = upa;
            rank[upa]++;
        }
    }

    void ubys(int a, int b)
    {
        int upa = find(a);
        int upb = find(b);

        if (upa == upb)
            return;

        if (size[upa] <= size[upb])
        {
            size[upb] += size[upa];
            par[upa] = upb;
        }
        else
        {
            size[upa] += size[upb];
            par[upb] = upa;
        }
    }
};

int sol(vector<string> &vec)
{
    int n = vec.size();
    int m = vec[0].size();
    int ans = 0;

    DSU ds(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == '.')
            {
                if (i + 1 < n && vec[i + 1][j] == '.')
                ds.ubyr(i*m+j, (i+1)*m + j);

                if (i - 1 >= 0 && vec[i - 1][j] == '.')
                ds.ubyr(i*m+j, (i-1)*m + j);

                if (j + 1 < m && vec[i][j + 1] == '.')
                ds.ubyr(i*m+j, i*m + j+1);

                if (j - 1 >= 0 && vec[i][j - 1] == '.')
                ds.ubyr(i*m+j, i*m + j-1);
            }
        }
    }

    vector<int> parr = ds.par;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vec[i][j]=='.')
            {
                if(parr[i*m+j] == i*m+j)
                ans++;
            }
        }
    }

    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    cout << sol(vec);

    return;
}

signed main()
{
    fastio();
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}