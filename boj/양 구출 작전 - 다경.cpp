#include <iostream>
#include <vector>
using namespace std;
int N;
long long ans=0;
char isl_type[123457];
long long animals[123457];
vector<int> v[123457];
long long movetoone(int cur){
    long long ret=0;
    int nxt;

    if(v[cur].empty()){
        //leaf node
        if(isl_type[cur]=='S') return animals[cur];
        else return 0;
    }

    //no leaf node
    for(int i=0; i<v[cur].size(); i++){
        nxt = v[cur][i];
        ret += movetoone(nxt);
    }
    if(isl_type[cur]=='S') ret += animals[cur];
    else ret -= animals[cur];
    ret = ret<0 ? 0:ret;

    return ret;
}
int main(){
    int p;

    cin>>N;
    for(int i=2; i<=N; i++){
        cin>>isl_type[i]>>animals[i]>>p;
        v[p].push_back(i);
    }

    for(int i=0; i<v[1].size(); i++){
        ans += movetoone(v[1][i]);
    }

    cout<<ans;

    return 0;
}