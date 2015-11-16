/**
pitfall:
	1. __int32 must be used, int is not ok.
	2. cout blank line after each output, not in between.
**/


#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#define MAX_N X
#define MAX_M X
using namespace std;
int main(){
	__int32 n;
	while (cin >> n){
		if (n % 2 == 0){
			cout << n / 2 * (n + 1) << endl;
		}
		else{
			cout << (n + 1) / 2 * n << endl;
		}
		cout << endl;
	}
	return 0;
}
