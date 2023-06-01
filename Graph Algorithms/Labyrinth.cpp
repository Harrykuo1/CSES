#include<bits/stdc++.h>
using namespace std;
#define int long long

int dirs[][2] ={{-1, 0},{1, 0},{0, 1},{0, -1}};
int path[1005][1005];
int dis[1005][1005];
char mp[1005][1005];
int ymax, xmax, sy, sx, ey, ex;

void init(){
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            dis[i][j] = INT_MAX;
        }
    }   
}

bool inRange(int y, int x){
    if(0<=y && y<ymax && 0<=x && x<xmax){
        return true;
    }
    return false;
}

int32_t main(){
    init();
    scanf("%lld %lld", &ymax, &xmax);
    for(int i=0;i<ymax;i++){
        scanf("%s", &mp[i]);
        for(int j=0;j<xmax;j++){
            if(mp[i][j] == 'B'){
                sy = i;
                sx = j;
            }
            else if(mp[i][j] == 'A'){
                ey = i;
                ex = j;
            }
        }
    }
    queue<pair<int, int>> q;
    dis[sy][sx] = 0;
    q.push({sy, sx});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newY = y + dirs[i][0];
            int newX = x + dirs[i][1];
            if(inRange(newY, newX) && mp[newY][newX]!='#' && dis[newY][newX] > dis[y][x] + 1){
                dis[newY][newX] = dis[y][x] + 1;
                mp[newY][newX]='#';
                path[newY][newX] = i + 1;
                q.push({newY, newX});
            }
        }
    }
    if(dis[ey][ex] != INT_MAX){
        printf("YES\n");
        printf("%lld\n", dis[ey][ex]);
        while(path[ey][ex]){
            if(path[ey][ex] == 1){
                printf("D");
                ey++;
            }
            else if(path[ey][ex] == 2){
                printf("U");
                ey--;
            }
            else if(path[ey][ex] == 3){
                printf("L");
                ex--;
            }
            else if(path[ey][ex] == 4){
                printf("R");
                ex++;
            }
        }
    }
    else{
        printf("NO\n");
    }
}