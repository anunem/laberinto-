#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
#include <string.h>
struct thread_parms{
    int pos_fila;
    int pos_col;
    int hilo_numero;
    int fin_fil;
    int fin_col;
    char ** matriz;
    int num_fil;
    int num_col;
};

int numero_hilos =0;
pthread_t tid[100];
struct thread_parms tp[100];
int final =0;


void *dothread( void *param){
    int pos_fila;
    int pos_col;
    int hilo_numero;
    int fin_fil;
    int fin_col;
    int contador;
    char ** matriz; 
    int num_fil;
    int num_col;
    int i;
    int j;
    struct thread_parms *p = (struct thread_parms *) param;
    pos_fila=p->pos_fila;
    pos_col=p->pos_col;
    fin_fil=p->fin_fil;
    fin_col=p->fin_col;
    hilo_numero=p->hilo_numero;
    matriz=p->matriz;
    num_fil=p->num_fil;
    num_col=p->num_col;



    while (final==0){
        contador=0;
        
        matriz[pos_fila][pos_col]='.';

        if(matriz[pos_fila-1][pos_col]==' ' && matriz[pos_fila-1][pos_col]!='.' && pos_fila>0 ){
        contador ++;
        }

        if(matriz[pos_fila+1][pos_col]==' ' && matriz[pos_fila+1][pos_col]!='.' && pos_fila<num_fil){
        contador ++;
        }

        if(matriz[pos_fila][pos_col+1]==' ' && matriz[pos_fila][pos_col+1]!='.' && pos_col<num_col){
        contador ++;
        //printf("col +1 \n ");
        }

        if(matriz[pos_fila][pos_col-1]==' ' && matriz[pos_fila][pos_col-1]!='.' && pos_col>0 ){
        contador ++;
        }
        //printf ("cobtaador = %d \n",contador);
       

        if (contador==0){
           // printf("elemino el hilo %d",hilo_numero);
        }

        else {
                    
                    if(matriz[pos_fila-1][pos_col]==' ' && matriz[pos_fila-1][pos_col]!='.' && pos_fila>0 && contador>1 ){
                        //printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila-1;
                        tp[numero_hilos].pos_col=pos_col;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila-1][pos_col]==' ' && matriz[pos_fila-1][pos_col]!='.' && pos_fila>0 && contador==1){
                                pos_fila=pos_fila-1;
                                //printf("avanzo1 ");
                        }
                    if(matriz[pos_fila+1][pos_col]==' ' && matriz[pos_fila+1][pos_col]!='.' && pos_fila<num_fil && contador>1){
                       // printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila+1;
                        tp[numero_hilos].pos_col=pos_col-1;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila+1][pos_col]==' ' && matriz[pos_fila+1][pos_col]!='.' && pos_fila<num_fil && contador==1){
                                pos_fila=pos_fila+1;
                                //printf("avanzo ");
                        }

                    if(matriz[pos_fila][pos_col+1]==' ' && matriz[pos_fila][pos_col+1]!='.' && pos_col<num_col && contador>1){
                        //printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila;
                        tp[numero_hilos].pos_col=pos_col+1;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila][pos_col+1]==' ' && matriz[pos_fila][pos_col+1]!='.' && pos_col<num_col && contador==1){
                                pos_col=pos_col+1;
                                // printf("avanzo2 \n");
                                //printf("%d \n",pos_col);
                        }

                    if(matriz[pos_fila][pos_col-1]==' ' && matriz[pos_fila][pos_col-1]!='.' && pos_col>0 && contador>1 ){
                        //printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila;
                        tp[numero_hilos].pos_col=pos_col-1;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila][pos_col-1]==' ' && matriz[pos_fila][pos_col-1]!='.' && pos_col>0 && contador==1){
                                pos_col=pos_col-1;
                               // printf("avanzo ");
                        }                      
        
        }
        // printf("%d  %d \n",pos_fila,pos_col);

        
        //sleep(1);
        if (pos_fila==fin_fil && pos_col==fin_col)     {
           final=1;
        printf("un hilo ha llegado \n");
        printf("el hilo que ha llegado es %d \n",p->hilo_numero);
        matriz[pos_fila][pos_col]='F';
       }
        
  
    }
    


    

}




