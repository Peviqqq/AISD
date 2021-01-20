#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
using namespace std;

struct elem{
	int dane;
	elem* nast;	
};

void push(elem* &stos, int x){//zadanie 1.a
	elem* scho = stos;
	stos = new elem{x, scho};
}

int pop(elem* &stos){//zadanie 1.b
	int schoDane = stos->dane;
	if(stos->nast){
		elem* scho = stos;
		stos = scho->nast;
		delete scho;
		scho = NULL;
		return schoDane;	
	}else{
		delete stos;
		stos=NULL;
		return schoDane;
	}	
}

int topEl(elem* stos){//zadanie 1.c
	int schoDane = stos->dane;
	return schoDane;
}

bool isEmpty(elem* stos){//zadanie 1.d
	return !stos;
}

void add(elem* &pocz_kolejki, elem* &kon_kolejki, int x){//zadanie 2.a
	if(pocz_kolejki){
		kon_kolejki->nast = new elem{x, NULL};
		kon_kolejki = kon_kolejki->nast;
	}else{
		pocz_kolejki = kon_kolejki = new elem{x, NULL};
	}
}

int next(elem* &pocz_kolejki, elem* &kon_kolejki){//zadanie 2.b
	int schoDane = pocz_kolejki->dane;
	elem* scho = pocz_kolejki;
	pocz_kolejki = pocz_kolejki->nast;
	delete scho;
	return schoDane;
}

int firstEl(elem* pocz_kolejki, elem* kon_kolejki){//zadanie 2.c
	int schoDane = pocz_kolejki->dane;
	return schoDane;
}

bool isEmptyKol(elem* pocz_kolejki){//zadanie 2.d
	return !pocz_kolejki;
}

string series(string str){//zadanie 3
	string newStr="";
	char* tab = new char[str.length()+1];
	strcpy(tab, str.c_str());
	
	elem* pocz_kolej=NULL;
	elem* kon_kolej=NULL;
	
	for(int i=0; i<str.length();++i){
		if(tab[i] == '*'){
			cout<<(char)next(pocz_kolej,kon_kolej);
		}
		if(isalpha(tab[i])){
			add(pocz_kolej, kon_kolej, tab[i]);
		}
	}
	return newStr;
}

string seriesStos(string str){//zadanie 4
	string newStr="";
	char* tab = new char[str.length()+1];
	strcpy(tab, str.c_str());
	
	elem* scho = NULL;
	
	for(int i=0;i<str.length();++i){
		if(tab[i] == '*'){
			cout<<(char)pop(scho);
		}
		if(isalpha(tab[i])){
			push(scho, tab[i]);
		}
	}
	return newStr;
}

//zadanie 5
void addStos(elem* &stos1, int x){
	push(stos1, x);	
}
int nastStos(elem* &stos1, elem* &stos2){
	if(isEmpty(stos2)){
		while(!isEmpty(stos1)){
			push(stos2,pop(stos1));
		}
	}
	return pop(stos2);
}

//zadanie 6
void addKol(int* tab, int max, int &tail, int x){
	tail %= max;
	tab[tail] = x;
	tail++;
}
int nastKol(int* tab, int max, int &head){
	int scho = tab[head++];
	head %= max;
	return scho;
}

//zadanie 7
void reverseStos(elem* &stos){
	elem* schoStos = NULL;
	while(!isEmpty(stos)){
		push(schoStos, pop(stos));
	}
	stos = schoStos;
}
void reverseKol(elem* &stos){
	elem* pocz_kolej1=NULL;
	elem* kon_kolej1=NULL;
	while(!isEmpty(stos)){
		add(pocz_kolej1, kon_kolej1, pop(stos));
	}
	while(!isEmptyKol(pocz_kolej1)){
		push(stos, next(pocz_kolej1,kon_kolej1));
	}
}

void sort(elem* &stos){//zadanie 8
	elem* schoStos = NULL;
	int x = 0;
	while(!isEmpty(stos)){
		x = pop(stos);
		while(!isEmpty(schoStos)){
			if(topEl(schoStos)<x) break;
			push(stos, pop(schoStos));
		}
		push(schoStos, x);
	}
	stos = schoStos;
}

void moveStos(elem* stos1, elem* &stos2){//zadanie 9
	elem* scho = NULL;
	while(!isEmpty(stos1)){
		push(scho, pop(stos1));
	}
	while(!isEmpty(scho)){
		push(stos2, pop(scho));
	}
}

void print(elem* stos){
	
	while(stos){
		cout<<stos->dane<<" ";
		stos = stos->nast;
	}
	cout<<endl;
}

void printKol(elem* pocz_kolejki, elem* kon_kolejki){
	elem* scho = pocz_kolejki;
	if(pocz_kolejki){
		do{
			cout<<scho->dane<<" ";
			scho = scho->nast;
		}while(scho != kon_kolejki);
		cout<<scho->dane<<" ";	
		cout<<endl;
			
	}else{
		cout<<"pusty"<<endl;
	}
	
}

int main(){
	
	elem* stos = new elem();
	
	push(stos, 1);
	push(stos, 2);
	push(stos, 3);
	print(stos);
	cout<<pop(stos)<<endl;
	cout<<pop(stos)<<endl;
	print(stos);
	cout<<topEl(stos)<<endl;
	pop(stos);
	print(stos);
	if(isEmpty(stos)){
		cout<<"pusty stos"<<endl;
	}else if(!isEmpty(stos)){
		cout<<"nie pusty stos"<<endl;
	}
	cout<<"------------kolejka-----------"<<endl;
	
	elem* kolej = new elem();
	elem* pocz_kolej=NULL;
	elem* kon_kolej=NULL;
	add(pocz_kolej,kon_kolej,1);
	add(pocz_kolej,kon_kolej,2);
	add(pocz_kolej,kon_kolej,3);
	cout<<firstEl(pocz_kolej,kon_kolej)<<endl;
	printKol(pocz_kolej,kon_kolej);
	cout<<next(pocz_kolej,kon_kolej)<<endl;
	printKol(pocz_kolej,kon_kolej);
	
	cout<<next(pocz_kolej,kon_kolej)<<endl;
	cout<<next(pocz_kolej,kon_kolej)<<endl;
	if(!isEmptyKol(kolej)){
		cout<<"pusty kolejka"<<endl;
	}else{
		cout<<"nie pusty kolejka"<<endl;
	}
	printKol(pocz_kolej,kon_kolej);
	
	
	string zad3 = "EAS*Y*QUE***ST***IO*N***";
	cout<<series(zad3)<<endl;//wynik: EASYQUESTION
	
	string zad4 = "EA*S*Y**";
	cout<<seriesStos(zad4)<<endl;//wynik: ASYE
	
	
	//zadanie 5
	
	elem* stosKol1=NULL;
	elem* stosKol2=NULL;
	addStos(stosKol1,5);
	addStos(stosKol1,3);
	addStos(stosKol1,4);
	//cout<<nastStos(stosKol1, stosKol2)<<" ";
	
	//zadanie 6
	
	int* tab = new int[5];
	int head = 0;
	int tail = 0;
	addKol(tab,5,tail,1);
	addKol(tab,5,tail,2);
	cout<<nastKol(tab,5,head)<<" ";
	cout<<nastKol(tab,5,head)<<" ";
	
	

	
	return 0;
}



