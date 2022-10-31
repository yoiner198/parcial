#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
int gotoxy(USHORT x,USHORT y){                                  
	COORD cp={x,y};                                                 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}

string titulo="PILA DINAMICA", titulo1="CAPTURA DE DATOS",titulo2="MUESTRA DE DATOS",titulo3="ELIMINACION DE DATOS";

struct nodo{
	int cedula; 
	char nombre[50];
	unsigned tel;
	char sex;
	nodo    *siguiente;
};

void detalle();
int menu();
void crear(); 
void muestra();
void eliminacion();

nodo *tope;

int main(){
	tope = NULL;
	char op='S';
	while (op=='S'){
		switch(menu()){
			case 1: crear();
				break;
			case 2: muestra();
				break;
			case 3: eliminacion();
				break;
			case 4:
				op='N';
				break;
	};
	}	
}

void detalle()
   {
   system("cls");
   gotoxy(30,3) ; cout << titulo;
   gotoxy(35,5) ; cout << titulo2;
   gotoxy(12,9) ; printf("CEDULA      NOMBRE                         TELEFONO     SEXO ");
   }
  
int menu(){
	int opc;
	system("cls");
	gotoxy(45,2);cout<<titulo;
	gotoxy(40,5); cout << "1. CAPTURA DE DATOS" ;
	gotoxy(40,6); cout << "2. CONSULTA  DE DATOS";
	gotoxy(40,7); cout << "3. ELIMINAR ";
	gotoxy(40,8); cout << "4. SALIR";
	do{
		gotoxy(40,15); cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
		gotoxy(72,15); cin>>opc;
		gotoxy(40,17); cout << "OPCION NO DISPONIBLE. ";
		
	}while(opc<1 or opc>5);
	gotoxy(40,17);cout<<"                                         ";
	return opc;
}

void crear(){
	nodo *persona;
	char op='S';
	while (op=='S'){
		system("cls");
		gotoxy(45,2);cout<<titulo;
		gotoxy(50,3);cout<<titulo1;
		gotoxy(40,5); cout << "CEDULA   : ";
		gotoxy(40,6) ;cout << "NOMBRE   : ";
		gotoxy(40,7) ;cout << "TELEFONO : ";
		gotoxy(40,8) ;cout << "SEXO     : ";
		persona = new nodo;
		if (persona == NULL ){
			gotoxy(40,15); cout << "Error... no hay espacio en memoria para signar";
			getch(); op = 'N';
		}
		else{
			do{
				gotoxy(51,5);cin>>persona->cedula;
				gotoxy(40,15);cout<< "Error... digite la cedula nuevamente ";
			}while((persona->cedula<0 or persona->cedula>999999999));
			gotoxy(40,15);cout <<"                                           ";
			gotoxy(51,6);cin>>persona->nombre;
			do{
				gotoxy(51,7);cin>>persona->tel;
				gotoxy(40,15);cout<< "Error... digite el telefono nuevamente ";
			}while((persona->tel<0));
			gotoxy(40,15);cout <<"                                           ";
			do{
				gotoxy(40,15);cout << " Digite : M-> Masculino o F -> Femenino " ;
				gotoxy(51,8);cin>>persona->sex;
				gotoxy(40,16);cout<< "Error... digite el sexo nuevamente ";
			}while((persona->sex!='M') and (persona->sex!='F'));
			gotoxy(40,16);cout <<"                                           ";
			persona->siguiente = NULL ;
			if (tope == NULL)
				persona->siguiente =  NULL ;
			else{
				persona->siguiente = tope;
			}
			tope = persona;
			do {
				gotoxy(40,15);cout<<"¿Desea ingresar los datos de otra persona? S o N: ";
				gotoxy(90,15);cin>>op;
			}while((op!='S') and (op!='N'));
		}
	}
}
void muestra(){
	nodo *persona = tope;
	int a=0, i;
	if (tope==NULL){
		gotoxy(40,17); cout << "No hay datos para mostrar";
		getch();
	}
	else{
		a=11;
		detalle();
		while ( persona != NULL){
			gotoxy(12,a);cout<<persona->cedula;
			gotoxy(24,a);cout<<persona->nombre;
			gotoxy(55,a);cout<<persona->tel;
			gotoxy(68,a);cout<<persona->sex;
			persona = persona->siguiente;
            if ( a <= 24 ){
				a++ ;
			}  
            else{
                gotoxy(21,a+=3); cout << "Pulse Cualquier tecla para Continuar";
                getch();
                a = 11 ;
                detalle();
            }
		}
		gotoxy(21,a+=3); cout << "Pulse Cualquier tecla para Continuar";
        getch();
	} 
} 
void eliminacion(){
	char op='S';
	nodo *persona;
	while (op=='S'){
		if (tope == NULL){
			gotoxy(28,24); cout << "No hay datos para eliminar         ";
			op='N';
			getch();
		}
		else{
			persona = tope;
			system("cls");
			gotoxy(45,2);cout<<titulo;
			gotoxy(50,3);cout<<titulo3;
			gotoxy(40,5); cout << "CEDULA   : " << persona->cedula;
			gotoxy(40,6); cout << "NOMBRE   : " << persona->nombre;
			gotoxy(40,7); cout << "TELEFONO : " << persona->tel;
			gotoxy(40,8); cout << "SEXO     : " << persona->sex;
			tope = tope->siguiente;
			delete(persona);
			gotoxy(50,11); cout << "Elemento Eliminado"; 
			do{
            	gotoxy(28,24); cout<<"Eliminar otro registro S - N";
            	gotoxy(52,24); cin>>op; 
			}while (( op != 'S' ) and ( op != 'N'));
		}
	
	}
}
