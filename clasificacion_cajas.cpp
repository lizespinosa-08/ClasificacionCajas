
#include <iostream>
#include <limits>
using namespace std;

int main() {

    // Variables
    double ancho, alto, profundidad, volumen;
    int contadorA = 0;
    int contadorB = 0;
    char continuar;

    cout << "SISTEMA DE CLASIFICACION DE CAJAS" << endl;

    do {

        // Solicitar dimensiones
        cout << "\nIngrese las dimensiones de la caja en centimetros:" << endl;

        cout << "Ancho: ";
        cin >> ancho;

        while (cin.fail() || ancho <= 0) {
            cout << "Error: ingrese un ancho numerico mayor que cero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> ancho;
        }

        cout << "Alto: ";
        cin >> alto;

        while (cin.fail() || alto <= 0) {
            cout << "Error: ingrese un alto numerico mayor que cero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> alto;
        }

        cout << "Profundidad: ";
        cin >> profundidad;

        while (cin.fail() || profundidad <= 0) {
            cout << "Error: ingrese una profundidad numerica mayor que cero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> profundidad;
        }

        // Calcular volumen
        volumen = ancho * alto * profundidad;

        cout << "\nEl volumen de la caja es: "
             << volumen << " cm3" << endl;

        // Clasificar caja
        if (volumen > 500) {
            cout << "Destino: BANDA A" << endl;
            contadorA++;
        } else {
            cout << "Destino: BANDA B" << endl;
            contadorB++;
        }

        // Preguntar si desea continuar
        cout << "\nDesea clasificar otra caja? (S/N): ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    // Resumen final
    cout << "\n===== RESUMEN DE CLASIFICACION =====" << endl;
    cout << "Cajas enviadas a BANDA A: " << contadorA << endl;
    cout << "Cajas enviadas a BANDA B: " << contadorB << endl;
    cout << "Total de cajas: " << contadorA + contadorB << endl;

    cout << "\nProceso finalizado." << endl;

    return 0;
}

