#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, k;
int arr[200005];

int32_t main(){
    scanf("%d%d", &n, &k);
    pbds s;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        s.insert({arr[i], i});
        if(i >= k){
            auto it = s.lower_bound({arr[i-k], -1});
            s.erase(it);
        }
        if(i >= k - 1){
            auto it = s.find_by_order((k-1)/2);
            printf("%d ", (*it).first);
        }
    }
}