#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>
#include <stack>
#include <time.h>
using namespace std;

        //Clase para modelar un unico enrutador

class Arista ;  //Definimos el protoptipo de la clase arista


class Enrutador{

    friend class Red ;


    private:

        char ID ;          //El identificador de cada enrutador será un caracter

        vector <Arista> aristas_enrutador ;     //Vector que contiene las aristas de cada enrutador
                                            //NOTA: tanto un enrutador A y B tienen guardada las misma arista
                                            //que los une en su vector de aristas
    public:

        Enrutador( unsigned short int ) ;       //Constructor

};


    //Clase para modelar la arista/enlace/conexion entre los enrutadores


class Arista{

    friend class Red ;


    private:

        char origen, destino ;          //info que dice con quien está conectado el enrutador

        unsigned int peso ;     //Numero que determinara los valores entre cada enrutador

    public:

        //No hay metodos, se accede a los datos privados desde la clase Red
};

#endif // ENRUTADOR_H

