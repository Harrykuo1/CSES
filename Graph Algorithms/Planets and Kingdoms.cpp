#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;

bool visited[1000005];
int pos[1000005];
int id[1000005];

vector<int> order;
vector<int> groups;

void dfs1(vector<vector<int>> &edges, int id){
    if(visited[id]){
        return;
    }
    visited[id] = true;
    for(auto x:edges[id]){
        dfs1(edges, x);
    }
    order.push_back(id);
}

void dfs2(vector<vector<int>> &inverse_edges, int id, int groupID){
    pos[id] = groupID;
    for(int x:inverse_edges[id]){
        if(pos[x] == -1){
            dfs2(inverse_edges, x, groupID);
        }
    }
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    vector<vector<int>> edges(n+5);
    vector<vector<int>> inverse_edges(n+5);
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        edges[a].push_back(b);
        inverse_edges[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(edges, i);
        }
    }
    memset(pos, -1, sizeof(pos));
    reverse(order.begin(), order.end());
    for(int x:order){
        if(pos[x] == -1){
            dfs2(inverse_edges, x, x);
            groups.push_back(x);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!id[pos[i]]){
            id[pos[i]] = ++ans;
        }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", id[pos[i]]);
	}
}