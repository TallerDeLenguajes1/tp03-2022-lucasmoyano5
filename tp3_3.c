#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h> 
 
 
struct{
       int productoID;
       int cantidad;
       char *tipo_producto;
       float precio_unitario;

}typedef producto;


struct{
       int clienteID; 
       char *nombre_cliente;
       int cantidad_productos_pedir;
       producto *productos;
        
}typedef cliente;

char *tipos_productos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};  	 

void cargarClientes(cliente *CLIENTES,int cantidad_clientes);

void mostrarClientes(cliente *CLIENTES,int cantidad_clientes);

float costoTotalDelProducto(int cant,float precio);     

int main(){
            
            int cantidad_clientes=0; 
            
            cliente *CLIENTES;
              
            printf("Ingrese la cantidad de clientes: ");
            scanf("%d",&cantidad_clientes);
            fflush(stdin);
			    
            CLIENTES = (cliente*)malloc(sizeof(cliente)*cantidad_clientes);
            
            cargarClientes(CLIENTES,cantidad_clientes);
            mostrarClientes(CLIENTES,cantidad_clientes);
            
            free(CLIENTES->nombre_cliente);
            free(CLIENTES->productos);
            free(CLIENTES);
 
 
           printf("\n\n\n\n");
	return 0;
}	
	
void cargarClientes(cliente *CLIENTES,int cantidad_clientes){
            
            char *buff; 
            int id_cliente=1;
            int id_producto=1;
              
            buff=(char *)malloc(100*sizeof(char));  
            
            srand(getpid()); 
            
            printf("\nCargar datos del cliente\n");
			printf("------------------------\n");
            for(int i=0;i<cantidad_clientes;i++)
            {
			   printf("\nCliente: %d\n",id_cliente);
			   
			   printf("Nombre del cliente: ");
			   gets(buff);
			   fflush(stdin);

			   CLIENTES[i].clienteID=id_cliente;
			   
			   CLIENTES[i].nombre_cliente = (char*)malloc(sizeof(char)*strlen(buff+1));
               strcpy(CLIENTES[i].nombre_cliente, buff);
  
               CLIENTES[i].cantidad_productos_pedir = 1 + rand()%4;  
               
                
               CLIENTES[i].productos = (producto*)malloc(sizeof(producto)*CLIENTES[i].cantidad_productos_pedir);
               
               for(int j=0;j<CLIENTES[i].cantidad_productos_pedir;j++)
               {
			       CLIENTES[i].productos[j].productoID = id_producto;
			       CLIENTES[i].productos[j].cantidad = 1 + rand()%9;
			       CLIENTES[i].productos[j].tipo_producto = tipos_productos[rand()%5];
			       CLIENTES[i].productos[j].precio_unitario = 10 + (float)(rand()%90)/100;

			       id_producto++;
			   } 
               
               id_cliente++;    
            }
            
}


void mostrarClientes(cliente *CLIENTES,int cantidad_clientes){

            int num=1;
            float costo;
            float costo_total;
            
            printf("\n\n\nMostrar datos del cliente\n");
			printf("-------------------------\n");
            for(int i=0;i<cantidad_clientes;i++)
            {
			    printf("\nCliente: %d\n",num++);
			    
			    printf("ID: %d",CLIENTES[i].clienteID);
			    printf("\nNombre: %s",CLIENTES[i].nombre_cliente);
			    printf("\nCantidad de productos: %d\n\n",CLIENTES[i].cantidad_productos_pedir);
			   
			    costo_total=0;
			    
			    for(int j=0;j<CLIENTES[i].cantidad_productos_pedir;j++)
                {
					     
			            printf("    Producto ID: %d\n",CLIENTES[i].productos[j].productoID);
			            printf("    Cantidad: %d\n",CLIENTES[i].productos[j].cantidad);
			            printf("    Producto: %s\n",CLIENTES[i].productos[j].tipo_producto);
			            printf("    Precio unitario: %.2f\n",CLIENTES[i].productos[j].precio_unitario);
			           
			            costo = costoTotalDelProducto(CLIENTES[i].productos[j].cantidad,CLIENTES[i].productos[j].precio_unitario);     
			            printf("    Costo total del producto: %.2f\n\n",costo);
			            
			            costo_total = costo_total + costo;
			    } 
			    printf("    Costo total a pagar: %.2f\n\n\n",costo_total);
			    
			}
}

float costoTotalDelProducto(int cant,float precio){

     float costo_total;
     return costo_total= cant*precio;
}     
