#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Constantes
const int PRECIO_SENCILLO_SOLO_LAVADO = 3000;
const int PRECIO_SENCILLO_COMPLETO = 5000;
const int PRECIO_4X4_SOLO_LAVADO = 5000;
const int PRECIO_4X4_COMPLETO = 7000;
const int PRECIO_PESADO_SOLO_LAVADO = 7000;
const int PRECIO_PESADO_COMPLETO = 12000;

// Variables Globales
int numFactura = 1;
int cantidadVehiculosSencillos = 0;
int dineroRecaudadoVehiculosSencillos = 0;
int cantidadVehiculos4x4 = 0;
int dineroRecaudadoVehiculos4x4 = 0;
int cantidadVehiculosPesados = 0;
int dineroRecaudadoVehiculosPesados = 0;
int cantidadSoloLavado = 0;
int dineroRecaudadoSoloLavado = 0;
int cantidadCompletoLavado = 0;
int dineroRecaudadoCompletoLavado = 0;

// Funciones
int calcularPrecio(int tipoVehiculo, int tipoLavado) {
    int precio = 0;
    if (tipoVehiculo == 1) { 
        if (tipoLavado == 1) {
            precio = PRECIO_SENCILLO_SOLO_LAVADO;
        } else {
            precio = PRECIO_SENCILLO_COMPLETO;
        }
    } else if (tipoVehiculo == 2) { 
        if (tipoLavado == 1) {
            precio = PRECIO_4X4_SOLO_LAVADO;
        } else {
            precio = PRECIO_4X4_COMPLETO;
        }
    } else { // Microbus o Camion
        if (tipoLavado == 1) {
            precio = PRECIO_PESADO_SOLO_LAVADO;
        } else {
            precio = PRECIO_PESADO_COMPLETO;
        }
    }
    return precio;
}

