/*
Confeccionar una programa que administre una lista tipo pila (se debe poder insertar, extraer e imprimir los datos de la pila).
*/
/*
Agregar al problema anterior otras dos funciones: que retorne la cantidad de nodos y otro que indique si esta vacía (1=vacía y 0=no vacía).
*/

/*
Agregar otra función al programa desarrollado para administrar una pila que retorne la información del primer nodo de la Pila sin borrarlo.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};

Nodo *cima = NULL;

void insertar(int);
int extraer ();
void imprimir();
int cantNodos();
int vacia();
int primerNodo();
void modificarNodo(int);

int main(){

int op=0, ciclo = 0, n = 0;

do
{
    system("cls");
    cout<<"0. Salir";
    cout<<"\n1. Insertar";
    cout<<"\n2. Extraer";
    cout<<"\n3. Imprimir";
    cout<<"\n4. Mostrar la cantidad de nodos";
    cout<<"\n5. Verificar si esta vacia la pila";
    cout<<"\n6. Mostrar primer nodo de la pila";
    cout<<"\n7. Eliminar un numero de la pila";
    cout<<"\nElija una opcion: "; cin>>op;

    switch (op)
    {
        case 0: 
            ciclo = 1;
        break;

        case 1: system("cls");
            cout<<"Ingrese un numero: "; cin>>n;
            insertar(n);
        break;

        case 2: system("cls");
            cout<<"Numero "<<extraer()<<" extraido con exito de la pila";
            cout<<"\n";
            system("pause");
        break;

        case 3: system("cls");
            imprimir();
            cout<<"\n";
            system("pause");
        break;

        case 4: system("cls");
            if (vacia() == 1)
            {
                cout<<"La pila esta vacia";
            }
            else
            {
                cout<<"La pila tiene "<<cantNodos()<<" nodos";
            }     

            cout<<"\n";
            system("pause");
        break;

        case 5: system("cls");
            if (vacia() == 1)
            {
                cout<<"La pila esta vacia";
            }
            else 
            {
                cout<<"La pila tiene "<<cantNodos()<< " elementos";
            }

            cout<<"\n";
            system("pause");
        break;

        case 6: system("cls");
            if (vacia() == 1)
            {
                cout<<"La pila esta vacia";
            }
            else
            {
                cout<<"Primer nodo de la pila:  "<<primerNodo();
            }     

            cout<<"\n";
            system("pause");

        break;

        case 7: system("cls");
            cout<<"Ingrese el numero que desea eliminar: "; cin>>n;
            modificarNodo(n);
            cout<<"\n";
            system("pause");
        break;
        
        default: 
        cout<<"\nOpcion incorrecta!"; 
        cout<<"\n";
        system("pause");

    }   
} while (ciclo == 0);



    return 0;
}

void insertar(int n)
{
    Nodo *temp_ptr = new Nodo();
    temp_ptr->dato = n;

    if (cima == NULL)
    {
        cima = temp_ptr;
        temp_ptr->sig = NULL; 
    }
    else
    {
        temp_ptr->sig = cima;
        cima = temp_ptr;
    }
}

int extraer ()
{
    Nodo *temp_ptr = new Nodo();

    int informacion = cima->dato;

    if (cima != NULL)
    {
        temp_ptr = cima;
        cima = cima->sig;
        delete temp_ptr;
        return informacion;
    }
    else
    {
        return -1;
    }

}

void imprimir()
{

    Nodo *temp_ptr = new Nodo();

    temp_ptr = cima;

    while (temp_ptr != NULL)
    {
        cout<<"|"<<temp_ptr->dato<<"|";
        temp_ptr = temp_ptr->sig;
        cout<<"\n";
    }

}

int cantNodos()
{
    Nodo *temp_ptr = new Nodo();

    temp_ptr = cima;

    int cant = 0;

    if (temp_ptr == NULL)
    {
        return cant;
    }

    else
    {
        while (temp_ptr != NULL)
        {
            cant++;
            temp_ptr = temp_ptr->sig;
        }

        return cant;
    }
}

int vacia()
{
    Nodo *temp_ptr = new Nodo();

    temp_ptr = cima;
    
    if (temp_ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int primerNodo()
{
    Nodo *temp_ptr = new Nodo();
    temp_ptr = cima;

    int primero = 0;

    if (temp_ptr->sig == NULL)
    {
        primero = temp_ptr->dato;
        return primero;
    }
    else
    {
        while(temp_ptr->sig != NULL)
        {
            temp_ptr = temp_ptr->sig;
        }

        primero = temp_ptr->dato;
        return primero;
        
    }

}

void modificarNodo(int n)
{
    Nodo *temp_ptr = new Nodo();
    Nodo *pila_rpld = new Nodo();
    Nodo *pila_aux = new Nodo();
    Nodo *aqui;
    temp_ptr = cima;
    pila_rpld = NULL;
    pila_aux = NULL;
    aqui = cima;
    
    

    /*
    Esta funcion debe permitir buscar cualquier valor dentro de la pila
    para eliminarlo sin borrar el resto de datos.
    pasos:
    1. Buscar el nodo (comparando el dato proporcionado con los datos dentro de la pila).
        antes de cada iteración se deben extraer los datos y guardarse en una pila auxiliar.
    2. Una vez encontrado el nodo eliminarlo de la pila.
    3. Llenar nuevamente la pila original con los datos resguardados en la pila auxiliar
    */

   if (vacia()==1)
   {
        cout<<"La pila esta vacia";
   }
   else
   {
    
        while (aqui->dato != n && aqui->sig != NULL)
        {
            if (pila_aux == NULL)
            {
                pila_rpld->dato = temp_ptr->dato;
                pila_rpld->sig = NULL;
            }
            else
            {
                pila_aux->dato = temp_ptr->dato;
                pila_aux->sig = pila_rpld;
                pila_rpld = pila_aux;

            }
            
            temp_ptr = temp_ptr->sig;
            aqui = aqui->sig;
            
        }

        if (aqui->dato == n)
        {

            temp_ptr = temp_ptr->sig;

            
            //aqui=NULL;

            temp_ptr->dato = pila_aux->dato;
            temp_ptr->sig = aux_ptr;
            //aux_ptr=NULL;

            cout<<"Nodo eliminado con exito";
        }
        else
        {
            cout<<"El nodo no existe en la pila";
        }

   }

}