#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
using namespace std;
vector<int> v[100000];
int visit[100000];

void dfs(int node)
{
    visit[node] = 1;
    for(auto child:v[node]){
        if(visit[child]==0) dfs(child);
    }
}
int main()
{
    sync;
    int n,e;
    cin>>n>>e;
    int m = e;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int cc = 0;
    for(int i=1; i<=n; i++){
        if(visit[i]==0){
            cc++;
            dfs(i);
        }
    }

    if(cc==1 && m==n-1) cout<< "YES\n";
    else cout<< "NO\n";


    return 0;
}
