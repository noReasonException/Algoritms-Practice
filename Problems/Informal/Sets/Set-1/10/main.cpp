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
 * 	3[D]. Minimum: Everyone evenly spaced to all of the teams, leftovers also spaced to as many teams as possible
 * 		3.1 for every new person in a team, the friendships are increased by the size of that team!
 * 		3.2 therefore, we spread people as much as possible
 * 		3.3 m teams, in case n%m==0, people fit in teams exacly
 * 		3.4 if n%m!=0, we fit people evenly in n teams, and we add the friendships added if we add the leftovers in every team one by one
 *				
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
	

	cout<<m*choose2(n/m) + (n%m)*(n/m)<<" "<<choose2(n-m+1);

	return 0;
}