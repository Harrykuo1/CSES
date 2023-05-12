#include<stdio.h>
#include<vector>
#include<climits>
using namespace std;
 
#define int long long 
signed main(){
    int n, m, q, u, v, w;
    scanf("%lld%lld%lld",&n,&m,&q);
    vector<vector<int> > dis(n+1, vector<int>(n+1, LLONG_MAX));
    for(int i=0;i<=n;i++){
        dis[i][i] = 0;
    }
    while(m--){
        scanf("%lld%lld%lld",&u,&v,&w);
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    while(q--){
        scanf("%lld%lld",&u,&v);
        printf("%lld\n", dis[u][v] != LLONG_MAX? dis[u][v] : -1 );
    }
 
}