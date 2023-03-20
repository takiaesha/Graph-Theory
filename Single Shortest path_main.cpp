#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
vector<int> v[10005];
int visit[100005], dis[100005];
void dfs(int node, int d)
{
    visit[node] = 1;
    dis[node] = d;

    for(int i=0; i<v[node].size(); i++){
        int child = v[node][i];
        if(visit[child]==0) dfs(child,d+1);
    }

}
int main()
{
    sync;
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }

    int rt;
    cin>>rt;

    dfs(rt,0);

    for(int i=1; i<=n; i++){
        cout<< rt << " -> "<< i << " = "<< dis[i] << "\n";
    }

    cout<< endl;

    return 0;
}
