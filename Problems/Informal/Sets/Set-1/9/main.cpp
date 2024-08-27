#include <iostream> 
#include <regex> 
#include <string> 


using namespace std;
#ifdef DEBUG
	#define cinfo cout
	#define add <<
#endif
#ifndef DEBUG
	#define cinfo ;
	#define add ;
#endif


bool nonR(char i){
	return i=='B' || i=='G';
}
void solve(){
	bool result = true;
	int n;
	cin >>n;
	string first,second;
	cin>>first;
	cin>>second;
	for(int i=0;i<first.size();i++){
		if(nonR(first[i])&&nonR(second[i])) continue;
		else if(first[i]=='R' && first[i]==second[i]) continue;
		else{
			result=false;
			break;
		}
	}
	if(result) cout<<"YES";
	else cout<<"NO";

}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	};
	return 0;
}