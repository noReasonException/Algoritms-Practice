#include <iostream>
using namespace std;
#ifdef DEBUG
	#define debug cout
	#define con <<
#endif
#ifndef DEBUG
	#define debug ;
	#define con ;
#endif


/**
 * 		Criterion
 * 			let array a1,a2,a3,a4 sorted, then its good if a4 = a1+a2+a3
 * 			let array a1,a2,a3,a4, then max(a1,a2,a3,a4) = others(a1,a2,a3,a4)
*/
int solve(){
	int numbers=0,current=0,currentSum=0,max=0,indexes = 0;
	cin>>numbers;
	debug con "numbers\t" con numbers con "\n";
	while(numbers--){
		cin>>current;
		if(current>max)max=current;
		if(max==currentSum || max==currentSum+current) {
			indexes+=1;
			debug con "\t\t\t\tindex is now" con indexes con "\n";
		}
		debug con "number\t" con current con "\n";
		debug con "\tmax\t" con max con "\n";
		debug con "\tcurrent sum\t" con currentSum con "\n";
		currentSum+=current;

	}
	return indexes;
}

int main(){
	int n;
	cin>>n;
	while(n--)cout<<solve()<<"\n";
	return 0;

}