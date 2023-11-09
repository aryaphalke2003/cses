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

// map<pair<int, int>, pair<int, int>> path;

vector<vector<pair<int, int>>> path;

void print(int tim, int x, int y)
{
    string s = "";
    // cout<<"ssss" ;

    // for(auto i: path)
    // cout << i.first.first <<":" << i.first.second << "->" << i.second.first << ":" << i.second.second << endl;
    // while (path.find({x, y}) != path.end())
    while (path[x][y].first != -1)
    {

        pair<int, int> pp = path[x][y];

        int ppx = pp.first;
        int ppy = pp.second;

        if (ppx == x)
        {
            if (ppy < y)
                s += "R";
            else
                s += "L";
        }
        else
        {
            if (ppx < x)
                s += "D";
            else
                s += "U";
        }
        x = ppx;
        y = ppy;
    }
    reverse(s.begin(), s.end());
    py;
    cout << tim << endl;
    cout << s << endl;
    return;
}

void func(vector<vector<int>> &mons, vector<string> &mp, int sx, int sy, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    path.clear();
    
    pair<int,int> pp = {-1,-1};
    path.resize(n, vector<pair<int,int>> (m, pp)); //pair<int,int> here
    int tim = 1;

    // cout << "Dfg"

    while (q.size())
    {
        int ss = q.size();
        // cout << "sdfs" << ss << endl;
        while (ss--)
        {
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            mp[x][y] = 'x';

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && mp[nx][ny] != '#' && mp[nx][ny] != 'x')
                {
                    if (mons[nx][ny] == -1 || mons[nx][ny] > tim)
                    {
                        mp[nx][ny] = 'x';
                        path[nx][ny] = {x, y};
                        q.push({nx, ny});

                        if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)
                        {
                            print(tim, nx, ny);
                            return;
                        } // nx ny bsdk
                    }
                }
            }
        }
        tim++;
    }
    cout << "NO\n";
    return;
}

void sol(int sx, int sy, int n, int m, vector<string> &mp)
{
    vector<vector<int>> mons(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'M')
                mons[i][j] = 0, q.push({i, j});
        }
    }
    while (q.size())
    {
        auto it = q.front();
        q.pop();

        int x = it.first;
        int y = it.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (mons[nx][ny] == -1 && (mp[nx][ny] == '.' || mp[nx][ny] == 'A'))
            {
                mons[nx][ny] = mons[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << mons[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    func(mons, mp, sx, sy, n, m);
}

void solve()
{

    int n, m;
    cin >> n >> m;

    vector<string> mp(n);
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        cin >> mp[i];
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'A')
                sx = i, sy = j;
        }
    }

    if (sx == 0 || sx == n - 1 || sy == 0 || sy == m - 1)
    {
        cout << "YES\n";
        cout << 0 << endl;
        cout << "" << endl;
        return;
    }
    // cout << sx << sy << endl;

    sol(sx, sy, n, m, mp);

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