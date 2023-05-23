#include<bits/stdc++.h>
using namespace std;
#define int long long

int ymax, xmax;
char mp[1005][1005];

int xv[] = {0, 0, -1, 1};
int yv[] = {1, -1, 0, 0};

bool check(int y, int x){
    if(0<=y && y<ymax && 0<=x && x<xmax){
        return true;
    }
    return false;
}

void dfs(int y, int x){
    mp[y][x] = '#';
    for(int i=0;i<4;i++){
        int newX = x+xv[i];
        int newY = y+yv[i];
        if(check(newY, newX) && mp[newY][newX]=='.'){
            dfs(newY, newX);
        }
    }
}

signed main(){
    int ans = 0;
    scanf("%lld %lld", &ymax, &xmax);
    for(int i=0;i<ymax;i++){
        scanf("%*[\n]");
        for(int j=0;j<xmax;j++){
            scanf("%c", &mp[i][j]);
        }
    }
    for(int i=0;i<ymax;i++){
        for(int j=0;j<xmax;j++){
            if(mp[i][j] == '.'){
                ans++;
                dfs(i,j);
            }
        }
    }
    printf("%lld\n", ans);
}