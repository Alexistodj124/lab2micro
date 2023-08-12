#include <stdio.h>

void decimalABinario(int num) {
    if (num == 0) {
        printf("El numero en binario es: 0\n");
        return;
    }

    int binario[32];
    int indice = 0;

    while (num > 0) {
        binario[indice++] = num % 2;
        num /= 2;
    }

    printf("El numero en binario es: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", binario[i]);
    }
    printf("\n");
}

void calcularIVA() {
    float monto, iva;
    printf("Ingrese el monto de la factura: ");
    scanf("%f", &monto);

    iva = (monto / 1.12) * 0.12;
    printf("El IVA es: %.2f\n", iva);
}

void reglaDeTres() {
    float a, b, x;
    printf("Ingrese el primer valor (a): ");
    scanf("%f", &a);
    printf("Ingrese el segundo valor (b): ");
    scanf("%f", &b);
    printf("Ingrese el tercer valor (x): ");
    scanf("%f", &x);

    float resultado = (x * b) / a;
    printf("El resultado de la regla de tres es: %.2f\n", resultado);
}

int main() {
    int opcion;
    int numero; 
    do {
        printf("Seleccione una opción:\n");
        printf("1. Transformar decimal a binario\n");
        printf("2. Calcular el IVA de una factura\n");
        printf("3. Realizar una regla de tres\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un numero decimal: ");
                scanf("%d", &numero); 
                decimalABinario(numero);
                break;
            case 2:
                calcularIVA();
                break;
            case 3:
                reglaDeTres();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción invalida. Intente nuevamente.\n");
        }

    } while (opcion != 4);

    return 0;
}
