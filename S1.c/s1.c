#include <stdio.h>

int main () {
    char ID[10], nombre[20];
    int stock = 0;
    float precio;
    float totalVenta, ganancias=0;
    int numVenta, numStock;
    int opc = 0, opc1 = 0;

    do {
        printf("Seleccionar una alternativa:\n");
        printf("1. Ingresar articulo\n");
        printf("2. Efectuar venta\n");
        printf("3. Aumentar stock\n");
        printf("4. Detalles del articulo\n");
        printf("5. Ver ingresos\n"); 
        printf("6. Cerrar sistema\n");
        printf("Opcion elegida: ");
        scanf("%d",&opc);

        switch (opc) {
            case 1:
                printf("Ingresar el ID del producto: ");
                scanf("%s",&ID);
                printf("Ingresar el nombre del producto: ");
                scanf("%s",&nombre);
                do{
                    printf("Ingresar la cantidad inicial (debe ser mayor a 0): ");
                    scanf("%d",&stock);
                    if(stock<=0){
                        printf("Atencion: la cantidad digitada es incorrecta\n");
                    }
                } while(stock<=0);
                printf("Ingresar el precio unitario: ");
                scanf("%f",&precio);
                printf("Registro completado con exito\n");
                break;
            case 2:
                printf("Ingresar la cantidad de unidades a vender: ");
                scanf("%d",&numVenta);
                if(numVenta>stock){
                    printf("Operacion fallida: el inventario es insuficiente\n");
                    break;
                }
                stock-=numVenta;
                totalVenta = numVenta * precio;
                ganancias+=totalVenta;
                printf("Monto total de la venta: %.2f\n",totalVenta);
                break;
            case 3:
                printf("Ingresar cuantas unidades va a reabastecer: ");
                scanf("%d",&numStock);
                stock+=numStock;
                printf("Cantidad actualizada en stock: %d\n",stock);
                break;
            case 4:
                printf("Codigo\t\tArticulo\tStock\t\tValor\t\tTotal\n");
                float totalProducto = stock * precio;
                printf("%s\t\t%s\t\t%d\t\t%.2f\t\t%.2f\n",ID,nombre,stock,precio,totalProducto);
                break;
            case 5:
                printf("El total de ganancias acumuladas es: %.2f\n",ganancias);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Alternativa invalida\n");
                break;
        }
        
        printf("¿Continuar en el programa? (1.Si / 2.No): ");
        scanf("%d",&opc1);
        
    } while(opc1==1);

    return 0;
}