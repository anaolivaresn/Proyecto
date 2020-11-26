# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream> // Librería para archivos
using namespace std; // Manipular los archivos

// Estructura
// Matrícula	9 A01234567
// Nombre		30
// Ap. Pat		30
// Ap. Mat		30
// Carrera		4
// Promedio		int 0-100

char mat[10], nom[31], ap[31], am[31], car[5];
int prom;
char falso[2];
char mat_busca[10];

bool busca_matricula(){
	do{
		printf("Indica la matr%ccula         : ",161); gets(mat_busca);
		if (strlen(mat_busca)!=9){
			printf("Error, matr%ccula debe tener 9 posiciones ...\n",161);
			getche();
		}
	} while (strlen(mat_busca)!=9);
	
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	while (!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>prom;
		if (strcmp(mat,mat_busca)==0) return(true);
	}
	arch.close();
	return(false);	
}

void pide_datos(){
	if (busca_matricula()){
		printf("Error, la matr%cicula se duplica en el archivo ...\n",161);
		getche();
	}
	else{
		strcpy(mat,mat_busca);
		do{
			printf("Indica el nombre            : "); gets(nom);
			if ((strlen(nom)<1) || (strlen(nom)>30)){
				printf("Error, nombre entre 1 y 30 caracteres ...\n");
				getche();
			}
		} while ((strlen(nom)<1) || (strlen(nom)>30));
	
		do{
			printf("Indica el Ap. Paterno       : "); gets(ap);
			if ((strlen(ap)<1) || (strlen(ap)>30)){
				printf("Error, Ap. Paterno entre 1 y 30 caracteres ...\n");
				getche();
			}
		} while ((strlen(ap)<1) || (strlen(ap)>30));
	
		do{
			printf("Indica el Ap. Materno       : "); gets(am);
			if ((strlen(am)<1) || (strlen(am)>30)){
				printf("Error, Ap. Materno entre 1 y 30 caracteres ...\n");
				getche();
			}
		} while ((strlen(am)<1) || (strlen(am)>30));
		
		do{
			printf("Indica el la carrera        : "); gets(car);
			if ((strlen(car)<1) || (strlen(car)>4)){
				printf("Error, Carrera entre 1 y 4 caracteres ...\n");
				getche();
			}
		} while ((strlen(car)<1) || (strlen(car)>4));
	
		do{
			printf("Indica el promedio          : "); scanf("%d",&prom);
			if ((prom<1) || (prom>100)){
				printf("Error, promedio entre 1 y 100 cracateres ...\n");
				getche();
			}
		} while ((prom<1) || (prom>100));
		
		for (int i=0;i<strlen(nom);i++) if (nom[i]==' ') nom[i]='_';
		for (int i=0;i<strlen(ap);i++) if (ap[i]==' ') ap[i]='_';
		for (int i=0;i<strlen(am);i++) if (am[i]==' ') am[i]='_';
		ofstream arch;
		arch.open("alumnos.txt",ios::app);
		arch <<mat <<" " <<nom <<" " <<ap <<" " <<am <<" " <<car <<" " <<prom  <<"\n";
		arch.close();
	} // Valida que no se duplique
}

void consulta_alumnos(){
	if (!busca_matricula()){
		printf("Error, la matr%ccula no existe en el archivo ...\n",161);
		getche();
	}
	else{
		printf("Nombre      : %s\n",nom);
		printf("Ap. Paterno : %s\n",ap);
		printf("Ap. Materno : %s\n",am);
		printf("Carrera     : %s\n",car);
		printf("Promedio    : %d\n",prom);
		getche();
	}
}

void lista_total(){
	printf("Matricula                Nombre           Ap. Paterno           Ap. Materno  Carrera  Promedio\n");
	//      123456789  123456789/123456789/  123456789/123456789/  123456789/123456789/    1234      123
	printf("----------------------------------------------------------------------------------------------\n");
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	while (!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>prom;
		if (!arch.eof()){
			printf("%s  ",mat);
			printf("%20s  ",nom);
			printf("%20s  ",ap);
			printf("%20s    ",am);
			printf("%4s      ",car);
			printf("%3d\n",prom);
		}
	}
	arch.close();
	getche();
}

void lista_carrera(){
	char car_listar[5];
	printf("Indica la carrera a listar : "); gets(car_listar);
	printf("Matricula                Nombre           Ap. Paterno           Ap. Materno  Carrera  Promedio\n");
	//      123456789  123456789/123456789/  123456789/123456789/  123456789/123456789/    1234      123
	printf("----------------------------------------------------------------------------------------------\n");
	ifstream arch;
	arch.open("alumnos.txt",ios::in);
	while (!arch.eof()){
		arch >>mat >>nom >>ap >>am >>car >>prom;
		if ((!arch.eof()) && (strcmp(car,car_listar)==0)){
			printf("%s  ",mat);
			printf("%20s  ",nom);
			printf("%20s  ",ap);
			printf("%20s    ",am);
			printf("%4s      ",car);
			printf("%3d\n",prom);
		}
	}
	arch.close();
	getche();
}

void menu(){
	int op=0;
	while(op!=5){
		printf("1) Alta de alumnos\n");
		printf("2) Consulta de alumnos\n");
		printf("3) Listar Alumnos\n");
		printf("4) Listar por carrera\n");
		printf("5) Terminar\n");
		printf("Indica la opci%cn deseada : ",162); scanf("%d",&op); gets(falso);
		
		if (op==1) pide_datos();
		if (op==2) consulta_alumnos();
		if (op==3) lista_total();
		if (op==4) lista_carrera();
	}
}

main(){
	menu();
}
