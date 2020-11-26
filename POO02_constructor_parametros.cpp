# include <stdio.h>
# include <conio.h>
# include <String.h>

class Persona{
	public:
		char ac_nom[21], ac_aps[21];
		int ac_edad;
	public:
		Persona(char par_nom[21], char par_aps[21], int par_edad){
			strcpy(ac_nom,par_nom);
			strcpy(ac_aps,par_aps);
			ac_edad=par_edad;
		}
		
		void muestra(){
			printf("Nombre    : %s\n",ac_nom);
			printf("Apellidos : %s\n",ac_aps);
			printf("Edad      : %d\n",ac_edad);
			printf("-----------------------------------\n");
		}
};

main(){
	Persona persona1("Juan","Perez Lopez",15);
	persona1.muestra();
}
