
#include <iostream>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <string>

using namespace std;

// ==========================================
// CONSTANTES DEL SISTEMA
// ==========================================

const double LIMITE_VOLUMEN = 500.0;

// ==========================================
// VARIABLES Y CONTADORES
// ==========================================

int contadorA = 0;
int contadorB = 0;
int totalCajas = 0;

double sumaVolumen = 0.0;
double volumenMayor = 0.0;
double volumenMenor = 0.0;

// ==========================================
// FUNCION: INGRESAR Y VALIDAR DIMENSIONES
// ==========================================

double ingresarDimension(string nombre) {

    double valor;

    while (true) {

        cout << nombre << ": ";

        if (cin >> valor && isfinite(valor) && valor > 0) {
            return valor;
        }

        cout << "Error: ingrese un valor numerico "
             << "finito y mayor que cero." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ==========================================
// FUNCION: CALCULAR VOLUMEN
// ==========================================

double calcularVolumen(double ancho, double alto,
                       double profundidad) {

    return ancho * alto * profundidad;
}

// ==========================================
// FUNCION: CLASIFICAR CAJA
// ==========================================

char clasificarCaja(double volumen) {

    if (volumen > LIMITE_VOLUMEN) {

        cout << "\nDestino: BANDA A" << endl;
        return 'A';

    } else {

        cout << "\nDestino: BANDA B" << endl;
        return 'B';
    }
}

// ==========================================
// FUNCION: ACTUALIZAR ESTADISTICAS
// ==========================================

void actualizarContadores(double volumen, char banda) {

    totalCajas++;
    sumaVolumen += volumen;

    if (banda == 'A') {
        contadorA++;
    } else {
        contadorB++;
    }

    if (totalCajas == 1) {

        volumenMayor = volumen;
        volumenMenor = volumen;

    } else {

        if (volumen > volumenMayor) {
            volumenMayor = volumen;
        }

        if (volumen < volumenMenor) {
            volumenMenor = volumen;
        }
    }
}

// ==========================================
// FUNCION: MOSTRAR RESUMEN FINAL
// ==========================================

void mostrarResumen() {

    cout << "\n======================================" << endl;
    cout << "       RESUMEN DE CLASIFICACION       " << endl;
    cout << "======================================" << endl;

    cout << fixed << setprecision(2);

    cout << "\nTotal de cajas procesadas: "
         << totalCajas << endl;

    cout << "\n--- DISTRIBUCION POR BANDAS ---" << endl;

    cout << "Cajas enviadas a BANDA A: "
         << contadorA << endl;

    cout << "Cajas enviadas a BANDA B: "
         << contadorB << endl;

    cout << "\n--- PORCENTAJES ---" << endl;

    if (totalCajas > 0) {

        double porcentajeA =
            (contadorA * 100.0) / totalCajas;

        double porcentajeB =
            (contadorB * 100.0) / totalCajas;

        cout << "Porcentaje BANDA A: "
             << porcentajeA << "%" << endl;

        cout << "Porcentaje BANDA B: "
             << porcentajeB << "%" << endl;

        cout << "\n--- ESTADISTICAS DE VOLUMEN ---" << endl;

        cout << "Volumen promedio: "
             << sumaVolumen / totalCajas
             << " cm3" << endl;

        cout << "Volumen mayor: "
             << volumenMayor << " cm3" << endl;

        cout << "Volumen menor: "
             << volumenMenor << " cm3" << endl;

    } else {

        cout << "No se procesaron cajas." << endl;
    }

    cout << "\n======================================" << endl;
    cout << "          PROCESO FINALIZADO          " << endl;
    cout << "======================================" << endl;
}

// ==========================================
// FUNCION PRINCIPAL
// ==========================================

int main() {

    double ancho, alto, profundidad, volumen;
    char continuar = 'S';

    cout << "======================================" << endl;
    cout << "     SISTEMA DE CLASIFICACION         " << endl;
    cout << "              DE CAJAS                " << endl;
    cout << "======================================" << endl;

    do {

        cout << "\n--------------------------------------" << endl;
        cout << " INGRESO DE DIMENSIONES DE LA CAJA" << endl;
        cout << "--------------------------------------" << endl;

        // Ingreso de dimensiones

        ancho = ingresarDimension("Ancho (cm)");
        alto = ingresarDimension("Alto (cm)");
        profundidad = ingresarDimension("Profundidad (cm)");

        // Calcular volumen

        volumen = calcularVolumen(ancho, alto, profundidad);

        // Validar resultado del calculo

        if (!isfinite(volumen)) {

            cout << "\nError: el volumen calculado "
                 << "supera el rango permitido." << endl;

            cout << "La caja no sera contabilizada." << endl;

            // Se vuelve a solicitar otra caja.
            continuar = 'S';
            continue;
        }

        cout << "\n--------------------------------------" << endl;
        cout << " RESULTADO DEL ANALISIS" << endl;
        cout << "--------------------------------------" << endl;

        cout << fixed << setprecision(2);

        cout << "Volumen calculado: "
             << volumen << " cm3" << endl;

        // Clasificar caja

        char banda = clasificarCaja(volumen);

        // Actualizar estadisticas

        actualizarContadores(volumen, banda);

        cout << "Caja registrada correctamente." << endl;

        // Preguntar si desea continuar

        do {

            cout << "\nDesea clasificar otra caja? (S/N): ";
            cin >> continuar;

            continuar = toupper(
                static_cast<unsigned char>(continuar)
            );

            if (continuar != 'S' && continuar != 'N') {

                cout << "Respuesta no valida. "
                     << "Ingrese S o N." << endl;
            }

        } while (continuar != 'S' && continuar != 'N');

    } while (continuar == 'S');

    // Mostrar resultados finales

    mostrarResumen();

    return 0;
}
