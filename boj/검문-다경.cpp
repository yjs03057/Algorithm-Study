#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
vector<int> v;
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp,sqrttmp;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    tmp = v[1]-v[0];
    for(int i=2; i<N; i++){
        tmp = gcd(tmp, v[i]-v[i-1]);
    }
    //tmp : 최대공약수
    sqrttmp = sqrt(tmp);
    for(int i=2; i<=sqrttmp; i++){
        if(tmp%i==0) cout<<i<<' '; //tmp의 약수 출력
    }
    sqrttmp = sqrt(tmp-1);
    for(int i=sqrttmp; i>=1; i--){
        if(tmp%i==0) cout<<tmp/i<<' '; //나눠진 숫자와 곱을 이뤄 tmp가 되는 수
    }

    return 0;
}