int main() {

    FILE* f;
    int num_col=0;
    int num_fil=0;
    char caracter;
    char **matriz;
    int i;
    int j;
    int init_fil;
    int init_col;
    int fin_col;
    int fin_fil;
    int pos_col;
    int pos_fila;
    int contador;
    int fila_anterior;
    int col_anterior;


    f= fopen("labyrinth.txt", "r");
    while(!feof(f)) {
        num_col=num_col+1;
        fscanf(f,"%c",&caracter);
        //printf("%c",caracter);
        
        if (caracter =='\n')
        {
        num_fil=num_fil+1;
    
        } 
    }
    fclose(f);
    //printf("%d \n",num_col);
    //printf("%d\n",num_fil);
    num_col=(num_col-1)/(num_fil-1) ;
    num_fil=(num_fil-1);

    printf("numero de col = %d \n",num_col);
    printf("numero de fila = %d \n",num_fil);



    matriz = (char **)malloc (num_fil*sizeof(char *));

    for (i=0;i<num_fil;i++)
    matriz[i] = (char *) malloc (num_col*sizeof(int));
    
    f= fopen("labyrinth.txt", "r");
    for (i=0;i<num_fil;i++){
        for(j=0;j<num_col;j++){
            fscanf(f,"%c",&matriz[i][j]);
            
        }
    }
/*
    for (i=0; i<num_fil; i++) 
	{ 
		
		for (j=0; j<num_col; j++) 
        
			printf("%c", matriz[i][j] ); 
	}
*/
    for (i=0; i<num_fil; i++) 
	{ 
		
		for (j=0; j<num_col; j++) 
			if (matriz[i][j]=='I'){
            init_fil=i;
            init_col=j;
            }
    }
    
    printf ("posicion inicial =%d %d \n",init_fil,init_col);
        
    for (i=0; i<num_fil; i++) 
	{ 
		
		for (j=0; j<num_col; j++) 
			if (matriz[i][j]=='O'){
            fin_fil=i;
            fin_col=j;
            matriz[i][j]=' ';
            }
    }
    printf ("posicion final =%d %d\n",fin_fil,fin_col);
    
    pos_fila=init_fil;
    pos_col=init_col;
    col_anterior=init_col;
    fila_anterior=init_fil;

    while (final==0){
        contador=0;
        
        matriz[pos_fila][pos_col]='.';

        if(matriz[pos_fila-1][pos_col]==' ' && matriz[pos_fila-1][pos_col]!='.' && pos_fila>0 ){
        contador ++;
        }

        if(matriz[pos_fila+1][pos_col]==' ' && matriz[pos_fila+1][pos_col]!='.' && pos_fila<num_fil){
        contador ++;
        }

        if(matriz[pos_fila][pos_col+1]==' ' && matriz[pos_fila][pos_col+1]!='.' && pos_col<num_col){
        contador ++;
        //printf("col +1 \n ");
        }

        if(matriz[pos_fila][pos_col-1]==' ' && matriz[pos_fila][pos_col-1]!='.' && pos_col>0 ){
        contador ++;
        }
        //printf ("cobtaador = %d \n",contador);
       

        if (contador==0){
           // printf("El hilo principal se ha atascado ");
        }

        else {
                    
                    if(matriz[pos_fila-1][pos_col]==' ' && matriz[pos_fila-1][pos_col]!='.' && pos_fila>0 && contador>1 ){
                        //printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila-1;
                        tp[numero_hilos].pos_col=pos_col;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila-1][pos_col]==' ' && matriz[pos_fila-1][pos_col]!='.' && pos_fila>0 && contador==1){
                                pos_fila=pos_fila-1;
                                //printf("avanzo1 ");
                        }
                    if(matriz[pos_fila+1][pos_col]==' ' && matriz[pos_fila+1][pos_col]!='.' && pos_fila<num_fil && contador>1){
                       // printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila+1;
                        tp[numero_hilos].pos_col=pos_col-1;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila+1][pos_col]==' ' && matriz[pos_fila+1][pos_col]!='.' && pos_fila<num_fil && contador==1){
                                pos_fila=pos_fila+1;
                                //printf("avanzo ");
                        }

                    if(matriz[pos_fila][pos_col+1]==' ' && matriz[pos_fila][pos_col+1]!='.' && pos_col<num_col && contador>1){
                        //printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila;
                        tp[numero_hilos].pos_col=pos_col+1;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila][pos_col+1]==' ' && matriz[pos_fila][pos_col+1]!='.' && pos_col<num_col && contador==1){
                                pos_col=pos_col+1;
                                //printf("avanzo2 \n");
                                //printf("%d \n",pos_col);
                        }

                    if(matriz[pos_fila][pos_col-1]==' ' && matriz[pos_fila][pos_col-1]!='.' && pos_col>0 && contador>1 ){
                        //printf("creo hilos");
                        numero_hilos ++;
                        contador--;
                        tp[numero_hilos].pos_fila=pos_fila;
                        tp[numero_hilos].pos_col=pos_col-1;
                        tp[numero_hilos].hilo_numero=numero_hilos;
                        tp[numero_hilos].matriz=matriz;
                        tp[numero_hilos].fin_col=fin_col;
                        tp[numero_hilos].fin_fil=fin_fil;
                        tp[numero_hilos].num_col=num_col;
                        tp[numero_hilos].num_fil=num_fil;
                        pthread_create (&tid[numero_hilos], NULL,&dothread, (void *) &tp[numero_hilos]);
                    }
                        else if (matriz[pos_fila][pos_col-1]==' ' && matriz[pos_fila][pos_col-1]!='.' && pos_col>0 && contador==1){
                                pos_col=pos_col-1;
                               // printf("avanzo ");
                        }                      
        
        }
        // printf("%d  %d \n",pos_fila,pos_col);

        //sleep(1);
        //printf("\n \n \n \n");
          if (pos_fila==fin_fil && pos_col==fin_col)     {
            final=1;
            
            matriz[pos_fila][pos_col]='F';
        }
  
    }  
    sleep(.2);
    for (i=0; i<num_fil; i++) 
    { 
        
        for (j=0; j<num_col; j++) 
        
            printf("%c", matriz[i][j] ); 
    }
        
    printf("un hilo ha llegado\n");
    printf("hago join de todos los hilos \n ");

    for (i=0; i<numero_hilos; i++) {
			pthread_join (tid[i],NULL);
            printf("join del hilo %d \n ",i);
	}
    

return 0;
}

