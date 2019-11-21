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

void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

void menu(){
	int dato,opcion;
	int contador=0;
	
	while(opcion !=6){
		cout<< "\t.:MENU:."<<endl;
		cout<<"1. Insertar nodo" <<endl;
		cout<<"2. Mostrar arbol" <<endl;
		cout<<"3.Recorrer el arbol en PreOrden: " <<endl;
		cout<<"4.Recorrer el arbol en InOrden: " <<endl;
		cout<<"5.Recorrer el arbol en PostOrden: " <<endl;
		cout<<"6. Salir" <<endl;
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
			
			case 3: cout<<"\nRecorrido en PreOrden: ";
					preOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
					
			case 4: cout<<"\nRecorrido en InOrden: ";
					inOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
					
			case 5: cout<<"\nRecorrido en PostOrden: ";
					postOrden(arbol);
					cout<<"\n\n";
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
