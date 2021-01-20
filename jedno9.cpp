#include <iostream>
#include <string>
using namespace std;



//zadanie 9
struct elem{
	int licz;
	int mian;
	elem* nast;
};
elem* list = new elem;


void insertFa(int licz, int mian, int i, elem* &a){
	if(i==0){
		
		elem* newEl = new elem{licz, mian, a};
		a = newEl;
		a->nast = NULL;
			
	}else{
		elem* scho = a;
		for(int j=0; j<i-1; ++j){
			scho = scho->nast;
		}	
		elem* newEl = new elem{licz, mian, scho->nast};
		scho->nast = newEl;
	}	
}
void printFa(elem* lista){
	for(;lista;lista = lista->nast){
		cout<<lista->licz<<"/"<<lista->mian<<endl;	
	}	
}

elem* ulamek_fareya(int n){
	
	int a=1;
	int b=n-1;
	bool d=false;
	int counter=2;
	insertFa(0,1,0,list);
	insertFa(1,n,1,list);
	while(a!=n){
		insertFa(a,b,counter,list);
		if(b!=2 && !d){	
			b--;	
		}else{
			b++;
			a++;
			d=true;
		}	
		counter++;
	}
	insertFa(1,1,counter,list);
	
	
} 

int main(){
	
	ulamek_fareya(5);
	
	printFa(list);
	/*Wynik: 
	0/1
	1/5
	1/4
	1/3
	1/2
	2/3
	3/4
	4/5
	1/1
	*/
	
	return 0;	
}
