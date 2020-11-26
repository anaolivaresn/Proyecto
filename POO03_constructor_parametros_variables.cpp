# include <stdio.h>
# include <conio.h>
# include <String.h>

class Computadora{
	public:
		char ac_procesador[21], ac_memoria[21], ac_dd[21], ac_monitor[21];
	
	public:
		Computadora(char par_procesador[21], char par_memoria[21], char par_dd[21], char par_monitor[21]){
			strcpy(ac_procesador,par_procesador);
			strcpy(ac_memoria,par_memoria);
			strcpy(ac_dd,par_dd);
			strcpy(ac_monitor,par_monitor);
		}
		
		void muestra(){
			printf("Procesador : %s\n",ac_procesador);
			printf("Memoria    : %s\n",ac_memoria);
			printf("Disco Duro : %s\n",ac_dd);
			printf("Monitor    : %s\n",ac_monitor);
			printf("--------------------------------------\n");
		}
};

main(){
	char v_procesador[21], v_memoria[21], v_dd[21], v_monitor[21];
	printf("Indica el procesador : "); gets(v_procesador);
	printf("Indica la memoria    : "); gets(v_memoria);
	printf("Indica el Disco Duro : "); gets(v_dd);
	printf("Indica el monitor    : "); gets(v_monitor);
	
	Computadora compu1(v_procesador, v_memoria, v_dd, v_monitor);
	compu1.muestra();
}
