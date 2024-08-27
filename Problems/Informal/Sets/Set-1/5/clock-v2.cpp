#include <iostream>
#include <set>

using namespace std;


void solve(){
	//s1 	: start of a,b area
	//s2 	: stop of a,b area
	int a,b,c,d;
	int a1,a2;
	cin>>a>>b>>c>>d;
	set<int> area;
	a1=min(a,b);
	a2=max(a,b);
	for(int i=a1;i<=a2;i++){
		area.insert(i);
	}
	if(!!(area.find(c) != area.end()) != !!(area.find(d) != area.end())){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}

int main(){
	int cases;
	cin>>cases;
	while(cases--){
		solve();
		cout<<endl;
	}

}
