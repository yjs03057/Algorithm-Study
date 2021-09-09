#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N,K; //보석 수, 가방 수
priority_queue<pair<int,int>> jams; // 보석(가격, 무게)
multiset<int> bags; // 각 가방 최대 무게
long long ans=0;

int main(){
    int m,v,c;

    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>m>>v;
        jams.push({v,m});
    }

    for(int i=1; i<=K; i++){
        cin>>c;
        bags.insert(c);
    }

    while(!jams.empty() && !bags.empty()){
        //set의 lower_bound(x) : x와 같은 값을 리턴하거나 더 큰 값중 가장 작은 값 리턴
        auto it = bags.lower_bound(jams.top().second);
        if(it != bags.end()){
            ans += jams.top().first;
            bags.erase(it);
        }
        jams.pop();
    }

    cout<<ans<<endl;

    return 0;
}