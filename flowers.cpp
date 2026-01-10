#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long int> dp(100001, 0);
    long long int md = 1e9 + 7;
    int t, k;
    cin >> t >> k;

    for(int i = 0; i < k; i++)
        dp[i] = 1;
    
    dp[k] = 2;

    for(int i = k+1; i <= 100000; i++){
        dp[i] = (dp[i-1]%md + dp[i-k]%md)%md;
    }   
    vector<long long int> pref(100001, 0);

    pref[1] = dp[1];
    for(int i = 2; i <= 100000; i++) pref[i] = (pref[i-1]%md + dp[i]%md)%md;
    
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        int tc = 0;

        cout << (pref[b] - pref[a-1]+md)%md << "\n";

    }

    return 0;
}