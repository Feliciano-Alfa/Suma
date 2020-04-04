//
//  main.cpp
//  LDE
//
//  Feliciano Morales Juan Daniel 2/04/20.
//  Copyright © 2020 Feliciano Morales Juan Daniel. All rights reserved.
//
#include <iostream>
using namespace std;
class Nodo
{
private:
    int dato;
    Nodo *sig,*ant;
public:
    Nodo()
    {   dato=0;
        ant=NULL;
		sig=NULL;
    }
    Nodo(int x)
    {   dato=x;
    	ant=NULL;
        sig=NULL;
    }
    void Asignasig(Nodo*);
    void Asignaant(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    Nodo *Obtieneant();
    int Obtienedato();
};
void Nodo::Asignasig(Nodo *x)
{   this->sig=x;
}
void Nodo::Asignaant(Nodo *x)
{	this->ant=x;
}
void Nodo::Imprimir()
{   cout<<this->dato;
}
Nodo* Nodo::Obtienesig()
{  return(this->sig);
}
Nodo* Nodo::Obtieneant()
{  return(this->ant);
}
int Nodo::Obtienedato()
{   return(this->dato);
}
class LDE
{    private:
    Nodo *Inicio,*Fin;
public:
    void InsertarI(int);
    void InsertarF(int);
    void Imprimir();
    void Leer();
    LDE operator+(LDE);
    LDE()
    {   Inicio=NULL;
    }
    
};
void LDE::InsertarI(int x)
{   if(!Inicio)	
	{	Inicio=new Nodo(x);
	}
	else
	{	Nodo *helpx3=new Nodo(x);
   		helpx3->Asignasig(Inicio);
   		Inicio->Asignaant(helpx3);
		Inicio=helpx3;  		
   	}
}
void LDE::InsertarF(int x)
{   if(Inicio==NULL)
    Inicio=new Nodo(x);
    else
        {   Nodo *help=Inicio;
            while(help->Obtienesig()!=NULL)			help=help->Obtienesig();
            Nodo *helpx2=new Nodo(x);
            help->Asignasig(helpx2);
            helpx2->Asignaant(help);
        }
}
void LDE::Imprimir()
{   if(!Inicio)
    cout<<"Lista Vacia"<<endl;
    else
        {   Nodo *Aux=Inicio;
            while(Aux!=NULL)   
            {	Aux->Imprimir();
				Aux=Aux->Obtienesig();
			}
        }
}
void LDE::Leer()
{	int n,aux;
	cout<<"Ingrese un numero: "; cin>>n;
	while((n%10)!=0)
	{	aux=n%10;
		n=n/10;
		InsertarI(aux);
	}
}
LDE LDE::operator+(LDE B)
{	LDE Temp;
	Nodo *Ayuda=B.Inicio,*Ayuda2=Inicio;
	int aux=0,c=0;
	while(Ayuda2->Obtienesig()!=NULL)
	{	Ayuda2=Ayuda2->Obtienesig();
		Ayuda=Ayuda->Obtienesig();
	}
	while(Ayuda!=NULL)
	{	c=Ayuda2->Obtienedato()+Ayuda->Obtienedato()+aux;
		if(c>=10)
		{	aux=1;
			c=c-10;	
		}
		else	aux=0;
		Temp.InsertarI(c);
		Ayuda2=Ayuda2->Obtieneant();
		Ayuda=Ayuda->Obtieneant();
	}
	if(aux>0) Temp.InsertarI(aux);
	return Temp;
}
int main(int argc, const char * argv[])
{   LDE A,B,C;
    cout<<"1.-"; A.Leer();
    cout<<"2.-"; B.Leer();
    system("pause"); system("cls");
    C=A+B;
    A.Imprimir(); cout<<endl;
    B.Imprimir(); cout<<endl;
    cout<<"la suma es: ";	C.Imprimir(); cout<<endl;
    return 0;
}
