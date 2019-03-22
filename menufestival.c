#include <stdio.h>

/* A: Agregar el dia/dias que quiere ver del festival (15,16,17,18 de agosto)
B: Ver todos los días disponibles.
C: precio.
D: Salir programa.*/

int main(){
	
	char opcion;
	float vectordia[60], preciofestival, preciodia;
	int i, totaldias = 0;
	do{
	
	printf("Elija una de las opciones disponibles: \n 'A' introducir el día/s del festival,'B' Ver los días disponibles,'C' precios,'D'Salir programa\n");
	fflush(stdin);
	scanf("%c", &opcion);
	
	switch (opcion){
		case 'A' : printf("Introduzca el día o días que desea asistir: \n");
		
		scanf("%f", &vectordia[totaldias]);
		
		totaladias++; //Se incrementa el contador.
		
		break;
		
		case 'B': 
		
		if(totaldias==0){
			printf("No hay días dsiponibles");
		}
		else{
		
		 for(i=0; i<totaldias; i++){
			
	   	printf("Los días disponibles son: %.2f \n", vectordia[i]);
		
	      }
    	}
 		
		break;
		
		case 'C': 
		
		if (totalprecio == 0){
			printf("No hay precios disponibles\n");
		}
		else{
			for(i=0; i<totalprecio; i++){
				precio = preciodia + vectordia[i];
			}
			preciofestival = dia1+dia2+dia3;
			printf("El precio de todo el festival es: %f\n", preciofestival);
		}
		break;
		
		case 'D': printf("Salir del programa");
		break;
		
		default: printf("Opcion incorrecta\n");
		}
	}while (opcion!= 'D');
	
	
	
	
	
	
	
	return 0;
}
