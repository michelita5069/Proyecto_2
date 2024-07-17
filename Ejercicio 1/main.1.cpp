#include <iostream>
#include <string>
#include <iomanip>


const int ANIO_ACTUAL = 2024;
const double PORCENTAJE_CRITERIO_COLEGIO = 0.4;
const double PORCENTAJE_EXAMEN_ADMISION = 0.6;
const double NOTA_MINIMA_ADMITIDO = 85.0;
const double NOTA_MINIMA_EN_ESPERA = 75.0;

int cantidadEstudiantesAdmitidos = 0;
double promedioEstudiantesAdmitidos = 0.0;
int cantidadEstudiantesEnEspera = 0;
double promedioEstudiantesEnEspera = 0.0;
int cantidadEstudiantesNoAdmitidos = 0;
double promedioEstudiantesNoAdmitidos = 0.0;

int calcularEdad(int anioNacimiento) {
    return ANIO_ACTUAL - anioNacimiento;
}

double calcularPromedioColegio(double matematicas, double espanol, double ciencias, double estudiosociales) {
    return (matematicas + espanol + ciencias + estudiosociales) / 4.0;
}

double calcularPorcentajeCriterioColegio(double promedioColegio) {
    return promedioColegio * PORCENTAJE_CRITERIO_COLEGIO;
}

double calcularPorcentajeExamenAdmision(double notaExamenAdmision) {
    return notaExamenAdmision * PORCENTAJE_EXAMEN_ADMISION;
}

double calcularPromedioAdmision(double porcentajeCriterioColegio, double porcentajeExamenAdmision) {
    return porcentajeCriterioColegio + porcentajeExamenAdmision;
}

std::string determinarCalificacion(double promedioAdmision) {
    if (promedioAdmision >= NOTA_MINIMA_ADMITIDO) {
        return "Admitido";
    } else if (promedioAdmision >= NOTA_MINIMA_EN_ESPERA) {
        return "En Espera";
    } else {
        return "No Admitido";
    }
}

void ingresarDatos() {
    char continuar;
    do {
        std::string cedula, nombre;
        int anioNacimiento;
        double matematicas, espanol, ciencias, estudiosociales, notaExamenAdmision;

        std::cout << "Ingrese los datos del estudiante:" << std::endl;
        std::cout << "Cedula: ";
        std::cin >> cedula;
        std::cout << "Nombre: ";
        std::cin >> nombre;
        std::cout << "Anio de Nacimiento: ";
        std::cin >> anioNacimiento;
        std::cout << "Promedio de Matematicas: ";
        std::cin >> matematicas;
        std::cout << "Promedio de Espanol: ";
        std::cin >> espanol;
        std::cout << "Promedio de Ciencias: ";
        std::cin >> ciencias;
        std::cout << "Promedio de Estudios Sociales: ";
        std::cin >> estudiosociales;
        std::cout << "Nota del Examen de Admision: ";
        std::cin >> notaExamenAdmision;

        int edad = calcularEdad(anioNacimiento);
        double promedioColegio = calcularPromedioColegio(matematicas, espanol, ciencias, estudiosociales);
        double porcentajeCriterioColegio = calcularPorcentajeCriterioColegio(promedioColegio);
        double porcentajeExamenAdmision = calcularPorcentajeExamenAdmision(notaExamenAdmision);
        double promedioAdmision = calcularPromedioAdmision(porcentajeCriterioColegio, porcentajeExamenAdmision);
        std::string calificacion = determinarCalificacion(promedioAdmision);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nResultados del estudiante:" << std::endl;
        std::cout << "Cedula: " << cedula << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Anio de Nacimiento: " << anioNacimiento << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Promedio de Matematicas: " << matematicas << std::endl;
        std::cout << "Promedio de Español: " << espanol << std::endl;
        std::cout << "Promedio de Ciencias: " << ciencias << std::endl;
        std::cout << "Promedio de Estudios Sociales: " << estudiosociales << std::endl;
        std::cout << "Promedio de Colegio: " << promedioColegio << std::endl;
        std::cout << "Porcentaje Criterio Colegio: " << porcentajeCriterioColegio << "%" << std::endl;
        std::cout << "Porcentaje Examen Admision: " << porcentajeExamenAdmision << "%" << std::endl;
        std::cout << "Promedio Admision: " << promedioAdmision << std::endl;
        std::cout << "Calificacion: " << calificacion << std::endl;

        if (calificacion == "Admitido") {
            cantidadEstudiantesAdmitidos++;
            promedioEstudiantesAdmitidos += promedioAdmision;
        } else if (calificacion == "En Espera") {
            cantidadEstudiantesEnEspera++;
            promedioEstudiantesEnEspera += promedioAdmision;
        } else {
            cantidadEstudiantesNoAdmitidos++;
            promedioEstudiantesNoAdmitidos += promedioAdmision;
        }

        std::cout << "\nDesea continuar ingresando datos (S/N)? ";
        std::cin >> continuar;
    } while (continuar == 'S' || continuar == 's');
}

void calcularEstadisticas() {
    std::cout << "\nEstadisticas:" << std::endl;
    std::cout << "Cantidad de Estudiantes Admitidos: " << cantidadEstudiantesAdmitidos << std::endl;
    if (cantidadEstudiantesAdmitidos > 0) {
        std::cout << "Promedio de Estudiantes Admitidos: " << promedioEstudiantesAdmitidos / cantidadEstudiantesAdmitidos << std::endl;
    }
    std::cout << "Cantidad de Estudiantes en Espera: " << cantidadEstudiantesEnEspera << std::endl;
    if (cantidadEstudiantesEnEspera > 0) {
        std::cout << "Promedio de Estudiantes en Espera: " << promedioEstudiantesEnEspera / cantidadEstudiantesEnEspera << std::endl;
    }
    std::cout << "Cantidad de Estudiantes No Admitidos: " << cantidadEstudiantesNoAdmitidos << std::endl;
    if (cantidadEstudiantesNoAdmitidos > 0) {
        std::cout << "Promedio de Estudiantes No Admitidos: " << promedioEstudiantesNoAdmitidos / cantidadEstudiantesNoAdmitidos << std::endl;
    }
    std::cout << "\nPresione cualquier tecla para regresar al menu...";
    std::cin.get();
    std::cin.get();
}

void graficarEstudiantes() {
    std::cout << "\nGrafico de Estudiantes segun Estado:" << std::endl;
    std::cout << "Admitidos\t";
    for (int i = 0; i < cantidadEstudiantesAdmitidos; i++) {
        std::cout << "¦";
    }
    std::cout << std::endl;
    std::cout << "En Espera\t";
    for (int i = 0; i < cantidadEstudiantesEnEspera; i++) {
        std::cout << "¦";
    }
    std::cout << std::endl;
    std::cout << "No Admitidos\t";
    for (int i = 0; i < cantidadEstudiantesNoAdmitidos; i++) {
        std::cout << "¦";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Presione cualquier tecla para regresar al menu...";
    std::cin.get();
    std::cin.get();
}

int main() {
    int opcion;
    do {
        std::cout << "\nMenu Principal" << std::endl;
        std::cout << "1) Ingresar Datos" << std::endl;
        std::cout << "2) Estadisticas" << std::endl;
        std::cout << "3) Grafico" << std::endl;
        std::cout << "4) Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarDatos();
                break;
            case 2:
                calcularEstadisticas();
                break;
            case 3:
                graficarEstudiantes();
                break;
            case 4:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
