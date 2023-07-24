#include<bits/stdc++.h>
using namespace std;
#define int long long

int ymax, xmax, startY, startX;
char mp[1005][1005];
char direct[1005][1005];
int xv[] = {0, 0, -1, 1};
int yv[] = {1, -1, 0, 0};
char directWord[] = {'D', 'U', 'L', 'R'};
struct pos{
    int y, x, type;
};

bool isArrived(pos now){
    if(now.type && (now.x==0 || now.x==xmax-1 || now.y==0 || now.y==ymax-1)){
        return true;
    }
    return false;
}

bool canMove(int y, int x){
    if(0<=y && y<ymax && 0<=x && x<xmax && mp[y][x]!='#'){
        return true;
    }
    return false;
}

int32_t main(){
    queue<pos> q;
    scanf("%lld %lld", &ymax, &xmax);
    for(int i=0;i<ymax;i++){
        scanf("%s", &mp[i]);
        for(int j=0;j<xmax;j++){
            if(mp[i][j] == 'M'){
                q.push({i, j, 0});
            }
            if(mp[i][j] == 'A'){
                startY = i;
                startX = j;
            }
        }
    }
    q.push({startY, startX, 1});
    while(!q.empty()){
        pos now = q.front();
        q.pop();
        if(isArrived(now)){
            vector<char> ans;
            int y = now.y, x = now.x;
            while(1){
                if(y == startY && x == startX){
                    break;
                }
                ans.push_back(direct[y][x]);
                if(direct[y][x] == 'U'){
                    y++;
                }
                else if(direct[y][x] == 'D'){
                    y--;
                }
                else if(direct[y][x] == 'L'){
                    x++;
                }
                else if(direct[y][x] == 'R'){
                    x--;
                }
            }
            printf("YES\n%lld\n", ans.size());
            for(int i=ans.size()-1;i>=0;i--){
                printf("%c", ans[i]);
            }
            exit(0);
        }
        mp[now.y][now.x] = '#';
        for(int i=0;i<4;i++){
            int nxtY = now.y + yv[i];
            int nxtX = now.x + xv[i];
            if(canMove(nxtY, nxtX)){
                if(now.type){
                    direct[nxtY][nxtX] = directWord[i];
                }
                mp[nxtY][nxtX] = '#';
                q.push({nxtY, nxtX, now.type});
            }
        }
    }
    printf("NO\n");
}