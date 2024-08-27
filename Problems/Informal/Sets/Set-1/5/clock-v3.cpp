#include <iostream>
#include <set>

using namespace std;



//a1<c<c2 ^^ a1<d<

void solve(){
	int a,b,c,d;
	int a1,a2;
	cin>>a>>b>>c>>d;
	a1=min(a,b);
	a2=max(a,b);
	
	if(((a1<=c && c<=a2))!=((a1<=d && d<=a2))){
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
