#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
int gotoxy(USHORT x,USHORT y){                                  
	COORD cp={x,y};                                                 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}

string titulo="COLA DINAMICA", titulo1="CAPTURA DE DATOS",titulo2="MUESTRA DE DATOS",titulo3="ELIMINACION DE DATOS";


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

nodo cola[50];
int   frente = 0, fin = -1; 

int main(){
	char op='S';
	frente = NULL;
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
	while ((op=='S')and(fin<50)){
		system("cls");
		gotoxy(45,2);cout<<titulo;
		gotoxy(50,3);cout<<titulo1;
		gotoxy(40,5); cout << "CEDULA   : ";
		gotoxy(40,6) ;cout << "NOMBRE   : ";
		gotoxy(40,7) ;cout << "TELEFONO : ";
		gotoxy(40,8) ;cout << "SEXO     : ";
		fin = fin+1;
		do{
			gotoxy(51,5);cin>>cola[fin].cedula;
			gotoxy(40,15);cout<< "Error... digite la cedula nuevamente ";
		}while((cola[fin].cedula<0 or cola[fin].cedula>999999999));
		gotoxy(40,15);cout <<"                                           ";
		gotoxy(51,6);cin>>cola[fin].nombre;
		do{
			gotoxy(51,7);cin>>cola[fin].tel;
			gotoxy(40,15);cout<< "Error... digite el telefono nuevamente ";
		}while((cola[fin].tel<0));
		gotoxy(40,15);cout <<"                                           ";
		do{
			gotoxy(40,15);cout << " Digite : M-> Masculino o F -> Femenino " ;
			gotoxy(51,8);cin>>cola[fin].sex;
			gotoxy(40,16);cout<< "Error... digite el sexo nuevamente ";
		}while((cola[fin].sex!='M') and (cola[fin].sex!='F'));
		gotoxy(40,16);cout <<"                                           ";
		do {
			gotoxy(40,15);cout<<"¿Desea ingresar los datos de otra persona? S o N: ";
			gotoxy(90,15);cin>>op;
		}while((op!='S') and (op!='N'));
	}
}
void muestra(){
	int a=0;
	if (fin<0){
		gotoxy(40,17); cout << "No hay datos para mostrar";
		getch();
	}
	else{
		a=11;
		detalle();
		for(frente = 0; frente<=fin; frente++){
			gotoxy(12,a);cout<<cola[frente].cedula;
			gotoxy(24,a);cout<<cola[frente].nombre;
			gotoxy(55,a);cout<<cola[frente].tel;
			gotoxy(68,a);cout<<cola[frente].sex;
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
		if (fin < 0){
			gotoxy(28,24); cout << "No hay datos para eliminar         ";
			op='N';
			getch();
		}
		else{
			system("cls");
			frente = 0;
			gotoxy(45,2);cout<<titulo;
			gotoxy(43,3);cout<<titulo3;
			gotoxy(40,5); cout << "CEDULA   :   " << cola[frente].cedula;
			gotoxy(40,6); cout << "NOMBRE   :   " << cola[frente].nombre;
			gotoxy(40,7); cout << "TELEFONO :   " << cola[frente].tel;
			gotoxy(40,8); cout << "SEXO     :   " << cola[frente].sex;
			for (frente = 0; frente <= fin; frente++ ){
		            cola[frente].cedula = cola[frente+1].cedula;	
					strcpy(cola[frente].nombre, cola[frente+1].nombre);
					cola[frente].tel  = cola[frente+1].tel;
					cola[frente].sex = cola[frente+1].sex;
		    }
			fin = fin-1;
			gotoxy(50,11); cout << "Elemento Eliminado"; 
			do{
            	gotoxy(28,24); cout<<"Eliminar otro registro S - N";
            	gotoxy(59,24); cin>>op; 
			}while (( op != 'S' ) and ( op != 'N'));
		}
	
	}
}
