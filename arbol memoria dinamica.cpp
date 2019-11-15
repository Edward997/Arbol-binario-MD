#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

Nodo *arbol = NULL;

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

void menu(){
	int dato,opcion;
	int contador=0;
	
	while(opcion !=3){
		cout<< "\t.:MENU:."<<endl;
		cout<<"1. Insertar nodo" <<endl;
		cout<<"2. Mostrar arbol" <<endl;
		cout<<"3. Salir" <<endl;
		cout<< "-> ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"Introduzca un numero: ";
					cin>>dato;
					insertarNodo(arbol, dato);
					cout<<"\n";
					system("pause");
					break;
					
			case 2: cout<<"\nMostrando arbol: \n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}
}

int main(){
	
	menu();
	
	return 0;
}
