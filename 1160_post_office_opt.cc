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
int queue[VSIZE+1];	// for optimiaztion

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
		int head = p-1;
		int tail = p-1;
		queue[head]=p-1;
		for(int v=p; v<=V; v++){
			while(head<tail && dp[queue[head]][p-1]-dp[queue[head+1]][p-1]>cost[queue[head+1]+1][v]-cost[queue[head]+1][v]) head++;
			dp[v][p]=dp[queue[head]][p-1]+cost[queue[head]+1][v];
			while(head<tail && )
			for(int j = p-1; j<v; j++){
				if(dp[v][p]>dp[j][p-1]+cost[j+1][v]){
					dp[v][p]=dp[j][p-1]+cost[j+1][v];
				}
			}
		}
	}
	cout<<dp[V][P];
	return 0;
}
