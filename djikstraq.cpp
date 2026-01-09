#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

long long INF = 1e18;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int,int>>());
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<long long> dist(n+1, INF);
    vector<int> par(n+1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, 1});

    while(!pq.empty()){
        auto tp = pq.top();
        int ce = tp.second;
        long long cw = tp.first;
        pq.pop();
        for(const auto & a: adj[ce]){
            
            if(cw + a.second > dist[a.first]) continue;

            dist[a.first] = cw + a.second;
            pq.push({dist[a.first], a.first});

            par[a.first] = ce;
            
        }
    }

    if(dist[n] == INF) {cout <<  -1; return 0;} 

    vector<int> soln;
    int curr = n;

    while(curr != 1){
        soln.push_back(curr);
        curr = par[curr];
    }
    cout << 1 << " ";

    for(int i = soln.size()-1; i>=0; i--) cout << soln[i] << " ";
    
    

    return 0;
}