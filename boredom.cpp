#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    vector<long long int>scores(100001, 0);
    for(int i = 0; i <n; i++)
    {
        cin >> a[i];
        scores[a[i]] += a[i];
    }
    long long int dp[100003];
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= 100002; i++){
        if(scores[i-2] > 0)
        {
            dp[i] = max(dp[i-2] + scores[i-2], dp[i-1]);
        } else{
            dp[i] = dp[i-1];
        }
    }
    cout << dp[100002];
    return 0;
}