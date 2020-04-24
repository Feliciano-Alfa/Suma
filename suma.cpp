//  SUMA CON LDE
//  Feliciano Morales Juan Daniel 24/04/20.
//  Copyright © 2020 Feliciano Morales Juan Daniel. All rights reserved.
#include <iostream>
#include <conio.h>
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
    int Contar();
    void Leer();
    LDE operator+(LDE);
    LDE()
    {   Inicio=NULL;
    	Fin=NULL;
    }
    
};
void LDE::InsertarI(int x)
{   if(!Inicio)
    {   Inicio=new Nodo(x);
        Fin=Inicio;
    }
    else
    {   Nodo *helpx3=new Nodo(x);
        helpx3->Asignasig(Inicio);
        Inicio->Asignaant(helpx3);
        Inicio=helpx3;
    }
}
void LDE::InsertarF(int x)
{   if(!Inicio)
    {   Inicio=new Nodo(x);
    	Fin=Inicio;
	}
    else
    {
        Nodo *helpx2=new Nodo(x);
        Fin->Asignasig(helpx2);
        helpx2->Asignaant(Fin);
        Fin=helpx2;
    }
}
void LDE::Imprimir()
{   if(!Inicio)   cout<<"";
    else
        {   Nodo *Aux=Inicio;
            while(Aux!=NULL)   
            {	Aux->Imprimir();
				Aux=Aux->Obtienesig();
			}
        }
}
int LDE::Contar()
{	int ESCA=0;
   	if(Inicio)
   	{	Nodo *REC=Inicio;
   		while(REC!=NULL)
   		{	ESCA++;
   			REC=REC->Obtienesig();
   		}
   	}
	return ESCA;
}
void LDE::Leer()
{	int i=0; 
	while(i!=13) //termina hasta que presione enter
	{	system("cls");
		cout<<"Ingresa tu numero: ";	Imprimir(); //para que muestre la cifra que voy ingresando
		if((i=getch())!=13)	InsertarF(i-48);//el -48 es para convertir de ASCII a decimal 
	}
}
LDE LDE::operator+(LDE B)
{	LDE Temp;
	Nodo *may,*men;
	int aux=0,c;
	if(Contar()>=B.Contar()) 
	{	men=B.Fin;	 may=Fin;
	}
	else
	{	may=B.Fin;	 men=Fin;
	}
	while(men!=NULL)
	{	c=may->Obtienedato()+men->Obtienedato()+aux;
		if(c>=10)
		{	aux=1;
			c=c-10;	
		}
		else	aux=0;
		Temp.InsertarI(c);
		men=men->Obtieneant();
		may=may->Obtieneant();
	}
	while(may!=NULL)
	{	c=may->Obtienedato()+aux;
		if(c>=10)
		{	aux=1;
			c=c-10;	
		}
		else	aux=0;
		Temp.InsertarI(c);
		may=may->Obtieneant();
	}
	if(aux>0) Temp.InsertarI(aux);
	return Temp;
}
int main(int argc, const char * argv[])
{   LDE A,B,C;
    cout<<"1.-"; A.Leer();
    cout<<"2.-"; B.Leer();
	system("cls");
    C=A+B;
    A.Imprimir(); cout<<endl;
    B.Imprimir(); cout<<endl;
    cout<<"la suma es: ";	C.Imprimir(); cout<<endl;
    return 0;
}
