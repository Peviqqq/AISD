#include <iostream>
#include <string>
using namespace std;

struct elem{
	int dane;
	elem* nast;
};
elem* head;
elem* tail;




void insert(int x, int i, elem* &a){//zadanie 1.a
	if(i==0){
		
		elem* newEl = new elem{x,a};
		a = newEl;
		a->nast = NULL;
			
	}else{
		elem* scho = a;
		for(int j=0; j<i-1; ++j){
			scho = scho->nast;
		}	
		elem* newEl = new elem{x, scho->nast};
		scho->nast = newEl;
	}	
}

void remove(int i, elem* &lista){//zadanie 1.b
	
	elem* scho;
	elem* scho2;
	elem* scho3;
	if(i==0){
		elem* a = lista;
		scho = a->nast;
		delete a;
		lista = scho;
	}
	if(i==1){
		elem* a = lista;
		scho = a->nast;
		scho2 = scho->nast;
		delete scho;
		a->nast = scho2;
	
	}else{
		scho = lista;
		for(int j=0; j<i-1;++j){
			
			scho = scho->nast;
			scho2 = scho->nast;
			scho3 = scho2->nast;
		}
		scho->nast = scho3;
		delete scho2;	
	}	
}

int read(int i, elem* lista){//zadanie 1.c	
	int c=0;
	while(lista){
		if(c==i){
			return lista->dane;
		}
		c++;
		lista = lista->nast;	
	}	
}

int size(elem* lista){//zadanie 2
	int counter=0;
	for(;lista;lista = lista->nast){
		counter++;
	}
	return counter;
}

void print(elem* lista){//zadanie 3
	
	for(;lista;lista = lista->nast){
		cout<<lista->dane<<" ";
	}
	cout<<endl;
}

void printRe(elem* a){//zadanie 5
	if(a->nast == NULL){
		cout<<a->dane<<" ";
		return;
	}
	printRe(a->nast);
	cout<<a->dane<<" ";
}

void destroy(elem* &lista){//zadanie 6
	if(lista->nast == NULL){
		delete lista;
		return;
	}
	destroy(lista->nast);
	delete lista;
}

elem* search(int x, elem* lista){//zadanie 7
	bool a = false;
	for(;lista; lista = lista->nast){
		if(x == lista->dane){
			a=true;
			if(a) return lista;
		}
	}
	if(!a){
		cout<<endl<<"nie znalezion";
		return NULL;	
	} 
}





int main(){
		
		
	elem* list = new elem;	
	insert(5,0,list);	
	insert(6,1,list);		
	insert(7,1,list);
	insert(8,3,list);
	insert(9,4,list);
	print(list);//wynik: 5 7 6 8 9
	cout<<endl<<"-----"<<endl;
	remove(1,list);
	print(list);//wynik: 5 6 8 9
	cout<<endl<<read(0,list)<<endl;//Wynik: 5
	cout<<endl<<size(list)<<endl;//Wynik: 4	
	cout<<endl<<"-----"<<endl;
	printRe(list);//Wynik: 9 8 6 5
	//destroy(list);
	cout<<endl<<search(9,list)<<endl;//Wynik: 0x855a70
		
	
	return 0;
}
