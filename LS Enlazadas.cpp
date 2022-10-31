#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
int gotoxy(USHORT x,USHORT y){                                  
	COORD cp={x,y};                                                 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);
}

string titulo="LISTAS SIMPLEMENTE ENLAZADAS", titulo1="CAPTURA DE DATOS",titulo2="MUESTRA DE DATOS"/*,titulo3="MODIFICACION DE DATOS"*/,titulo3="ELIMINACION DE DATOS";

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
//void modificacion();
//void cambiar(nodo *i);
void eliminacion();

nodo *cabeza, *fin;
int main(){
	char op='S';
	while (op=='S'){
		switch(menu()){
			case 1: crear();
				break;
			case 2: muestra();
				break;
//			case 3: modificacion();
//				break;
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
//	gotoxy(40,7); cout << "3. MODIFICAR ";
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
			if (cabeza == NULL)
				cabeza =  persona ;
			else{
				fin->siguiente = persona;
			}
			fin = persona;
			do {
				gotoxy(40,15);cout<<"¿Desea ingresar los datos de otra persona? S o N: ";
				gotoxy(90,15);cin>>op;
			}while((op!='S') and (op!='N'));
		}
	}
}
void muestra(){
	nodo *persona = cabeza;
	int a=0, i;
	if (cabeza==NULL){
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
//
//void modificacion(){
//	int a, i, ced;
//	char op='S';
//	nodo *persona = cabeza;
//	if (cabeza == NULL){
//		gotoxy(40,17); cout << "No hay datos para modificar";
//		getch();
//	}
//	else{
//		while(op=='S'){
//			persona = cabeza;
//			system("cls");
//			gotoxy(45,2);cout<<titulo;
//			gotoxy(50,3);cout<<titulo3;
//			gotoxy(40,5); cout << "CEDULA   : ";
//			do{
//				gotoxy(51,5);cin>>ced;
//				gotoxy(40,7);cout<<"Ingrese un numero de cedula valido";
//			}while(ced < 0 or ced > 999999999);
//			gotoxy(40,7);cout<<"                                         ";
//			a=0;
//			while ((persona != NULL) && (a == 0)){
//				if(ced==persona->cedula){
//					a=1;
//					gotoxy(40,6); cout << "NOMBRE   = " << persona->nombre;
//		    	    gotoxy(40,7); cout << "TELEFONO = " << persona->tel;
//		    	    gotoxy(40,8); cout << "SEXO     = " << persona->sex;
//		    	    cambiar(persona);
//	        	    gotoxy(40,12); cout << "Registro modificado";
//				}
//				else{
//					persona = persona->siguiente ;
//				}
//			}
//						
//			if (a == 0){
//            	gotoxy(50,11) ; cout << "Registro no encontrado" ;
//        	}
//        	do{
//            	gotoxy(28,24); cout<<"Modificar otro rigistro S - N ";
//            	gotoxy(58,24); cin>>op; 
//			}while (( op != 'S' ) and ( op != 'N'));
//		}
//	
//	}
//}

//void cambiar(nodo *i){
//	int o = 1,f = 6;
//	char tecla;
//	gotoxy(21,15);cout<<"UTILICE : Flechas Abajo y Arriba Para Desplazarse, ENTER para seleccionar y Terminar";
//	do{
//	   gotoxy(51,f); tecla = getch();
//	   if ( kbhit()){	
//		  tecla = getch();
//		  if (tecla == 80) 
//		     {
//		     o++;
//		     f+=1;
//		     }
//		  if (tecla == 72) 
//			 {
//			 o--;
//		     f-=1;
//		     }
//		  if ((o > 3) ||  (o < 1))
//			 {
//			 o = 1;
//		     f = 13;
//			} 
//		}
//	}while((tecla == 80) or (tecla == 72));
//	
//	switch (o){ 
//	    case 1: 
//		        gotoxy(51,6); cout << "                                ";
//		        gotoxy(51,6); cin>> i->nombre;
//                gotoxy(51,6); cout << strupr(i->nombre);
//				break;
//		case 2: do {
//			       gotoxy(51,7) ; cout <<"           " ;
//			       gotoxy(51,7); cin >> i->tel ;
//                   gotoxy(51,15); cout<< "Error .... digite el telefono nuevamente";
//                } while (i->tel < 0 );
//                gotoxy(51,15); cout <<"                                         ";
//		        break;
//		case 3: do{
//					gotoxy(20,18);cout << " Digite : M-> Masculino o F -> Femenino " ;
//					gotoxy(51,8);cin>>i->sex;
//					gotoxy(20,15);cout<< "Error .... digite el sexo nuevamente ";
//				}while((i->sex!='M') and (i->sex!='F'));
//		        gotoxy(20,15); cout << "                                           ";
//				break;
//		}
//   gotoxy(20,21);cout<<"                                                                                     ";
//}

void eliminacion(){
	int a, ced, o;
	char op='S';
	nodo *i, *persona;
	while (op=='S'){
		if (cabeza == NULL){
			gotoxy(40,17); cout << "No hay datos para eliminar";
			op='N';
			getch();
		}
		else{
			persona = cabeza;
			system("cls");
			gotoxy(45,2);cout<<titulo;
			gotoxy(50,3);cout<<titulo3;
			gotoxy(40,5); cout << "CEDULA   : ";
			do{
				gotoxy(51,5);cin>>ced;
				gotoxy(40,7);cout<<"Ingrese un numero de cedula valido";
			}while(ced<0 or ced>999999999);
			gotoxy(40,7);cout<<"                                         ";
			a=0;
			while ((persona != NULL) && (a == 0)){
				if(ced==persona->cedula){
					gotoxy(40,6); cout << "NOMBRE   = " << persona->nombre;
		    	    gotoxy(40,7); cout << "TELEFONO = " << persona->tel;
		    	    gotoxy(40,8); cout << "SEXO     = " << persona->sex;
		    	    a=1;
		    	    if  (persona == cabeza){
						cabeza = persona->siguiente;
					}
	            	else{
						i->siguiente = persona->siguiente;
						if  (fin == persona){
							fin = i;
						}
					}
				   delete(persona);
				   gotoxy(50,11); cout << "Elemento Eliminado"; 
				}
				else{
					i  = persona;
					persona  = persona->siguiente ;
	           }
				
			}
			if (a == 0){
				gotoxy(50,11) ; cout << "Registro no encontrado" ;
			}
			do{
            	gotoxy(28,24); cout<<"Eliminar otro registro S - N";
            	gotoxy(52,24); cin>>op; 
			}while (( op != 'S' ) and ( op != 'N'));
		}
	
	}
}
