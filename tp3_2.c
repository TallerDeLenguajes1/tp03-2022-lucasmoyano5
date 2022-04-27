#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	 
            char *buff;
            char *nombre[5];
             	         
            buff=(char *)malloc(100*sizeof(char));
    
		    printf("Ingrese 5 nombres\n");
		    printf("-----------------\n");
			
		    for(int i=0;i<5;i++)
	        {
			   printf("Ingrese el nombre %d: ",i+1);	
			   gets(buff);   	
			   
			   nombre[i]=(char *)malloc((strlen(buff)+1)*sizeof(char));
			   strcpy(nombre[i],buff);
			}
            
            printf("\n\nListado de nombres\n");	
			printf("-------------------\n");
			
			for(int i=0;i<5;i++)
	        {
		      printf("%d) ",i+1);
		      puts(nombre[i]);
		    }
			 
			for(int i=0;i<5;i++)
	        { 
		       free(nombre[i]);
		    }
			 
            free(buff); 
			 
  return 0;
} 