void ingresarDatosVehiculos() {
    char continuar;
    do {
        string placa, marca, modelo;
        int tipoVehiculo, tipoLavado, precio;

        cout << "Ingrese los datos del vehiculo:" << endl;
        cout << "Numero de placa: ";
        cin >> placa;
        cout << "Marca: ";
        cin >> marca;
        cout << "Modelo: ";
        cin >> modelo;
        cout << "Tipo de vehiculo (1=Sencillo, 2=4x4, 3=Microbus o Camion): ";
        cin >> tipoVehiculo;
        cout << "Tipo de lavado (1=Solo Lavado, 2=Lavado, Aspirado y Encerado): ";
        cin >> tipoLavado;

        precio = calcularPrecio(tipoVehiculo, tipoLavado);

        cout << fixed << setprecision(2);
        cout << "\nFactura #" << numFactura << endl;
        cout << "Numero de placa: " << placa << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Tipo de vehiculo: ";
        if (tipoVehiculo == 1) {
            cout << "Sencillo" << endl;
            cantidadVehiculosSencillos++;
            dineroRecaudadoVehiculosSencillos += precio;
        } else if (tipoVehiculo == 2) {
            cout << "4x4" << endl;
            cantidadVehiculos4x4++;
            dineroRecaudadoVehiculos4x4 += precio;
        } else {
            cout << "Microbus o Camion" << endl;
            cantidadVehiculosPesados++;
            dineroRecaudadoVehiculosPesados += precio;
        }
        cout << "Tipo de lavado: ";
        if (tipoLavado == 1) {
            cout << "Solo Lavado" << endl;
            cantidadSoloLavado++;
            dineroRecaudadoSoloLavado += precio;
        } else {
            cout << "Lavado, Aspirado y Encerado" << endl;
            cantidadCompletoLavado++;
            dineroRecaudadoCompletoLavado += precio;
        }
        cout << "Precio a pagar: " << precio << " colones" << endl;

        numFactura++;

        cout << "\nDesea continuar ingresando datos (S/N)? ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');
}

void mostrarEstadisticasTipoVehiculo() {
    cout << "\nEstadisticas de Vehiculos Lavados por Tipo de Vehiculo:" << endl;
    cout << "Cantidad de Vehiculos Tipo Sencillos: " << cantidadVehiculosSencillos << endl;
    cout << "Dinero Recaudado por Vehiculos Tipo Sencillos: " << dineroRecaudadoVehiculosSencillos << " colones" << endl;
    cout << "Cantidad de Vehiculos Tipo 4x4: " << cantidadVehiculos4x4 << endl;
    cout << "Dinero Recaudado por Vehiculos Tipo 4x4: " << dineroRecaudadoVehiculos4x4 << " colones" << endl;
    cout << "Cantidad de Vehiculos Tipo Microbus o Camion: " << cantidadVehiculosPesados << endl;
    cout << "Dinero Recaudado por Vehiculos Tipo Microbus o Camion: " << dineroRecaudadoVehiculosPesados << " colones" << endl;
    cout << "\nPresione cualquier tecla para continuar...";
    cin.get();
    cin.get();
}

void mostrarEstadisticasTipoLavado() {
    cout << "\nEstadisticas de Vehiculos Lavados por Tipo de Lavado:" << endl;
    cout << "Cantidad de Vehiculos con Solo Lavado: " << cantidadSoloLavado << endl;
    cout << "Dinero Recaudado por Vehiculos con Solo Lavado: " << dineroRecaudadoSoloLavado << " colones" << endl;
    cout << "Promedio Dinero Recaudado por Vehiculos con Solo Lavado: " << (cantidadSoloLavado > 0 ? static_cast<double>(dineroRecaudadoSoloLavado) / cantidadSoloLavado : 0.0) << " colones" << endl;
    cout << "Cantidad de Vehiculos con Lavado, Aspirado y Encerado: " << cantidadCompletoLavado << endl;
    cout << "Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << dineroRecaudadoCompletoLavado << " colones" << endl;
    cout << "Promedio Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << (cantidadCompletoLavado > 0 ? static_cast<double>(dineroRecaudadoCompletoLavado) / cantidadCompletoLavado : 0.0) << " colones" << endl;
    cout << "\nPresione cualquier tecla para continuar...";
    cin.get();
    cin.get();
}

void graficarTipoVehiculo() {
    cout << "\nGrafico de Vehiculos Lavados por Tipo de Vehiculo:" << endl;
    cout << "Veh. Sencillos\t";
    for (int i = 0; i < cantidadVehiculosSencillos; i++) {
        cout << "¦";
    }
    cout << endl;
    cout << "Veh. 4x4\t\t";
    for (int i = 0; i < cantidadVehiculos4x4; i++) {
        cout << "¦";
    }
    cout << endl;
    cout << "Veh. Pesados\t";
    for (int i = 0; i < cantidadVehiculosPesados; i++) {
        cout << "¦";
    }
    cout << endl << endl;
    cout << "Pulse tecla para Abandonar";
    cin.get();
    cin.get();
}

void graficarTipoLavado() {
    cout << "\nGrafico de Vehiculos Lavados por Tipo de Lavado:" << endl;
    cout << "Sencillo\t\t";
    for (int i = 0; i < cantidadSoloLavado; i++) {
        cout << "¦";
    }
    cout << endl;
    cout << "Completo\t\t";
    for (int i = 0; i < cantidadCompletoLavado; i++) {
        cout << "¦";
    }
    cout << endl << endl;
    cout << "Pulse tecla para Abandonar";
    cin.get();
    cin.get();
}

int main() {
    int opcion;
    do {
        cout << "\nMenu Principal" << endl;
        cout << "1- Ingresar Datos Vehiculos" << endl;
        cout << "2- Ver Estadisticas Vehiculos Lavados según tipo de Vehiculo" << endl;
        cout << "3- Ver Estadisticas Vehiculos Lavados según tipo de Lavado" << endl;
        cout << "4- Ver Grafico Vehiculos Lavados por Tipo de Vehiculo" << endl;
        cout << "5- Ver Grafico Vehiculos Lavados por Tipo de Lavado" << endl;
        cout << "6- Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarDatosVehiculos();
                break;
            case 2:
                mostrarEstadisticasTipoVehiculo();
                break;
            case 3:
                mostrarEstadisticasTipoLavado();
                break;
            case 4:
                graficarTipoVehiculo();
                break;
            case 5:
                graficarTipoLavado();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
