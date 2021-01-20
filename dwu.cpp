#include <iostream>
#include <string>
using namespace std;

struct elem{
	int dane;
	elem* poprz;
	elem* nast;	
};


void insert(int x, int i, elem* &a){//zadanie 1.a
	
	if(i==0){
		
		elem* newEl = new elem{x,a};
		a = newEl;
		a->nast = NULL;
		a->poprz = NULL;
			
	}else{
		elem* scho = a;
		for(int j=0; j<i-1; ++j){
			scho = scho->nast;
		}	
		elem* newEl = new elem{x, scho, scho->nast};
		scho->nast = newEl;
	}	
}

void remove(elem* &lista){//zadanie 1.b
	
	lista = lista->nast;
	delete lista->poprz;	
}

void remove(int i, elem* &lista){//zadanie 1.c
	
	if(i==0){
		remove(lista);
	}else{
		elem* scho = lista;
		for(int j=0; j<i;++j){
			scho = scho->nast;
		}
		scho->poprz->nast = scho->nast;
		delete scho;	
	}
}

void reverse(elem* &lista){//zadanie 2
	elem* scho = lista;
	while(scho){
		elem* scho2 = scho->nast;
		scho->nast = scho->poprz;
		scho->poprz = scho2;
		if(scho->poprz == NULL){
			lista = scho;
		}
		scho = scho->poprz;
	}		
}

void to_cyclic(elem* lista){//zadanie 3
	elem* scho = lista;
	while(lista){
		lista = lista->nast;
	}
	lista->nast = scho;
}

void reverse_cyclic(elem* lista){//zadanie 4
	elem* scho = lista;
	lista = lista->nast;
	elem* scho2 = lista->nast;
	while(scho != scho2){
		lista->nast = scho;
		scho = lista;
		lista = scho2;
		scho2 = lista->nast;
	}	
}

void print(elem* lista){
	int counter=0;
	for(;lista;lista = lista->nast){
		cout<<lista->dane<<" ";
		counter++;
		if(counter>10) break;
	}
	cout<<endl;
}

int main(){
	
	elem* list = new elem;	
	
	insert(1,0,list);
	insert(2,1,list);
	insert(3,2,list);
	print(list);
	insert(4,2,list);
	print(list);
	remove(2,list);
	print(list);
	reverse(list);
	print(list);
	//to_cyclic(list);
	//reverse_cyclic(list);
	//print(list);
	
	return 0;
}
