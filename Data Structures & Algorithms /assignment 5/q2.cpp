#include<iostream>
#define ll long long int
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
vector <ll>v[mx]; 
ll n, k, x, ans = 0; set <pair<ll,ll> > st;
ll d[50001][1001];
void dfs(ll p, ll par)
{
    d[p][0] = 1;
    for (ll j = 0; j < v[p].size(); j++) 
    {
        ll i = v[p][j];
        if(i == par) continue;
        dfs(i, p);
        for (int j = 1; j <= k; j++) ans = ans + d[i][j - 1] * d[p][k - j];
        for (int j = 1; j <= k; j++) d[p][j] += d[i][j - 1];
    }
}
int main() 
{    
    ios::sync_with_stdio(0);
    cin.tie(0); 
    //printgraph();
    ll t; cin >> t;
    for (ll siz = 0; siz < t; siz++)
    {
        cin >> n >> k; //ll D[n+1][5000];
        if(k == 0) 
        {
            for (ll i = 0; i < n-1; i++){ ll a, b; cin >> a >> b; }
            cout << n << endl;
            continue;
        }
        for (ll i = 0; i < n-1; i++)
        {
            ll a, b; cin >> a >> b; 
            v[a].push_back(b);
            v[b].push_back(a);
        }
        //cin >> x >> y; //ans = 0; //cout << endl << x << endl; gfg ref used;
        // for (ll i = 0; i < n; i++)
        // {
        //     x = i+1;
        //     dfs(x, k, -1);
        // }
        //cout << endl << st.size()/2;
        dfs(1,1);
        cout << ans << endl;
        for (ll i = 1; i <= n; i++)
        {
            v[i].clear();    
        }  
        for (ll i = 0; i < 50001; i++)
        {
           for (ll j = 0; j < 1001; j++)
           {
                d[i][j] = 0;
           }
        }
        //st.clear();
        ans = 0;
    }
}

