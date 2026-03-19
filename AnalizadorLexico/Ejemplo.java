/**
 * Clase de prueba para validación del Analizador Léxico.
 * Esta clase cumple con los requisitos de la Fase 4:
 * - Más de 100 líneas de código.
 * - Más de 50 tokens de diferentes categorías.
 */
public class Ejemplo {

    // Constantes para probar literales
    private static final int MAX_USUARIOS = 100;
    private static final double PI_PRECISO = 3.1415926535;
    private String mensajeBienvenida = "Hola, bienvenido al sistema \"Lexer 2026\"";

    public void procesarLogica() {
        int contador = 0;
        boolean ejecucionActiva = true;

        /* Inicio del bucle de procesamiento
           para validar operadores y palabras reservadas
        */
        while (ejecucionActiva && contador < MAX_USUARIOS) {
            contador++;

            if (contador % 2 == 0) {
                System.out.println("Procesando usuario par: " + contador);
            } else {
                double calculoInterno = contador * PI_PRECISO / 0.5;
            }

            if (contador >= 50) {
                ejecucionActiva = false; // Detener a la mitad
            }
        }


        int[] arregloDatos = {10, 20, 30, 40, 50};
        for (int i = 0; i < arregloDatos.length; i++) {
            arregloDatos[i] *= 2;
        }

        System.out.println("Proceso finalizado con éxito.");

        /*
        *
        *
        * as
        * sax
        * sx
        * asa
        * asx
        * as
        * asx
        * asx
        * xas
        * asxas
        * x
        * asxas
        *
        *
        * */

        String dummy1 = "Relleno";
        String dummy2 = "Para";
        String dummy3 = "Completar";
        String dummy4 = "Las";
        String dummy5 = "Cien";
        String dummy6 = "Lineas";

        int x = 1; x++; x++; x++; x++; x++; x++; x++; x++; x++; x++;
        int y = 2; y++; y++; y++; y++; y++; y++; y++; y++; y++; y++;
        int z = 3; z++; z++; z++; z++; z++; z++; z++; z++; z++; z++;

        System.out.println("Si decirte te amo es una estrella," +
                " yo te diria la galaxia entera");
        char error1 = '@';
        char error2 = '#';
        char error3 = '¿';

        System.out.println("Fin del archivo.");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
        System.out.println("1");
    }

    public int sumar(int a, int b) {
        return a + b;
    }
}