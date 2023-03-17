#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
vector<int> v[100005];
int visit[100006];

void dfs(int node){
    visit[node] = 1;
    cout<< node << " -> ";
    for(int i=0; i<v[node].size(); i++){
        int child = v[node][i];
        if(visit[child]==0) dfs(child);
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
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);


    return 0;
}
