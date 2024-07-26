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


void solve(){
	int n;
	cin >>n;
	string first,second;
	cin>>first;
	cin>>second;
	regex replaceFirstPass("G");
	regex replaceSecondPass("B");
	string commonRepr = "0";
	string firstTranslatedPass1 = regex_replace(first, replaceFirstPass, commonRepr);
	string firstTranslated = regex_replace(firstTranslatedPass1,replaceSecondPass,commonRepr);
	string secondTranslatedPass1 = regex_replace(second, replaceFirstPass, commonRepr);
	string secondTranslated = regex_replace(secondTranslatedPass1,replaceSecondPass,commonRepr);
	if(!firstTranslated.compare(secondTranslated)) {
		cout<<"YES"; 
	}
	else {
		cout<<"NO";
	}

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