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

map<pair<int,int>,pair<int,int>> mp;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

void print(int x,int y)
{
    string s="";

    // for(auto i: mp)
    // cout << i.first.first << ":" << i.first.second << "->" << i.second.first << i.second.second << endl;
    while(mp.find({x,y}) != mp.end())
    {
        auto p = mp[{x,y}];
        int ppx = p.first;
        int ppy = p.second;

        if(ppx==x)
        {
            if(ppy<y)
            s+="R";
            else
            s+="L";

        }
        else
        {
            if(ppx<x)
            s+="D";
            else
            s+="U";
        }

        x=ppx;
        y=ppy;
    }

    reverse(s.begin(),s.end());
    py;
    cout << s.size() << endl;
    cout<< s << endl;
    return;
}

void sol(int sx,int sy,int tx,int ty,int n,int m,vector<string> &vec)
{
    queue<pair<int,int>> q;
    q.push({sx,sy});
    mp.clear();

    while(q.size())
    {
        auto it=q.front();
        q.pop();

        int x = it.first;
        int y = it.second;

        vec[x][y] = 'v';

        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && vec[nx][ny]!='#' && vec[nx][ny]!='v')
            {
                q.push({nx,ny});
                mp[{nx,ny}]={x,y};
                vec[nx][ny]='v';

                if(nx==tx && ny==ty)
                {
                    
                    print(nx,ny);
                    return;
                }
            }
        }
    }

    pn;
}

void solve()
{

    int n,m;
    cin >> n >> m;

    vector<string> vec(n);

    int sx,sy,tx,ty;

    for(int i=0;i<n;i++)
    {
        cin >> vec[i];

        for(int j=0;j<m;j++)
        {
            if(vec[i][j]=='A')
            sx=i,sy=j;
            if(vec[i][j]=='B')
            tx=i,ty=j;
        }

    }
    if(sx==tx && sy==ty)
    {
        py;
        cout << 0 << endl;
        cout << "";
        return;
    }
    sol(sx,sy,tx,ty,n,m,vec);

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