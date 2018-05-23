//preguntar si hay q verificar que el telefono,DNI no se ponga negativo por el usuario
#include <iostream>
#include <string.h>

using namespace std;
//----------------------------------------------------------------------
              	//Fecha
class Fecha{
	protected:  //cambiar si no se usa herencia
		int dia;
		int mes;
		int anio;
	public:
		Fecha();
		Fecha(int, int , int); //incluir destructor
		void setdia(int dia);
		void setmes(int mes);
		void setanio(int anio);
		int getdia();//capaz poner "{return dia;};"
		int getmes();
		int getanio();
		int valida();
		void operator ++(); 
		Fecha operator +(int);	
};
Fecha::Fecha(){ //inicializar en dia actual?
	dia = 0;
	mes = 0;
	anio = 0;
}
Fecha::Fecha(int d,int m,int a){ 
	anio = a;
	mes = m;
	dia = d;
}
void Fecha::setdia(int d){	
	dia = d;
}
void Fecha::setanio(int a){ 
	anio = a;
}
void Fecha::setmes(int m){
	mes = m;
}
int Fecha::getdia(){ 
	return dia;
}
int Fecha::getmes(){ 
	return mes;
}
int Fecha::getanio(){ 
	return anio;
}
int Fecha::valida(){ //usar valida en el main para controlar fecha
	if(dia<1 || dia>31 || mes>12){
		return 0;
	}
	if(dia>30 && (mes==4 || mes == 6 || mes == 9 || mes == 11)){
		return 0;
	}
	if(mes == 2 && (dia>29 || (dia>28 && anio%4 !=0))){ 
		return 0;
	}
	return 1;
}
void Fecha::operator ++(){
	dia++;
	if(!valida()){ 
		dia = 1;
		mes++;
		if(!valida()){ 
			mes = 1;
			anio++;
		}
	}
}
Fecha Fecha::operator +(int dd){ 
	Fecha Resultante(dia, mes, anio); 
	for(int i=0;i<dd;i++){
		++Resultante; 
	}
}
void Fecha::operator --(){   //revisar a la hora de ejecutar
	dia--;
	if(!valida()){ 
	  dia++;
	  if(mes==4 || mes == 6 || mes == 9 || mes == 11){
		dia = 30;
		mes--;
		}
	  if(mes==1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
	    dia = 31;
		mes--;  	
		if(!valida()){ 
			mes = 12;
			anio--;
		}
	  }
	  if(mes == 3 && (dia == 1){
	  	dia=29;
	  	mes--;
	  }
	  if(mes == 3 && (dia == 1 && anio%4 == 0) ){
	  	dia=28;
	  	mes--;
	  }
    }
}
Fecha Fecha::operator -(int dd){   //revisar a la hora de ejecutar
	Fecha Resultante(dia, mes, anio); 
	for(int i=dd;i>0;i--){
		--Resultante; 
	}
}
  			  	//Fecha
//-----------------------------------------------------------------
  			  	//Persona
class Persona{
	protected: //cambiar si no se usa herencia
		int DNI;
		char nombre[50];
		char apellido[50];
		int telfijo;
		int telmovil;
	public:
	    Persona(int,char,char,int,int);//revisar sintaxis
		Persona();		//incluir destructor
		void setDNI(int dni);
		void setnombre(char n[50]);
		void setapellido(char a[50]); 
		void settelfijo(int fijo);
		void settelmovil(int movil);
		int getDNI();//capaz poner "{return DNI;};"
		char getnombre();
		char getapellido(); 
		int gettelfijo();
		int gettelmovil();
		//verificar si tel, DNI son correctos?		
};
Persona::Persona(int dni,char n[50],char a[50],int fijo,int movil){
	DNI=dni;
	strcpy(nombre,n);
	strcpy(apellido,a);
	telfijo=fijo;
	telmovil=movil;
}
Persona::Persona(){ //ver si inicializar cadenas
	DNI=0;
	telfijo=0;
	telmovil=0;
}
void Persona::setDNI(int dni){
	DNI=dni;
}
void Persona::setnombre(char n[50]){
	strcpy(nombre,n);
}
void Persona::setapellido(char a[50]){
	strcpy(apellido,a);
}
void Persona::settelfijo(int fijo){
	telfijo=fijo;
}
void Persona::settelmovil(int movil){
	telmovil=movil;
}
int Persona::getDNI(){
	return DNI;
}
char Persona::getnombre(){
	return nombre;
}
char Persona::getapellido(){
	return apellido;
}
int Persona::gettelfijo(){
	return telfijo;
}
int Persona::gettelmovil(){
	return telmovil;
}
				//Persona
//-----------------------------------------------------------------------------
                //Prestamo
class Prestamo:Persona:Fecha{//revisar sintaxis de herencia
	protected: //ver si poner private
		int numprestamo;		// controlar que sea mayor que cero
		                		//revisar ,como es herencia como es la sintaxis para incluir a persona
		float valor;      		//controlar que sea mayor que cero
		int tasadeinteres;
		int cuotas;
	public:
		Prestamo(int,int,int,int,char,char,int,int,int,float,int,int);	//revisar //es posible no incluir las fechas al constructor?
		Prestamo();
		void setnumprestamo(int);
		void setvalor(float);
		void settasadeinteres(int);
		void setcuotas(int);
		int getnumprestamo();
		float getvalor();
		int gettasadeinteres();
		int getcuotas();
//falta metodos de se usa fecha		
		
		
		 
	
	

};                








