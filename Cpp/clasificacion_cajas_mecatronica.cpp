
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

// CLASE SENSOR
class Sensor {

private:
    string codigo;
    string tipoMedicion;
    string unidad;

public:

    // Constructor
    Sensor(string cod, string tipo, string uni) {
        codigo = cod;
        tipoMedicion = tipo;
        unidad = uni;
    }

    // Consultar tipo de medicion
    string getTipoMedicion() const {
        return tipoMedicion;
    }

    // Mostrar informacion del sensor
    void mostrarInformacion() const {
        cout << codigo << " - Sensor de "
             << tipoMedicion << " (" << unidad << ")" << endl;
    }
};

//VALIDAR LAS LECTURAS


double leerDimension(const Sensor& sensor, int numeroCaja) {

    double valor;

    while (true) {

        cout << sensor.getTipoMedicion()
             << " de la caja " << numeroCaja << ": ";

        cin >> valor;

        if (cin.fail() || valor <= 0) {

            cout << "Error: ingrese un valor numerico "
                 << "mayor que cero." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } else {
            return valor;
        }
    }
}

//  REGISTRAR LAS LECTURAS
void registrarLecturas(
    double anchos[],
    double altos[],
    double profundidades[],
    int cantidad,
    const Sensor& sensorAncho,
    const Sensor& sensorAlto,
    const Sensor& sensorProfundidad
) {

    for (int i = 0; i < cantidad; i++) {

        cout << "\n===== REGISTRO DE CAJA "
             << i + 1 << " =====" << endl;

        anchos[i] = leerDimension(sensorAncho, i + 1);

        altos[i] = leerDimension(sensorAlto, i + 1);

        profundidades[i] =
            leerDimension(sensorProfundidad, i + 1);
    }
}

//  CALCULAR LOS VOLUMENES

void calcularVolumenes(
    double anchos[],
    double altos[],
    double profundidades[],
    double volumenes[],
    int cantidad
) {

    for (int i = 0; i < cantidad; i++) {

        volumenes[i] =
            anchos[i] * altos[i] * profundidades[i];
    }
}

// FUNCION PARA CLASIFICAR LAS CAJAS

void clasificarCajas(
    double volumenes[],
    char bandas[],
    int cantidad
) {

    for (int i = 0; i < cantidad; i++) {

        if (volumenes[i] > 500) {
            bandas[i] = 'A';
        } else {
            bandas[i] = 'B';
        }
    }
}

// MOSTRAR LOS RESULTADOS

void mostrarResultados(
    double anchos[],
    double altos[],
    double profundidades[],
    double volumenes[],
    char bandas[],
    int cantidad
) {

    cout << "\n========== RESULTADOS ==========" << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < cantidad; i++) {

        cout << "\nCaja " << i + 1 << endl;

        cout << "Ancho: " << anchos[i] << " cm" << endl;
        cout << "Alto: " << altos[i] << " cm" << endl;

        cout << "Profundidad: "
             << profundidades[i] << " cm" << endl;

        cout << "Volumen: "
             << volumenes[i] << " cm3" << endl;

        cout << "Destino: BANDA "
             << bandas[i] << endl;
    }
}

// ==========================================
// FUNCION PARA MOSTRAR LAS ESTADISTICAS
// ==========================================

void mostrarEstadisticas(
    double volumenes[],
    char bandas[],
    int cantidad
) {

    int contadorA = 0;
    int contadorB = 0;

    double sumaVolumenes = 0;

    for (int i = 0; i < cantidad; i++) {

        sumaVolumenes += volumenes[i];

        if (bandas[i] == 'A') {
            contadorA++;
        } else {
            contadorB++;
        }
    }

    double promedio = sumaVolumenes / cantidad;

    cout << "\n===== RESUMEN DE CLASIFICACION =====" << endl;

    cout << "Cajas enviadas a BANDA A: "
         << contadorA << endl;

    cout << "Cajas enviadas a BANDA B: "
         << contadorB << endl;

    cout << "Total de cajas: " << cantidad << endl;

    cout << fixed << setprecision(2);

    cout << "Volumen promedio: "
         << promedio << " cm3" << endl;
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

int main() {

    const int MAX_CAJAS = 100;

    // Arreglos unidimensionales
    double anchos[MAX_CAJAS];
    double altos[MAX_CAJAS];
    double profundidades[MAX_CAJAS];
    double volumenes[MAX_CAJAS];

    char bandas[MAX_CAJAS];

    int cantidad;

    // Creacion de los tres objetos Sensor
    Sensor sensorAncho("S001", "Ancho", "cm");

    Sensor sensorAlto("S002", "Alto", "cm");

    Sensor sensorProfundidad(
        "S003", "Profundidad", "cm"
    );

    cout << "======================================" << endl;
    cout << " SISTEMA DE CLASIFICACION DE CAJAS" << endl;
    cout << "======================================" << endl;

    // Informacion de los sensores
    cout << "\nSENSORES DEL SISTEMA:" << endl;

    sensorAncho.mostrarInformacion();
    sensorAlto.mostrarInformacion();
    sensorProfundidad.mostrarInformacion();

    // Validacion de la cantidad de cajas
    do {

        cout << "\nIngrese la cantidad de cajas (1-100): ";
        cin >> cantidad;

        if (cin.fail() || cantidad < 1 ||
            cantidad > MAX_CAJAS) {

            cout << "Error: ingrese un numero entre 1 y 100."
                 << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cantidad = 0;
        }

    } while (cantidad < 1 || cantidad > MAX_CAJAS);

    // Registro de lecturas simuladas
    registrarLecturas(
        anchos,
        altos,
        profundidades,
        cantidad,
        sensorAncho,
        sensorAlto,
        sensorProfundidad
    );

    // Procesamiento de las lecturas
    calcularVolumenes(
        anchos,
        altos,
        profundidades,
        volumenes,
        cantidad
    );

    // Clasificacion de las cajas
    clasificarCajas(volumenes, bandas, cantidad);

    // Presentacion de resultados
    mostrarResultados(
        anchos,
        altos,
        profundidades,
        volumenes,
        bandas,
        cantidad
    );

    // Presentacion de estadisticas
    mostrarEstadisticas(
        volumenes,
        bandas,
        cantidad
    );

    cout << "\nProceso finalizado correctamente." << endl;

    return 0;
}
