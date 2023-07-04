#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

int32_t main(){
    scanf("%lld", &n);
    vector<string> arr;
    arr.push_back("0");
    arr.push_back("1");
    for(int i=2;i<(1<<n);i*=2){
        for(int j=i-1;j>=0;j--){
            arr.push_back("1" + arr[j]);
        }
        for(int j=0;j<i;j++){
            arr[j] = "0" + arr[j];
        }
    }
    for(int i=0;i<arr.size();i++){
        std::cout << arr[i] << "\n";
    }
}