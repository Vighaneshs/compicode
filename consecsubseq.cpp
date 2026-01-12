#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n; i++) cin >> a[i];

    unordered_map<int, int> mp;
    mp[a[0]] = 1;
    int mx = 1, mv = a[0];
    for(int i = 1; i < n; i++){
        if(mp.find(a[i]-1) != mp.end()) mp[a[i]] = mp[a[i]-1]+1;
        else mp[a[i]] = 1;
        if(mp[a[i]] > mx){
            mx = mp[a[i]];
            mv = a[i];
        }
    }

    vector<int> fans;

    for(int i = n; i>=0; i--){
        if(a[i] == mv){
            fans.push_back(i+1);
            mv--;
        }
    }
    reverse(fans.begin(), fans.end());

    cout << fans.size() << endl;

    for(const auto & a: fans) cout << a << " ";

    return 0;
}