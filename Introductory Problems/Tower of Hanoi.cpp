#include<bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int >arr;
vector<int >brr;

void hanoi(int n, int a, int b, int c){
    if(n == 1){
        ans++;
        arr.push_back(a);
        brr.push_back(c);
        return;
    }
    hanoi(n-1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n-1, b, a, c);
}

signed main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);

    printf("%d\n", ans);
    for(int i=0;i<ans;i++){
        printf("%d %d\n", arr[i], brr[i]);
    }
}