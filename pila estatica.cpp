#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
int gotoxy(USHORT x,USHORT y){                                  
	COORD cp={x,y};                                                 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}

string titulo="PILA ESTATICA", titulo1="CAPTURA DE DATOS",titulo2="MUESTRA DE DATOS",titulo3="ELIMINACION DE DATOS";

struct nodo{
	int cedula; 
	char nombre[50];
	unsigned tel;
	char sex;
};
void detalle();
int menu();
void crear(); 
void muestra();
void eliminacion();


  nodo pila[50];
  int   tope = -1;

int main(){
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
 

void detalle(){
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
	char op='S';
	while ((op=='S')and(tope<50)){
		system("cls");
		gotoxy(45,2);cout<<titulo;
		gotoxy(43,3);cout<<titulo1;
		gotoxy(40,5); cout << "CEDULA   : ";
		gotoxy(40,6) ;cout << "NOMBRE   : ";
		gotoxy(40,7) ;cout << "TELEFONO : ";
		gotoxy(40,8) ;cout << "SEXO     : ";
		tope = tope+1;
		do{
			gotoxy(51,5);cin>>pila[tope].cedula;
			gotoxy(40,15);cout<< "Error... digite la cedula nuevamente ";
		}while((pila[tope].cedula<0 or pila[tope].cedula>999999999));
		gotoxy(40,15);cout <<"                                           ";
		gotoxy(51,6);cin>>pila[tope].nombre;
		do{
			gotoxy(51,7);cin>>pila[tope].tel;
			gotoxy(40,15);cout<< "Error... digite el telefono nuevamente ";
		}while((pila[tope].tel<0));
		gotoxy(40,15);cout <<"                                           ";
		do{
			gotoxy(40,15);cout << " Digite : M-> Masculino o F -> Femenino " ;
			gotoxy(51,8);cin>>pila[tope].sex;
			gotoxy(40,16);cout<< "Error... digite el sexo nuevamente ";
		}while((pila[tope].sex!='M') and (pila[tope].sex!='F'));
		gotoxy(40,16);cout <<"                                           ";
		do {
			gotoxy(40,15);cout<<"¿Desea ingresar los datos de otra persona? S o N: ";
			gotoxy(90,15);cin>>op;
		}while((op!='S') and (op!='N'));
	}
}
void muestra(){
	int a=0, i;
	if (tope<0){
		gotoxy(40,17); cout << "No hay datos para mostrar";
		getch();
	}
	else{
		a=11;
		detalle();
		for(i = tope; i>=0; i--){
			gotoxy(12,a);cout<<pila[i].cedula;
			gotoxy(24,a);cout<<pila[i].nombre;
			gotoxy(55,a);cout<<pila[i].tel;
			gotoxy(68,a);cout<<pila[i].sex;
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
	while (op=='S'){
		if (tope < 0){
			gotoxy(28,24); cout << "No hay datos para eliminar         ";
			op='N';
			getch();
		}
		else{
			system("cls");
			gotoxy(45,2);cout<<titulo;
			gotoxy(43,3);cout<<titulo3;
			gotoxy(40,5); cout << "CEDULA   :   " << pila[tope].cedula;
			gotoxy(40,6); cout << "NOMBRE   :   " << pila[tope].nombre;
			gotoxy(40,7); cout << "TELEFONO :   " << pila[tope].tel;
			gotoxy(40,8); cout << "SEXO     :   " << pila[tope].sex;
			tope = tope-1;
			gotoxy(50,11); cout << "Elemento Eliminado"; 
			do{
            	gotoxy(28,24); cout<<"Eliminar otro registro S - N";
            	gotoxy(59,24); cin>>op; 
			}while (( op != 'S' ) and ( op != 'N'));
		}
	
	}
}
