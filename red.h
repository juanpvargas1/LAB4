#ifndef RED_H
#define RED_H

#include "enrutador.h"

        //Clase para modelar una Red de enrutadores


class Red{



    private:

        map <char,Enrutador> red_enrutadores ;      //Contenedor de los enrutadores

        map <char,Enrutador>::iterator iterador_red ;       //Iterador de la Red

        map <char,Enrutador>::iterator iterador_red2 ;       //Iterador de la Red 2

    public:

            //Metodos de la clase Red

       void almacenar_enrutador( Enrutador objeto_enrutador ) ;

       void tamano_red() ;

       void Crear_Arista() ;

       void Lista_adyacencia() ;

       void Eliminar_Enrutador() ;

       void Eliminar_Arista() ;

       void Modificar_peso() ;

       void generacion_automatica() ;

       void Envio_paquete() ;

       void red_aleatoria() ;


};


bool comparacion( pair<char, unsigned int> a, pair<char, unsigned int>b );      //Funcion complementaria para
                                                                                //el metodo Envio_paquete()

#endif // RED_H


