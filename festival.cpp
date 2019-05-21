#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Asistente {
    string nombre, dni, cuenta, correo;
    int nacimiento;
};

struct Concierto
{
    char banda[20];
    int precio, hora;
};

vector<Concierto> leerFichero() {
    FILE *conciertosFile;
    conciertosFile = fopen("conciertos.txt", "r");
    Concierto concierto;
    vector<Concierto> conciertos;

    if (conciertosFile == NULL) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    while (!feof(conciertosFile)) {
        fscanf(conciertosFile, "%s %d %d", concierto.banda, &concierto.precio, &concierto.hora);
        conciertos.push_back(concierto);
    }

    return conciertos;
}

Asistente leerAsistente() {
    Asistente asistente;
    cout << "Introduzca su nombre: ";
    cin >> asistente.nombre;
    cout << "Introduzca su DNI: ";
    cin >> asistente.dni;
    cout << "Introduzca su año de nacimiento: ";
    cin >> asistente.nacimiento;
    if (2019 - asistente.nacimiento < 18)
    {
        cout << "Prohibida la entrada a menores de edad" << endl;
        exit(1);
    }
    cout << "Introduzca su cuenta bancaria: ";
    cin >> asistente.cuenta;
    cout << "Introduzca su correo electronico: ";
    cin >> asistente.correo;
    return asistente;
}

float totalizarConciertos(vector<Concierto> conciertos) {
    float costoTotal = 0;

    for (int i = 0; i < conciertos.size(); i++) {
        cout << i << " - " << conciertos[i].banda << " a las " << conciertos[i].hora << " por " << conciertos[i].precio << endl;
        costoTotal += conciertos[i].precio;
    }
    // descuento del 25% para la entrada a todos los conciertos
    costoTotal -= costoTotal * 0.25;
    cout << conciertos.size() << " - Todos los conciertos por " << costoTotal << endl;

    return costoTotal;
}

vector<int> seleccionarConciertos() {
    vector<int> conciertosElegidos;
    int conciertoSeleccion;
    bool repetido = false;
    char seleccionarOtro;
    do {
        cout << "Seleccione una opcion: ";
        cin >> conciertoSeleccion;
        
        for (int i = 0; i < conciertosElegidos.size(); i++) {
            if (conciertoSeleccion == conciertosElegidos[i]) {
                repetido = true;
            }
        } 

        if (!repetido) {
            conciertosElegidos.push_back(conciertoSeleccion);
        } else {
            cout << "Ya selecciono este concierto" << endl;
        }

        cout << "Desea seleccionar otro? (s/n) ";
        cin >> seleccionarOtro;
        repetido = false;
    } while (seleccionarOtro == 's');

    return conciertosElegidos;
}

int seleccionarCamping() {
    int camping;
    cout << "Seleccine uno de nuestros campings" << endl;
    cout << "0 - Ninguno" << endl;
    cout << "1 - Zona comun por 50" << endl;
    cout << "2 - Zona VIP(mejor situado sin necesidad de comprar autobus aparte y con mejores instalaciones)por 100" << endl;
    cin >> camping;
    return camping;
}

int seleccionarBus(int camping) {
    int bus = 0;
    if (camping == 1) {
        cout << "Seleccione si desea tomar el autobus que lo acercara a la zona de conciertos" << endl;
        cout << "0 - No" << endl;
        cout << "1 - Si por 20" << endl;
        cin >> bus;
    }
    return bus;
}

void mostrarFactura(Asistente asistente, vector<Concierto> conciertos, float costoTotal, vector<int> conciertosElegidos, int camping, int bus) {
    bool festivalCompleto = false;
    float totalFactura = 0;

    cout << "DNI: " << asistente.dni << endl;
    cout << "Año de nacimiento: " << asistente.nacimiento << endl;
    cout << "--- Compra ---" << endl;
    for (int i = 0; i < conciertosElegidos.size(); i++) {
        if (conciertosElegidos[i] == conciertos.size()) {
            festivalCompleto = true;
            cout << "Summer Festival completo -- " << costoTotal << endl;
            totalFactura += costoTotal;
        }
    }
    if (!festivalCompleto) {
        for (int i = 0; i < conciertosElegidos.size(); i++) {
            cout << conciertos[conciertosElegidos[i]].banda << " a las " << conciertos[conciertosElegidos[i]].hora << " -- " << conciertos[conciertosElegidos[i]].precio << endl;
            totalFactura += conciertos[conciertosElegidos[i]].precio;
        }
    }
    if (camping == 1) {
        cout << "Camping Zona comun -- 50" << endl;
        totalFactura += 50;
    } else if (camping == 2) {
        cout << "Camping Zona VIP -- 100" << endl;
        totalFactura += 100;
    }
    if (bus == 1) {
        cout << "Bus -- 20" << endl;
        totalFactura += 20;
    }

    char aceptar;
    cout << "Total a ingresar " << totalFactura << endl;
    cout << "Cuenta bancaria: " << asistente.cuenta << endl;
    cout << "Correo electronico: " << asistente.correo << endl;
    cout << asistente.nombre << " confirmanos que todo esta bien" << endl;
    cout << "Desea cogerlo? (s/n) ";
    cin >> aceptar;

    if (aceptar == 's') {
        cout << "Disfrute de su concierto!" << endl;
    } else {
        cout << "Operacion cancelada" << endl;
    }
}

int main() {
    cout << "Bienvenido al summer festival - Conciertos disponibles" << endl;
    
    vector<Concierto> conciertos = leerFichero();
    Asistente asistente = leerAsistente();
    float costoTotal = totalizarConciertos(conciertos);
    vector<int> conciertosElegidos = seleccionarConciertos();
    int camping = seleccionarCamping();
    int bus = seleccionarBus(camping);
    
    cout << endl;

    mostrarFactura(asistente, conciertos, costoTotal, conciertosElegidos, camping, bus);

    return 0;
}
