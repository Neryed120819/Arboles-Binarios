//ARBOLES BINARIOS
#include <iostream>
#include <stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();

Nodo *crearNodo(int);
void agregarNodo(Nodo *&,int);

Nodo *arbol = NULL;

int main(){
	menu();
	
	getch();
	return 0;
}

//Funcion del menu
void menu(){
	int dato, opcion;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1.-Agregar un nuevo nodo"<<endl;
		cout<<"2-Salir"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDame un numero: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 2);
}

//Funcionp para crear un nuevo nodo
Nodo *crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}
//Funcion para agregar Nodo
void agregarNodo(Nodo *&arbol, int n){
	if (arbol == NULL){
		Nodo *nuevoNodo = crearNodo(n);
		arbol = nuevoNodo;
	}
	else{
		int valorRaiz= arbol->dato;
		if (n < valorRaiz){
			agregarNodo(arbol->izq,n);
		}
		else{
			agregarNodo(arbol->der,n);
		}
	}
	
}
