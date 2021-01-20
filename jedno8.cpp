#include <iostream>
#include <string>
using namespace std;



//zadanie 8
struct elem{
	int expo;
	int coef;
	elem* nast;
};
elem* list3 = new elem;

void insertWiel(int i, int expo, int coef, elem* &a){
	if(i==0){
		
		elem* newEl = new elem{expo, coef, a};
		a = newEl;
		a->nast = NULL;
			
	}else{
		elem* scho = a;
		for(int j=0; j<i-1; ++j){
			scho = scho->nast;
		}	
		elem* newEl = new elem{expo, coef, scho->nast};
		scho->nast = newEl;
		newEl->nast=NULL;
	}
}
void printWiel(elem* lista){
	
	for(;lista;lista = lista->nast){
		if(lista->coef >=0){
			cout<<"+";
		}
		cout<<lista->coef;
		if(lista->expo !=0){
			cout<<"x^"<<lista->expo;
		}
	}
	cout<<endl;	
}
elem* polyAdd(elem* l1, elem* l2){
	
	
	int schoExpo;
	int schoCoef;
	int schoLicz=-1;
	for(;l1,l2; l1=l1->nast , l2=l2->nast){
		if(l1!=NULL && l2!=NULL && l1->expo == l2->expo){
			schoLicz++;
			schoCoef = l1->coef + l2->coef;
			schoExpo = l1->expo;
			insertWiel(schoLicz, schoExpo, schoCoef, list3);
		}else{
			if(l1!=NULL){
				schoLicz++;
				insertWiel(schoLicz, l1->expo, l1->coef, list3);
			}	
			if(l2!=NULL){
				schoLicz++;
				insertWiel(schoLicz, l2->expo, l2->coef, list3);
			}
		}
		
		
	}
}


int main(){
	
	elem* list = new elem;	
	insertWiel(0, 5, 2, list);
	insertWiel(1, 2, -1, list);
	insertWiel(2, 1, 7, list);
	insertWiel(3, 0, 4, list);
	printWiel(list); //wynik: +2x^5-1x^2+7x^1+4
	
	elem* list2 = new elem;
	insertWiel(0, 5, 2, list2);
	insertWiel(1, 2, 1, list2);
	insertWiel(2, 1, 3, list2);
	insertWiel(3, 0, 4, list2);
	printWiel(list2);//wynik: +2x^5+1x^2+3x^1+4
	
	
	polyAdd(list, list2);
	printWiel(list3);//wynik: +4x^5+0x^2+10x^1+8
	
	
	
	
	return 0;
}
