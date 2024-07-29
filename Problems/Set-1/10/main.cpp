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


void solve(){
	
}

int main(){
	int n;
	cin>>n;
	while(n--)solve();
	return 0;
}