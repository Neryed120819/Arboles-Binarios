#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct Nodo{ 
  int dato;
  Nodo* izq,* der;
};
Nodo* valorRaiz=NULL,*aux=NULL;

int main() {
    valorRaiz=new Nodo();
    valorRaiz->dato=14;
    valorRaiz->izq=new Nodo();
    valorRaiz->der=new Nodo();

    aux=valorRaiz->izq;
    aux->dato=10;
    aux->izq=new Nodo();
    aux->der=new Nodo();

    aux=aux->izq;
    aux->dato=8;
    aux->izq=NULL;
    aux->der=NULL;

    aux=valorRaiz->izq;
    aux=aux->der;
    aux->dato=5;
    aux->izq=NULL;
    aux->der=NULL;

    aux=valorRaiz->der;
    aux->dato=3;
    aux->izq=NULL;
    aux->der=new Nodo();

    aux=aux->der;
    aux->dato=4;
    aux->izq=new Nodo();
    aux->der=NULL;

    aux=aux->izq;
    aux->dato=6;
    aux->izq=NULL;
    aux->der=NULL;
    
    cout<<"\t\t"<<valorRaiz->dato<<endl;
    cout<<"\t"<<valorRaiz->izq->dato<<"\t\t "<<valorRaiz->der->dato<<endl;
    cout<<"  "<<valorRaiz->izq->izq->dato<<"\t\t"<<valorRaiz->izq->der->dato<<"\t\t"<<valorRaiz->der->der->dato<<endl;
    cout<<valorRaiz->der->der->izq->dato<<endl;


    aux=valorRaiz->izq;
    valorRaiz->izq=NULL;
    delete aux;

    aux=valorRaiz->der;
    aux=aux->der;
    aux=aux->izq;
    delete aux;
    aux=valorRaiz->der->der;
    aux->izq=NULL;

    cout<<endl<<"Al eliminar:"<<endl;
    cout<<valorRaiz->dato<<endl;
    cout<<valorRaiz->der->dato<<endl;
    cout<<valorRaiz->der->der->dato<<endl;
	system("pause");
    return 0;
}

