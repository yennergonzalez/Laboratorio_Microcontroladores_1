#include <pic14/pic12f675.h>

typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDT_OFF & _MCLRE_OFF);

// Declaracion funcion delay
void delay (unsigned int tiempo );

// Definir main
int main()
{
    // Configuracion Inicial de Registros y Pines
    TRISIO = 0b00000001;    // Poner GP0 como entrada y los demas como salidas
	GP4 = 0;                // GP4 indica cuando se han sacado 16 numeros y por ende inicia en cero
    ANSEL = 0;              // No se usan entradas analogicas, todo es I/O digital
    CMCON = 7;              // Comparador apagado

    // Contador de numeros que han salido - Inicia en cero
    unsigned int count = 0;

    // Variable para detectar si se esta presionando el boton/si ya termino de presionarse
    int button_pressed = 0;

    // Programa se repite indefinidamente
    while (1)
    {   
        if (count < 16)
        {   
            // Se entra en el if si se presiona el boton
            if (GP0 == 0 && button_pressed == 0)
            {
                button_pressed = 1;
                continue;
            }
            else if (GP0 == 1 && button_pressed == 1)
            {
                // Se aumenta el contador cuando el boton se dejo de presionar
                count = count + 1;
                button_pressed = 0;
            }
        }
        else //
        //if (count >= 16)   // Se entra en el else if cuando se ha presionado 16 veces el boton/ han salido 16 numeros
        {
            // Se pone GP4 en uno para imprimir 99
            GP4 = ~GP4;

            // delay
            delay(200);

            // Se reinicia el contador y se regresa GP4 a cero
            count = 0;
            GP4 = ~GP4;
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