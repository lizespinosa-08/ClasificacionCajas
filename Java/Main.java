package Java;

import java.util.Scanner;

public class Main {

    static Scanner entrada = new Scanner(System.in);
    public static double leerDimension(String mensaje) {

        double valor = 0;
        boolean valido = false;

        while (!valido) {

            System.out.print(mensaje);

            try {

                valor = Double.parseDouble(entrada.nextLine());

                if (valor > 0) {
                    valido = true;
                } else {
                    System.out.println(
                        "Error: ingrese un valor mayor que cero."
                    );
                }

            } catch (NumberFormatException e) {

                System.out.println(
                    "Error: debe ingresar un dato numerico."
                );
            }
        }

        return valor;
    }

    // Metodo para validar la cantidad de cajas
    public static int leerCantidad() {

        int cantidad = 0;

        while (cantidad < 1 || cantidad > 100) {

            System.out.print(
                "\n¿Cuantas cajas desea registrar? (1-100): "
            );

            try {

                cantidad = Integer.parseInt(entrada.nextLine());

                if (cantidad < 1 || cantidad > 100) {
                    System.out.println(
                        "Error: ingrese una cantidad entre 1 y 100."
                    );
                }

            } catch (NumberFormatException e) {

                cantidad = 0;

                System.out.println(
                    "Error: ingrese un numero entero."
                );
            }
        }

        return cantidad;
    }

    // Metodo principal
    public static void main(String[] args) {

        Caja[] cajas = new Caja[100];

        int contadorA = 0;
        int contadorB = 0;

        System.out.println(
            "======================================"
        );
        System.out.println(
            "   SISTEMA DE CLASIFICACION DE CAJAS"
        );
        System.out.println(
            "======================================"
        );

        int cantidad = leerCantidad();

        for (int i = 0; i < cantidad; i++) {

            System.out.println(
                "\n===== REGISTRO DE LA CAJA " + (i + 1) + " ====="
            );

            double ancho = leerDimension("Ancho (cm): ");

            double alto = leerDimension("Alto (cm): ");

            double profundidad = leerDimension(
                "Profundidad (cm): "
            );

            String codigo = String.format("C%03d", i + 1);

            cajas[i] = new Caja(
                codigo,
                ancho,
                alto,
                profundidad
            );

            cajas[i].calcularVolumen();

            cajas[i].clasificar();
        }

        // Mostrar resultados de todas las cajas
        System.out.println(
            "\n======================================"
        );
        System.out.println(
            "         RESULTADOS DEL PROCESO"
        );
        System.out.println(
            "======================================"
        );

        for (int i = 0; i < cantidad; i++) {

            cajas[i].mostrarInformacion();

            if (cajas[i].getBanda().equals("BANDA A")) {

                contadorA++;

            } else {

                contadorB++;
            }
        }

        System.out.println(
            "\n======================================"
        );
        System.out.println(
            "       RESUMEN DE CLASIFICACION"
        );
        System.out.println(
            "======================================"
        );

        System.out.println(
            "Cajas enviadas a BANDA A: " + contadorA
        );

        System.out.println(
            "Cajas enviadas a BANDA B: " + contadorB
        );

        System.out.println(
            "Total de cajas: " + cantidad
        );

        System.out.println(
            "\nProceso finalizado correctamente."
        );

        entrada.close();
    }
}
