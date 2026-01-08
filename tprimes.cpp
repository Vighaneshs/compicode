#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1e6;
bool isPrime[MAXN + 1];

void sieve() {
    for (int i = 0; i <= MAXN; ++i) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= MAXN; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                isPrime[i] = false;
        }
    }
}

int main(){
    sieve();
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    for(int i = 0; i < n; i++){
        long long int sr = sqrt(a[i]);
        if(sr*sr == a[i] && isPrime[sr]) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}

