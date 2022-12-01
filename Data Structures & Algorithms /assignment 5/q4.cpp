#include <iostream>
#define ll long long int
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
vector <pair<ll,ll> >v[mx]; set <pair<ll,ll> >st; ll n, m, k; 
// void printgraph()
// {
//     for (ll i = 0; i < n; i++)
//     {
//         cout << i+1 << endl;
//         for (ll j = 0; j < v[i+1].size(); j++)
//         {
//             pair<ll,ll >p = v[i+1][j];
//             cout << p.first << p.second << endl;
//         }
//     }
// }

int main() 
{  
    ios::sync_with_stdio(0);
    cin.tie(0);  
    cin >> n >> m >> k; vector <ll> dist(n+1, __LONG_LONG_MAX__); vector<ll> vis(n+1,0);
    for (ll i = 0; i < k; i++)
    {
        ll a; cin >> a;
        st.insert(make_pair(0, a));
    }
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b >> c; 
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    while (st.size())
    {
        pair <ll,ll> b = *st.begin();ll nd = b.second, w = b.first;
        if(vis[nd])
        {
            st.erase(st.begin());
            continue;
        }
        st.erase(st.begin()); 
        vis[nd]++;
        if(w < dist[nd]) dist[nd] = w;
        //else continue;
        //cout << b.first << b.second << endl;
        for (ll i = 0; i < v[nd].size(); i++)
        {
            pair<ll,ll >p = v[nd][i];
            if(w + p.second < dist[p.first])
            {
                dist[p.first] = w + p.second;
            }
            st.insert(make_pair(dist[p.first], p.first));
        }
    }
    for (ll i = 1; i <= n; i++) cout << dist[i] << " ";
}