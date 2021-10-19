#include <iostream>
#include <algorithm>
using namespace std;

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C){
    //외적 공식
    long cal = A.first*B.second + B.first*C.second + C.first*A.second;
    cal = cal - A.second*B.first - B.second*C.first - C.second*A.first;

    if(cal>0) return 1;
    else if(cal<0) return -1;
    else return 0; //일직선
}

int main(){

    //세 점을 넣었을 때, 세 점의 관계를 파악하는 것 (외적)
    // CA X AB => >0:반시계, <0: 시계, 0: 일직선
    // 1) ABC X ABD < 0
    // 2) 직선인 경우, 범위 내 교차하는지

    pair<int, int> A,B,C,D;
    cin>>A.first>>A.second>>B.first>>B.second;
    cin>>C.first>>C.second>>D.first>>D.second;

    int ABC = CCW(A,B,C);
    int ABD = CCW(A,B,D);
    int CDA = CCW(C,D,A);
    int CDB = CCW(C,D,B);

    //예외) 둘 다 직선인 경우
    if(ABC*ABD == 0 && CDA*CDB == 0){
        if(A>B) swap(A,B);
        if(C>D) swap(C,D);

        if(A<=D && C<=B) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    else{
        if(ABC*ABD<=0 && CDA*CDB<=0) cout<<1<<'\n';
        else cout<<0<<'\n';
    }

    return 0;
}