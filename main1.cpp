//
// Created by sv231 on 16/09/2026.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    //Variables de la primera parte
    string nombreEvento;
    int cantidadAsistentes;
    double duracionHoras, costoAlquilerHora, costoAlimentacionPersona, costoMaterialPersona, costoServicioSonido;
    double costoTransporte, totalAlquiler, totalAlimentacion, totalCostoMateriales, admin, subtotal, valorTotal;

    //Variables de la segunda parte
    string clasificacionEvento, nombreTipoEvento, nombreTipoCliente;
    int tipoEvento, tipoCliente;
    char esFindeSemana, esSonidoPremium;

    //Entradass de la primera parte
    cout << "Ingrese el nombre del evento: ";
    getline(cin, nombreEvento);

    cout << "Ingrese la cantidad de asistentes: ";
    cin >> cantidadAsistentes;

    cout << "Ingrese la cantidad de horas de duracion del evento: ";
    cin >> duracionHoras;

    cout << "Ingrese el costo por hora del espacio: ";
    cin >> costoAlquilerHora;

    cout << "Ingrese el costo de alimentacion por persona: ";
    cin >> costoAlimentacionPersona;

    cout << "Ingrese el costo del material por persona: ";
    cin >> costoMaterialPersona;

    cout << "Ingrese el costo del servicio de sonido: ";
    cin >> costoServicioSonido;

    cout << "Ingrese el costo del transporte: ";
    cin >> costoTransporte;

    //Entradas de la segunda parte
    cout << "\nSeleccione el tipo de evento:\n";
    cout << "1 = Conferencia\n2 = Seminario\n3 = Congreso\n4 = Evento empresarial\nOpcion: ";
    cin >> tipoEvento;

    cout << "\nSeleccione el tipo de cliente:\n";
    cout << "1 = Cliente nuevo\n2 = Cliente frecuente\n3 = Cliente corporativo\nOpcion: ";
    cin >> tipoCliente;

    cout << "\nEl evento se realiza en fin de semana? (1 = Si, 0 = No): ";
    cin >> esFindeSemana;

    cout << "El cliente solicita servicio premium de sonido? (1 = Si, 0 = No): ";
    cin >> esSonidoPremium;

    //Cálculos de la primera parte
    totalAlquiler = duracionHoras * costoAlquilerHora;
    totalAlimentacion = cantidadAsistentes * costoAlimentacionPersona;
    totalCostoMateriales = cantidadAsistentes * costoMaterialPersona;

    //Subtotal inicial de la primera parte
    subtotal = totalAlquiler + totalAlimentacion + totalCostoMateriales + costoServicioSonido + costoTransporte;

    //1. Clasificación por cantidad de asistentes
    if (cantidadAsistentes < 50) {
        clasificacionEvento = "Evento pequeño";
    } else if (cantidadAsistentes <= 149) {
        clasificacionEvento = "Evento mediano";
    } else if (cantidadAsistentes <= 299) {
        clasificacionEvento = "Evento grande";
    } else {
        clasificacionEvento = "Evento masivo";
    }

    //2. Recargo por tipo de evento (sobre subtotal inicial)
    double recargoTipoEvento = 0.0;
    if (tipoEvento == 1) {
        nombreTipoEvento = "Conferencia";
        recargoTipoEvento = subtotal * 0.00;
    } else if (tipoEvento == 2) {
        nombreTipoEvento = "Seminario";
        recargoTipoEvento = subtotal * 0.03;
    } else if (tipoEvento == 3) {
        nombreTipoEvento = "Congreso";
        recargoTipoEvento = subtotal * 0.07;
    } else if (tipoEvento == 4) {
        nombreTipoEvento = "Evento empresarial";
        recargoTipoEvento = subtotal * 0.10;
    } else {
        nombreTipoEvento = "No especificado";
        recargoTipoEvento = 0.0;
    }

    //3. Descuento por tipo de cliente (sobre subtotal inicial)
    double descTipoCliente = 0.0;
    if (tipoCliente == 1) {
        nombreTipoCliente = "Cliente nuevo";
        descTipoCliente = subtotal * 0.00;
    } else if (tipoCliente == 2) {
        nombreTipoCliente = "Cliente frecuente";
        descTipoCliente = subtotal * 0.05;
    } else if (tipoCliente == 3) {
        nombreTipoCliente = "Cliente corporativo";
        descTipoCliente = subtotal * 0.10;
    } else {
        nombreTipoCliente = "No especificado";
        descTipoCliente = 0.0;
    }

    //4. Recargo por duración > 8 horas (5% sobre subtotal)
    double recargoDuracion = 0.0;
    if (duracionHoras > 8.0) {
        recargoDuracion = subtotal * 0.05;
    }

    //5. Recargo por fin de semana (8% sobre totalAlquiler)
    double recargoFindeSemana = 0.0;
    if (esFindeSemana) {
        recargoFindeSemana = totalAlquiler * 0.08;
    }

    //6. Recargo por sonido premium (20% sobre costoServicioSonido)
    double recargoSonidoPremium = 0.0;
    if (esSonidoPremium) {
        recargoSonidoPremium = costoServicioSonido * 0.20;
    }

    //7. Descuento corporativo adicional (3% sobre subtotal si es corporativo y asistentes >= 200)
    double descCorporativoAdicional = 0.0;
    if (tipoCliente == 3 && cantidadAsistentes >= 200) {
        descCorporativoAdicional = subtotal * 0.03;
    }

    //8. Recargo logístico (4% sobre subtotal si asistentes >= 300 y duracion > 6 horas)
    double recargoLogistico = 0.0;
    if (cantidadAsistentes >= 300 && duracionHoras > 6.0) {
        recargoLogistico = subtotal * 0.04;
    }

    //Cálculo del subtotal y total final de la segunda parte
    double totalRecargos = recargoTipoEvento + recargoDuracion + recargoFindeSemana + recargoSonidoPremium + recargoLogistico;
    double totalDescuentos = descTipoCliente + descCorporativoAdicional;

    double subtotalAjustado = subtotal + totalRecargos - totalDescuentos;
    double adminAjustado = subtotalAjustado * 0.06;
    double valorTotalFinal = subtotalAjustado + adminAjustado;

    // Configurar salida a 2 decimales para montos de moneda
    cout << fixed << setprecision(2);

    cout << "\n==============================================" << endl;
    cout << "           COTIZACION FINAL DEL EVENTO        " << endl;
    cout << "==============================================" << endl;
    cout << "Nombre del evento:               " << nombreEvento << endl;
    cout << "Tipo de evento:                 " << nombreTipoEvento << endl;
    cout << "Tipo de cliente:                " << nombreTipoCliente << endl;
    cout << "Cantidad de asistentes:         " << cantidadAsistentes << endl;
    cout << "Clasificacion del evento:       " << clasificacionEvento << endl;
    cout << "Duracion del evento:            " << duracionHoras << " horas" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Costo de alquiler base:        $" << totalAlquiler << endl;
    cout << "Costo de alimentacion:         $" << totalAlimentacion << endl;
    cout << "Costo de materiales:           $" << totalCostoMateriales << endl;
    cout << "Costo de sonido base:          $" << costoServicioSonido << endl;
    cout << "Costo de transporte:           $" << costoTransporte << endl;
    cout << "Subtotal inicial:              $" << subtotal << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Recargo por tipo de evento:    +$" << recargoTipoEvento << endl;
    cout << "Recargo por duracion (>8h):    +$" << recargoDuracion << endl;
    cout << "Recargo por fin de semana:     +$" << recargoFindeSemana << endl;
    cout << "Recargo por sonido premium:    +$" << recargoSonidoPremium << endl;
    cout << "Recargo logistico:             +$" << recargoLogistico << endl;
    cout << "Descuento por tipo de cliente: -$" << descTipoCliente << endl;
    cout << "Descuento corporativo adicional:-$" << descCorporativoAdicional << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Subtotal ajustado:             $" << subtotalAjustado << endl;
    cout << "Tarifa administrativa (6%):    $" << adminAjustado << endl;
    cout << "Total final de la cotizacion:  $" << valorTotalFinal << endl;
    cout << "==============================================" << endl;

    return 0;
}
