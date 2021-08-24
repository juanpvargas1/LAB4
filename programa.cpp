#include "programa.h"

    //PROGRAMA PRINCIPAL

void programa_principal(){

    short int opcion, opcion2 ;

    bool seguir = true ;

    Red red_principal ;            //La red debe de estar afuera del while para que no se borren las cosas que contiene

    while( seguir == true ){

        cout << endl << " ---BIENVENIDO---" << endl  << endl ;
        cout << " *Que desea hacer?" << endl << endl ;
        cout << " Modelar Red           [0]" << endl ;
        cout << " Envio Paquete         [1]" << endl ;
        cout << " Generar Red Aleatoria [2]" << endl ;
        cout << endl << " Su Opcion: " ;
        cin >> opcion ;
        cout << endl ;

        switch( opcion ){


            case 0 :{   //Modelar Red [dentro de esta esta la ocpion de cargarla desde un archivo]

                unsigned short int opcion3 ;

                cout << " ** MODELADO DE RED **" << endl ;

                cout << endl << " Agregar un Enrutador  [0]" ;
                cout << endl << " Agregar una conexion  [1]" ;
                cout << endl << " Tamano de la Red      [2]" ;
                cout << endl << " Lista de Adyacencia   [3]" ;
                cout << endl ;
                cout << endl << " Eliminar un Enrutador [4]" ;
                cout << endl << " Eliminar una conexion [5]" ;
                cout << endl << " Cambiar peso conexion [6]" ;
                cout << endl ;
                cout << endl << " Cargar una Red        [7]" ;
                cout << endl << endl << " Su Opcion: " ;
                cin >> opcion3 ;
                cout << endl ;


                switch( opcion3 ){

                    case 0:{


                        Enrutador e1(0) ;      //Constructor de la clase Enrutador, esta linea crea e objeto directamente

                        red_principal.almacenar_enrutador(e1);      //Almacenamos el objeto anteriormente creado


                    }break;


                    case 1:{

                        red_principal.Crear_Arista() ;          //Accedemos al metodo crear_arista()

                    }break;


                    case 2:{

                        red_principal.tamano_red();     //tamaño y listado e la red principal

                    }break;

                    case 3:{

                        red_principal.Lista_adyacencia();       //Lista de Adyacencia

                    }break;


                    case 4:{

                        red_principal.Eliminar_Enrutador() ;       //Eliminar enrutador

                    }break;


                    case 5:{

                        red_principal.Eliminar_Arista() ;                //Eliminar arista

                    }break;


                    case 6:{

                        red_principal.Modificar_peso() ;        //Modificar el peso entre 2 enrutadores

                    }break;


                    case 7:{

                        red_principal.generacion_automatica();      //Cargar una red desde un archivo txt

                    }break;


                    default:

                        cout << endl << " [Consejo: Re-lee las opciones disponibles]" << endl ;

                    break;

                }

            }break;


            case 1 :{   //Envio paquete (consulta costo y camino mas corto)

                red_principal.Envio_paquete();

            }break;


            case 2 :{   //Generar Red aleatoria

                red_principal.red_aleatoria() ;

            }break;


            default:

                cout << endl << " [Consejo: Re-lee las opciones disponibles]" << endl ;

            break;


        }


        cout << endl << " Desea seguir usando el Programa?" << endl << endl ;
        cout << "      Si [0]  ||  No [1]" << endl ;
        cout << endl << "            R/: " ;
        cin >> opcion2 ;

        system("cls") ;     //Comando para limpiar la pantalla de la consola

        if( opcion2 == 0 ){

            seguir = true ;
        }
        else{

            seguir = false ;
        }


    }

    cout << endl << "    [CERRANDO PROGRAMA]" << endl << endl ;
}

