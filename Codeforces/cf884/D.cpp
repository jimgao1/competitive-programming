#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
}
LL dp[51][51];
LL dp0[51][51];
LL dp2[51][51];
LL C[51][51];
LL inv[51];
LL CC(LL x,LL v){
    if(x<v)return 0;
    LL ret=1;
    REP(i,v){
        ret=ret*(x-i)%MOD;
    }
    return ret*inv[v]%MOD;
}
int main(){
    inv[0]=1;
    REPP(i,1,51){
        inv[i]=mypow(i,MOD-2)*inv[i-1]%MOD;
    }
    REP(i,51){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    dp0[0][0]=1;
    REPP(i,1,51){
        REP(j,51){
            for(int k=1;j+k<=50;k++){
                ADD(dp0[i][j+k],dp0[i-1][j]);
            }
        }
    }
    dp[0][0]=1;
    dp[1][1]=1;
    dp2[0][0]=1;
    {
        int i=1,j=1;
        for(int k=50;k>=0;k--)for(int r=50;r>=0;r--){
            if(!dp2[k][r])continue;
            for(int t=1;t*i+k<=50&&t*j+r<=50;t++){
                REPP(s,1,t+1){
                    ADD(dp2[t*i+k][t*j+r],dp2[k][r]*dp0[s][t]%MOD*CC(dp[i][j],s));
                }
            }
        }
    }
    REPP(i,2,51){
        REP(j,i){
            {
                int k=i-1-j;
                REP(j2,i+1)REP(k2,i+1){
                    ADD(dp[i][min(j2,k2)+1],dp2[j][j2]*dp2[k][k2]);
                }
            }
        }
        REPP(j,1,i+1){
            for(int k=50;k>=0;k--)for(int r=50;r>=0;r--){
                if(!dp2[k][r])continue;
                for(int t=1;t*i+k<=50&&t*j+r<=50;t++){
                    REPP(s,1,t+1){
                        ADD(dp2[t*i+k][t*j+r],dp2[k][r]*dp0[s][t]%MOD*CC(dp[i][j],s));
                    }
                }
            }
        }
    }
    DRII(x,y);
    y--;
    printf("%I64d\n",dp2[x][y]);

    return 0;
}
