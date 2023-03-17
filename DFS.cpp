#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
vector<int> v[1000005];
int visit[100005];

void dfs(int node){
    //cout<< "\nNode = "<< node << endl;
    visit[node] = 1;
    cout<< "Node size = "<< v[node].size()<< endl;

    cout<< node << " -> ";

    for(int i=0; i<v[node].size(); i++){

        int child = v[node][i];
        cout<<"Child = "<< child << "   ";
    cout<< "I = "<< i << endl;
        if(visit[child]==0) dfs(child);
    }

}
int main()
{
    sync;
    int n,e;
    cin>>n>>e;
    int x,y;
    while(e--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    return 0;
}
