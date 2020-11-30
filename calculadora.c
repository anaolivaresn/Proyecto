#include <stdio.h>
#include <conio.h>
float radianes, grados, radio, volumen;
int select=1;
main(){
    while (select!=0){
    printf("------CALCULARDORA---------\n");
    printf("---------------------------\n");
    printf("1) CONVERSION DE GRADOS A RADIANES\n");
    printf("2) VOLUMEN DE UN CIRCULO\n");
    printf("TECLEE EL NUMERO DE LA OPERACION A REALIZAR:   "); scanf("%d",&select);

      switch (select){
          case 0:{
            printf("Adios!\n" );
            break;
          }
          case 1:{
              printf("INDIQUE LOS GRADOS QUE DESEE CONVERTIR A RADIANES: "); scanf("%f",&grados);
              radianes=(grados*3.1415926/180);
              printf("RADIANES =  %.3f\n",radianes);
              break;
          }
          case 2:{
              printf("INDIQUE EL RADIO:  ");scanf("%f",&radio);
              volumen=(3.1415926*4/3*(radio*radio*radio));
              printf("VOLUMEN =  %.3f\n",volumen);
              break;
          }
          default:{
              printf("Opcion Invalida\n  ");
              break;
          }
        }
    }
}
