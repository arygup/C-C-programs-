```
#include <bits/stdc++.h>
#include <set>
#include <list>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> adj[100005];

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    // vector<int> adj[n+1]; // adjacency list
    set<pair<ll, ll>> st;
    vector<ll> ans(n + 1);
    ll weights[n + 1][n + 1];
    ll mess;
    for (ll i = 0; i < n + 1; i++)
    {
        for (ll j = 0; j < n + 1; j++)
        {
            weights[i][j] = 0;
        }
    }
    for (ll i = 0; i < k; i++)
    {
        cin >> mess;
        // cout << mess << endl;
        adj[mess - 1].push_back(n);
        adj[n].push_back(mess - 1);
        weights[mess - 1][n] = 0;
        weights[n][mess - 1] = 0;
    }
    // creating adj list
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        // cout << u << v << w << endl;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        weights[u - 1][v - 1] = w;
        weights[v - 1][u - 1] = w;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i + 1 << " ";
    //     for (ll j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j]+1 << " ";
    //     }
    //     cout << endl;
    // }

    for (ll i = 0; i < n; i++)
    {
        ans[i] = LLONG_MAX;
    }
    ll source = n;
    ans[source] = 0;
    st.insert(make_pair(0, source));

    ll vis[n + 1];
    for (ll i = 0; i < n + 1; i++)
    {
        vis[i] = 0;
    }
    while (!st.empty())
    {
        auto top = *(st.begin());
        ll dist = top.first;
        ll node = top.second;
        st.erase(st.begin());

        if (!vis[node])
        {
            if(ans[node] < dist) ans[node] = dist;
            for (auto neighbour : adj[node])
            {
                if (dist + weights[neighbour][node] < ans[neighbour])
                {
                    ans[neighbour] = dist + weights[neighbour][node];
                }
                st.insert(make_pair(weights[neighbour][node], neighbour));
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
```