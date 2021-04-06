#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<pair<pair<int,int>,int>> roads; //<<마을,마을>, 유지비>
vector<int> parent;
bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second < b.second;
}
int find(int u){
    if(u==parent[u]) return u;

    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u==v) //합치면 순환이라는 뜻이므로 합치면 안 됨
        return;
    parent[u] = v;
}
int main(){
    int a,b,c, cost,sum=0, u,v, max_cost=0;

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        roads.push_back(make_pair(make_pair(a,b),c));
    }

    //유지비 오름차순 정렬
    sort(roads.begin(), roads.end(), compare);
    //초기화
    for(int i=0; i<=n; i++) parent.push_back(i);
    //계산 -> 최소비용으로 모든 마을 연결하는 것
    for(int i=0; i<roads.size(); i++){
        cost = roads[i].second;
        u = roads[i].first.first;
        v = roads[i].first.second;

        if(find(u)==find(v)) continue;
        merge(u,v);
        sum += cost;
        max_cost = max(max_cost,cost);

        //cout<<cost<<' '<<sum<<endl;
    }
    cout<<sum-max_cost;  //최대 비용 삭제하면 마을 분리됨


    return 0;
}