#include <iostream>
#include <cstring>

using namespace std;
#define VSIZE 300
#define PSIZE 30
int V;//number of villages
int P;//number of post offices;
int Vpos[VSIZE+1];//position of villages
int cost[VSIZE+1][VSIZE+1];	//min cost of having one post 
			//+ office between i and j.
int dp[VSIZE+1][PSIZE+1];	//dp[v][p] is the best solution
				//+ of building p post offices
				//+ in the first v villages.

void init(){
	memset(cost,0,sizeof(cost));
	for(int i = 1; i<=V; i++){
		for(int j = i+1; j<=V; j++){
			int median = (i+j)/2;
			for(int k = i; k<=median; k++){
				cost[i][j]+=(Vpos[median]-Vpos[k]);
			}
			for(int k = median+1; k<=j; k++){
				cost[i][j]+=(Vpos[k]-Vpos[median]);
			}
			cost[j][i]=cost[i][j];
		}
	}
	for(int i = 1; i<=V; i++){
		dp[i][1]=cost[1][i];
	}
}
int main(){
	cin>>V>>P;
	for(int i = 0; i<V; i++){
		cin>>Vpos[i+1];
	}
	init();
	for(int p=2; p<=P; p++){
		for(int v=p; v<=V; v++){
			dp[v][p]=9999999;
			for(int j = p-1; j<v; j++){
				//cout<<"v: "<<v<<" j: "<<j<<" "<<dp[j][p-1]<<" "<<cost[j+1][v]<<endl;
				if(dp[v][p]>dp[j][p-1]+cost[j+1][v]){
					dp[v][p]=dp[j][p-1]+cost[j+1][v];
				}
			}
			//cout<<dp[v][p]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[V][P];
	return 0;
}
