#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	 
            int cantidad_nombres;
            char *buff;
            char *nombre[5];
             	         
            buff=(char *)malloc(100*sizeof(char));
    
		    printf("Cuantos nombres quiere ingresar?: ");
		    scanf("%d",&cantidad_nombres);
		    fflush(stdin);
		    printf("\n");	
		    
		    for(int i=0;i<cantidad_nombres;i++)
		    {
			   printf("Ingrese el nombre %d: ",i+1);	
			   gets(buff);   	
			    
			   nombre[i]=(char *)malloc((strlen(buff)+1)*sizeof(char));
			   strcpy(nombre[i],buff);
			}
			
			printf("\n\nListado de nombres\n");	
			printf("-------------------\n");
			
			for(int i=0;i<cantidad_nombres;i++)
	        {
		      printf("%d) ",i+1);
		      puts(nombre[i]);
		    }
			 
			for(int i=0;i<cantidad_nombres;i++)
	        { 
		       free(nombre[i]);
		    }
			
			free(buff); 
			 
  return 0;
} 
