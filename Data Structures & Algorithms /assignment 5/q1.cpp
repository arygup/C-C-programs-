#include <iostream>
#define ll long long int
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int mx = 1e5 + 5;
vector <pair<ll,ll> >v[mx]; vector <ll>cul;
ll n, m, x, y, vis[mx], ans; 
void dfs(ll p, ll col)
{
    if(p == y)
    {
        ans ++; 
        cul.push_back(col); 
        return;
    }
    vis[p] = col;
    for (ll i = 0; i < v[p].size(); i++)
    { 
        ll chch = 0;
        for (ll j = 0; j < cul.size(); j++)
        {
            if(cul[j] == v[p][i].second)
            {
                chch = 1; 
                break;
            } 
        }
        if(chch) continue;
        if(vis[v[p][i].first] != col && (v[p][i].second == col  || col == -1)) 
        {
            //cout << v[p][i].first << "..";
            dfs(v[p][i].first, v[p][i].second);
        }
    }
}

int main() 
{    
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c; cin >> a >> b >> c; 
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    //printgraph();
    ll t; cin >> t;
    for (ll siz = 0; siz < t; siz++)
    {
        cin >> x >> y; ans = 0; //cout << endl << x << endl;
        for (ll i = 0; i < n; i++) vis[i+1] = 0;
        dfs(x, -1);
        cout << endl << ans;
        cul.clear();
    }
    
}