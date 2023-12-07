#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QLabel>
#include <QVariantList>

namespace Ui {class global;}
class global{
public:
    static int switchControl; //boton de control total en configuraciones.ui
    static int indice; //indice de pagina en el selector de Modulos
    static int logo;

    //control del progreso de los modulos
    static int m1[4];
    static int m1part;
    static int m1points;
    static int m1total;
    static int m2[4];
    static int m2part;
    static int m2points;
    static int m2total;
    static int m3[4];
    static int m3part;
    static int m3points;
    static int m3total;
    static int m4[4];
    static int m4part;
    static int m4points;
    static int m4total;

    static QString prevProfile;
    static QString currentProfile;
    static QString currentAvatar;
    static QVariantList listaPerfiles;

    static bool conjunt1;
    static bool conjunt2;
    static bool conjunt3;
    static bool conjunt4;
    static bool conjunt5;
    static bool conjunt6;
    static bool conjunt7;
    static bool conjunt8;

public slots:
    static void calcularTotal();
    static void guardarPerfil();
    static void reiniciarVariables();
    static void reiniciarConjuntos();
};



#endif // GLOBAL_H
