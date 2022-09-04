#include <pic14/pic12f675.h>


// Declaracion funcion delay
void delay (unsigned int tiempo );

// Contador de numeros que han salido - Inicia en cero
int count;

// Definir main
int main()
{
    // Configuracion Inicial de Pines
    TRISIO = 0b00000001; // Poner GP0 como entrada y los demas como salidas
	//GP1 = 0;    // No se han sacado 16 numeros
    ANSEL = 0;  // No se usan entradas analogicas, todo es I/O digital
    CMCON = 7;  // Comparador apagado

    count = 0;
    int past_GP4;

    // Declarar entrada
    int button_pressed = 0;

    // Programa se repite indefinidamente
    while (1)
    {   
        if (count < 16)
        {
            // Se entra en el if si se presiona el boton
            if (GP0 == 0)
            {
                button_pressed = 1;
            }

            if (GP0 == 1 && button_pressed == 1)
            {
                
                count++;
                // Boton se termino de presionar
                
                button_pressed = 0;
                delay(20);
                GP4 = !GP4;
                delay(20);
            }
        }
        else
        {
            // Se entra en el else cuando se ha presionado 16 veces el boton/ han salido 16 numeros
            // Se pone GP1 en uno para imprimir 99
            GP1 = 1;

            // delay
            delay(100);

            // Se reinicia el contador y se regresa GP1 a cero
            count = 0;
            GP1 = 0;
        }
    }
}

void delay (unsigned int tiempo )
{
    unsigned int i ;
    unsigned int j ;
    for( i =0; i <tiempo ; i ++)
        for( j =0; j <1275; j ++);
}