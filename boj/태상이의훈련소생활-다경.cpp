#include <iostream>
#include <cstring>
using namespace std;
int N,M;
int a,b,k;
int height[100001];
int order[100001][2]; //i부터 시작-> [i][0]=k, i까지->[i][1]=k
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(height, 0, sizeof(height));
    memset(order, 0, sizeof(order));

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        cin>>height[i];
    }
    for(int i=0; i<M; i++){
        cin>>a>>b>>k;
        order[a][0] += k;
        order[b][1] += k;
    }
    int sum=0; // 구간동안 변경해줄 값 저장
    for(int i=1; i<=N; i++){
        sum += order[i][0];
        height[i] += sum;
        sum -= order[i][1];
    }

    for(int i=1; i<=N; i++) cout<<height[i]<<' ';

    return 0;
}