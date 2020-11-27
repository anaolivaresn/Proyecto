#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <fstream> // Libreria para archivos
using namespace std; // Manipular los archivos

class Producto{
  //---------Atributos----------------
	public:
		int clave;
    char nombre[16];
    char familia[16];
    int existencia;
    int precio;

  //---------Metodos----------------
	public:
    //----Constructor----
		Producto(){

		}
		Producto(int c, char n[16], char f[16], int e, int p){
			setNombre(n);
			setFamilia(f);
			strcpy(familia,f);
      setClave(c);
      setPrecio(p);
      setExistencia(e);

		}
		void espacioAGuion(char c[16]){
			for (int i = 0; i < 15; i++) {
				if(c[i]==' '){
					c[i]='_';
				}
			}
		}
		void setNombre(char c[16]){
			espacioAGuion(c);
			strcpy(nombre,c);
		}
		void setFamilia(char f[16]){
			espacioAGuion(f);
			strcpy(familia,f);
		}
    int setClave(int c){
      if(c>=1&&c<=99999){
          clave=c;
          return 0;
      }
      else{
        printf("Valor de clave invalido\n" );
				clave=0;
        return 1;
      }
    }

    int setExistencia(int c){
      if(c>=1&&c<=99999){
          existencia=c;
          return 0;
      }
      else{
        printf("Valor de existencia invalido\n" );
				existencia=0;
        return 1;
      }
    }
    int setPrecio(int c){
      if(c>=1&&c<=99999){
          precio=c;
          return 0;
      }
      else{
        printf("Valor de precio invalido\n" );
				existencia=0;
        return 1;
      }
    }

		void muestra(){
			printf("Clave\t: %d\t|",clave);
			printf("Nombre\t: %s\t|",nombre);
			printf("Familia\t: %s\t|",familia);
      printf("Existencia\t: %d\t|",existencia);
      printf("Precio\t: %d\t|\n",precio);
			//printf("-----------------------------------\n");
		}
};
class Tienda{
//---------Atributos----------------
//---------Metodos----------------
public:
	Tienda(){

	}
	int  mostrarMenu(){
		printf(" ========================MENU========================\n");
		printf(" 1)	Altas de productos\n");
		printf(" 2)	Consulta de productos por clave\n");
		printf(" 3)	Lista de productos en el archivo\n");
		printf(" 4)	Lista de productos por Familia\n");
		printf(" 5)	Terminar\n");
		printf(" Tecle su opcion: ");
		char selec;
		selec=getch();//capurar un char
		printf("\n" );
		switch (selec) {
			case '1':
				altas();
				break;
			case '2':
				consultaPorClave();
				break;
			case '3':
				mostrarProductos();
				break;
			case '4':
				consultaPorFamilia();
				break;
			case '5':
				printf("Bye\n" );
				return 0;
				break;
			default:
				printf("Opcion no Valida\n" );
				break;
		}
		return 1;
	}

	void altas(){
		char clave[16];
    char nombre[16];
    char familia[16];
    char existencia[16];
    char precio[16];
		printf("\n ================Alta de productos================\n");
		printf(" Clave\t\t:");gets(clave);
		printf(" Nombre\t\t:");gets(nombre);
		printf(" Familia\t:");gets(familia);
		printf(" Existencia\t:");gets(existencia);
		printf(" Precio\t\t:");gets(precio);
		int iclave=0;
		int iexistencia=0;
		int iprecio=0;
		Producto nuevoProducto;
		if(strlen(clave)<6){
			iclave=atoi(clave);//convertir String a int
		}
		if(strlen(existencia)<7){
			iexistencia=atoi(existencia);
		}
		if(strlen(precio)<7){
			iprecio=atoi(precio);
		}
		if(strlen(nombre)<16&&strlen(familia)<16){

			nuevoProducto=Producto(iclave,nombre,familia,iexistencia,iprecio);
			if((nuevoProducto.precio>0&&nuevoProducto.clave>0&&nuevoProducto.existencia>0)){
				printf("\nProducto Creado exitosamente\n" );
				nuevoProducto.muestra();
				printf("Agregando...\n" );
				agregarProducto(nuevoProducto);
			}
		}
		else
			printf("Verifique el Nombre o la Familia del Producto (valor maximo 16 caracteres)\n");

	}
	void agregarProducto(Producto nuevoProducto){
		ofstream archEscritura;
		archEscritura.open("productos.txt",ios::app);
		if(!validarClave(nuevoProducto.clave)){
			archEscritura <<nuevoProducto.clave <<" " <<nuevoProducto.nombre <<" " <<nuevoProducto.familia <<" " <<nuevoProducto.existencia <<" " <<nuevoProducto.precio <<"\n";
			printf("Producto Agregado\n" );
		}
		else{
			printf("Error: Clave duplicada, el producto no fue agregado \n");
		}
		archEscritura.close();
	}
	bool validarClave(int clave){
		ifstream archLectura;
		archLectura.open("productos.txt",ios::in);
		Producto aux;
		while (!archLectura.eof()){
			archLectura >>aux.clave >>aux.nombre >>aux.familia >>aux.existencia >>aux.precio;
			if (clave==aux.clave) {
				archLectura.close();
				return(true);
			}

		}

		archLectura.close();
		return(false);
	}
	int consultaPorClave(){
		char clave[16];
		printf("\nIntroduzca la clave del producto: " );gets(clave);
		int iclave=atoi(clave);
		ifstream archLectura;
		archLectura.open("productos.txt",ios::in);
		Producto aux;
		while (!archLectura.eof()){//ejecutar mientras no llegue al final del archivo
			archLectura >>aux.clave >>aux.nombre >>aux.familia >>aux.existencia >>aux.precio;
			if (iclave==aux.clave&&!archLectura.eof()) {
				aux.muestra();
				archLectura.close();
				return 0;
			}
		}
	printf("Producto no encontrado\n" );
	return 1;
	}
	void mostrarProductos(){
		ifstream archLectura;
		archLectura.open("productos.txt",ios::in);
		Producto aux;
		while (!archLectura.eof()){
			archLectura >>aux.clave >>aux.nombre >>aux.familia >>aux.existencia >>aux.precio;
				if(!archLectura.eof())
					aux.muestra();

		}
		archLectura.close();

	}
	void consultaPorFamilia(){
		char familia[16];
		bool bandera=false;//badera de tipo booleano para detectar si encontramos la familia que buscamos
		printf("\nIntroduzca la familia del producto: " );gets(familia);
		ifstream archLectura;
		archLectura.open("productos.txt",ios::in);
		Producto aux;
		while (!archLectura.eof()){
			archLectura >>aux.clave >>aux.nombre >>aux.familia >>aux.existencia >>aux.precio;
			if (strcmp(familia,aux.familia)==0&&!archLectura.eof()) {
				aux.muestra();
				bandera=true;
			}
		}
	if(!bandera)//si no hay bandera se imprime: "Familia no encontrada"
		printf("Familia no encontrada\n" );

	}

};
main(){
	Tienda tienda;
	while(tienda.mostrarMenu());
}
