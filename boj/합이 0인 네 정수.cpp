#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long ans=0;
vector<long long> A,B,C,D;
vector<long long> AB,CD; //A+B조합, C+D조합

int main(){
    int a,b,c,d;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c>>d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    for(auto ab: AB){
        // -ab 이상이 처음 나오는 위치
        int s = lower_bound(CD.begin(), CD.end(), -ab)-CD.begin();
        // -ab를 초과하는 값이 처음 나오는 위치
        int e = upper_bound(CD.begin(), CD.end(), -ab)-CD.begin();
        ans += (e-s);
    }

    cout<<ans;

    return 0;
}