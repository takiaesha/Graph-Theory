#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
vector<int> v[10000000];
ll visit[10000000], col[10000000];

bool dfs(ll node,ll c)
{
    visit[node] = 1;
    col[node] = c;

    for(auto child:v[node]){
        if(visit[child]==0){
            if(dfs(child,c^1)==false) return false;
        }else{
            if(col[node]==col[child]) return false;
        }
    }
    return true;

}

int main()
{
    sync;
    int tc,cs = 1;
    cin>>tc;
    while(tc--){
        ll n,e;
        cin>>n>>e;
        for(int i=1; i<=n; i++) v[i].clear(),visit[i] = 0;
        ll x,y;
        while(e--){
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        bool ans = true;
        for(ll i=1; i<=n; i++){
            if(visit[i]==0){
                ans = dfs(i,1);
            }
            if(ans==false) break;
        }
        //cout<< ans << endl;
        cout<< "Scenario #"<< cs <<":\n";

        if(ans==true) cout<< "No suspicious bugs found!\n";
        else cout<< "Suspicious bugs found!\n";
        cs++;

    }
    return 0;
}

