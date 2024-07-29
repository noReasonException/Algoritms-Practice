#include <iostream>

using namespace std;
#ifdef DEBUG
	#define cinfo cout
	#define add <<
#endif
#ifndef DEBUG
	#define cinfo ;
	#define add ;
#endif


/**
 *	1. Maximum : Everyone in a single team, everyone else in isolation
 * 		1.1 Isolated teams do not form friendships
 *  2. Minimum : Everyone in pairs of two, and one team with the leftovers
 * 		2.1 Pair-team = 1 friendship
 * 		2.2 leftovers choose 2 for the last team
*/


//(N choose 2) simplified, avoiding to calculate the whole number as it will overflow
int choose2(int n){
	return (n*(n-1))/2;
}

int main(){
	int n,m;
	int k=0;
	int l=0;
	cin>>n>>m;
	


	//min - max
	cout<<(m-1) + choose2(n-(m-1)*2)<<" "<<choose2(n-m+1)<<"\n";
	

	return 0;
}