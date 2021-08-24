#include "enrutador.h"


        //Definicion de cada uno de los metodos de la clase Enrutador

Enrutador::Enrutador( unsigned short int n ){

    if( n == 0){

        char _id ;

        cout << " Ingrese la ID del Enrutador: " ;
        cin >> _id ;

        ID = _id ;

    }

}
