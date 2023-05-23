#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input;
    cin >> input;
    sort(input.begin(), input.end());
    vector<string> ans;
    do{
        ans.push_back(input);
    }while(next_permutation(input.begin(), input.end()));

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}
