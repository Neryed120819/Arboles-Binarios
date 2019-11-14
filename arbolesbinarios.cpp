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
void mostrarArbol(Nodo *,int);
void preOrden(Nodo*);
void enOrden(Nodo *);

Nodo *arbol = NULL;

int main(){
	menu();
	
	getch();
	return 0;
}

//Funcion del menu
void menu(){
	int dato, opcion,contador=0;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1.-Agregar un nuevo nodo"<<endl;
		cout<<"2.-Mostrar arbol"<<endl;
		cout<<"3-Preorden"<<endl;
		cout<<"4-En Orden"<<endl;
		cout<<"5-Salir"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDame un numero: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					system("pause");
					break;
			case 2: cout<<"\nMostrando el arbol:\n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\nRecorrido en PreOrden: ";
					preOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
			case 4: cout<<"Recorrido en orden: ";
					enOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 5);
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
//Funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}
//Funcion en preorden
void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}
//Funcion en orden
void enOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		enOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		enOrden(arbol->der);
	}
}
