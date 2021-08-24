#include "red.h"

    //Definicion de cada uno de los metodos de la clase Red

void Red::almacenar_enrutador(Enrutador objeto_enrutador){

    char _id = objeto_enrutador.ID ;


    //Comprobamos que no se repitan las ID de los enrutadores

    if( red_enrutadores.count( _id ) == 0 ){

       red_enrutadores.insert( pair< char , Enrutador >( _id , objeto_enrutador ) ) ;

       cout << endl << " ** Enrutador Correctamente Creado **" << endl ;

    }
    else{

        cout << endl << " *** YA HAY UN ENRUTADOR CON ESA ID ***" << endl << endl ;

    }

}


void Red::tamano_red(){

    cout << endl << " La Red contiene (" << red_enrutadores.size() << ") Enrutadores." << endl ;

    cout << " -----------------------" ;

    cout << endl << " Listado de Enrutadores:" << endl << endl ;

    iterador_red = red_enrutadores.begin() ;

    if( iterador_red == red_enrutadores.end() ){

        cout << " Todavia NO hay Enrutadores" << endl ;

    }
    else{

        for(  ; iterador_red != red_enrutadores.end() ; iterador_red++ ){

            cout << " ID: " << iterador_red->first << endl ;
        }
    }

    cout << " -----------------------" << endl ;

}



void Red::Crear_Arista(){

    Arista arist_1, arist_2 ;        //Creamos el objeto

    char id_enrut, id_destino ;

    unsigned int _peso ;

    cout << endl << " ** Definir Conexion **" << endl << endl ;

    cout << " Ingrese la ID del Enrutador de Origen: " ;
    cin >> id_enrut ;
    cout << endl ;

    cout << " Ingrese la ID del Enrutador de Destino: " ;
    cin >> id_destino ;
    cout << endl ;


    if( id_destino == id_enrut ){           //Verificamos que el usuario no quiera crear una conexion entre un mismo enrutador

        cout << endl << " **NO ES POSIBLE CREAR CONEXION ENTRE EL MISMO ENRUTADOR**" << endl ;
    }
    else{

        cout << endl << " **Definir Valor de la Conexion**" << endl << endl ;

        cout << " Ingrese el Peso entre ambos Enrutadores: " ;
        cin >> _peso ;



        if( _peso == 0 || _peso > 100 ){

            cout << endl << endl << " Valor de Peso Invalido, se asignara 1 por defecto..." << endl << endl ;

            _peso = 1 ;
        }


            //Buscamos el enrutador en el contenedor de red

        iterador_red = red_enrutadores.find( id_enrut ) ;       //Buscamos en la red si está el enrutador ingresado

        iterador_red2 = red_enrutadores.find( id_destino ) ;



        if( iterador_red != red_enrutadores.end() && iterador_red2 != red_enrutadores.end() ){

                                                                    //Si ambos estan, procede a crear la conexion
                //Almacenamos los datos de las aristas

            arist_1.origen = id_enrut ;

            arist_1.destino = id_destino ;

            arist_2.origen = id_destino ;

            arist_2.destino = id_enrut ;

            arist_1.peso = _peso ;

            arist_2.peso = _peso ;

            iterador_red->second.aristas_enrutador.push_back( arist_1 ) ;
                                                                                //Agregamos la arista en el vector de aristas
            iterador_red2->second.aristas_enrutador.push_back( arist_2 ) ;      //de cada enrutador

            cout << endl << " ** Arista Correctamente Creada **" << endl ;

        }
        else{

            cout << endl << " **NO ES POSIBLE CREAR CONEXION ENTRE LOS ENRUTADORES**" << endl ;

        }

    }

}




void Red::Lista_adyacencia(){

    cout << endl << " **Lista de Adyacencia**" << endl ;

    vector<Arista>::iterator it ;       //Iterador de tipo Arista

    cout << endl << " -------------------" << endl ;

    iterador_red = red_enrutadores.begin() ;

    if( iterador_red == red_enrutadores.end() ){        //Se mira si hay enrutadoes en la red

        cout << " Todavia NO hay Enrutadores" << endl ;
    }
    else{

        for(  ; iterador_red != red_enrutadores.end() ; iterador_red++ ){


            cout << " [" << iterador_red->first << "]" ;        //Imprime el ID del enrutador

            it = iterador_red->second.aristas_enrutador.begin() ;

            if( it == iterador_red->second.aristas_enrutador.end() ){       //se mira si hay aristas en cada enrutador

                cout << " Todavia NO tiene conexiones." ;
            }
            else{

                for(  ; it != iterador_red->second.aristas_enrutador.end() ; it++ ){

                    cout << " -{" << it->peso << "}-> " << it->destino << " ||" ;       //Imprime sus conexiones
                }

            }

            cout << endl ;

        }
    }

    cout << " -------------------" << endl ;

}



void Red::Eliminar_Arista(){



    char delete_origen, delete_destino ;

    bool match1 = false, match2 = false ;

    vector<Arista>::iterator it1 ;       //Iteradores de tipo Arista

    vector<Arista>::iterator it2 ;


    cout << endl << " ** Eliminar Conexion **" << endl << endl ;

    cout << " Ingrese las ID de los enrutadores conectados:" << endl ;
    cout << endl << " 1) ";
    cin >> delete_origen ;
    cout << endl << " 2) ";
    cin >> delete_destino ;


    if( delete_destino != delete_origen ){      //Condicional para que no se repita la ID

        iterador_red = red_enrutadores.find( delete_origen ) ;

        iterador_red2 = red_enrutadores.find( delete_destino ) ;


        if( iterador_red != red_enrutadores.end() && iterador_red2 != red_enrutadores.end() ){  //Condicional para ver si exiten


           it1 = iterador_red->second.aristas_enrutador.begin() ;

           it2 = iterador_red2->second.aristas_enrutador.begin() ;


           if( it1 != iterador_red->second.aristas_enrutador.end() && it2 != iterador_red2->second.aristas_enrutador.end() ){


               //Primer enrutador
                for(  ; it1 != iterador_red->second.aristas_enrutador.end() ; it1++ ){

                    if( (it1->origen == delete_origen && it1->destino == delete_destino) || (it1->origen == delete_destino && it1->destino == delete_origen) ){

                        iterador_red->second.aristas_enrutador.erase( it1 ) ; //Borramos la arista

                        match1 = true ;

                        break;
                    }

                }


                //Segundo enrutador

                for(  ; it2 != iterador_red2->second.aristas_enrutador.end() ; it2++ ){

                    if( (it2->origen == delete_origen  && it2->destino == delete_destino ) || (it2->origen == delete_destino  && it2->destino == delete_origen ) ){

                       iterador_red2->second.aristas_enrutador.erase( it2 ) ;

                       match2 = true ;

                       break;
                    }
                }

                if( match1 == true && match2 == true ){

                    cout << endl << endl << " **Conexion Correctamente Eliminada**" << endl ;

                }
                else{

                    cout << endl << " ** NO EXISTE CONEXION ENTRE LOS ENRUTADORES **" << endl ;
                }

           }
           else{

              cout << endl << " ** NO EXISTE CONEXION ENTRE LOS ENRUTADORES **" << endl ;

           }

        }
        else{

            cout << endl << " ** NO EXISTE CONEXION ENTRE LOS ENRUTADORES **" << endl ;

        }


    }
    else{

        cout << endl << " ** NO EXISTE CONEXION ENTRE UN MISMO ENRUTADOR **" << endl ;

    }


}



void Red::Eliminar_Enrutador(){


    char id_delete ;

    unsigned short int op ;

    vector<Arista>::iterator it ;       //Iterador de tipo Arista

    cout << endl << " ** Eliminar Enrutador **" << endl << endl ;

    cout << " Que desea eliminar?" << endl ;
    cout << endl << " Un solo elemento    [0]" ;
    cout << endl << " TODOS los elementos [1]" ;
    cout << endl << endl << " Su Opcion: " ;
    cin >> op ;
    cout << endl ;


    switch( op ){

        case 0:{


            cout << " Ingrese la ID del Enrutador a Eliminar: " ;
            cin >> id_delete ;
            cout << endl ;


            iterador_red = red_enrutadores.find( id_delete ) ;


            if( iterador_red == red_enrutadores.end() ){

                cout << endl << " ** Este Enrutador NO existe **" << endl ;
            }
            else{

                red_enrutadores.erase( iterador_red ) ;         //Borramos el elemnto con esta sentencia


                    //Eliminacion de su conexion con otros enrutadores

                iterador_red = red_enrutadores.begin() ;

                if( iterador_red != red_enrutadores.end() ){


                    for( ; iterador_red != red_enrutadores.end() ; iterador_red++ ){


                        it = iterador_red->second.aristas_enrutador.begin() ;


                        for(  ; it != iterador_red->second.aristas_enrutador.end() ; it++ ){


                            if( it->origen == id_delete || it->destino == id_delete ){


                                iterador_red->second.aristas_enrutador.erase( it ) ;        //Encuentra y elimina
                                                                                          //las aristas que tengan la ID
                                break;                                                      //Del enrutador eliminado
                            }


                        }

                    }


                }

                cout << endl << " ** Enrutador Correctamente eliminado **" << endl ;
            }

        }break;


        case 1:{

            red_enrutadores.clear() ;                   //Elimina todos los elementos del mapa

            cout << endl << " ** Red Correctamente Vaciada **" << endl ;

        }break;


        default:

            cout << endl << " [Consejo: Re-lee las opciones disponibles]" << endl ;

        break;

    }

}




void Red::Modificar_peso(){


    char id_1, id_2 ;

    unsigned int peso_modif ;

    bool match1 = false, match2 = false ;

    vector<Arista>::iterator it1 ;       //Iteradores de tipo Arista

    vector<Arista>::iterator it2 ;


    cout << endl << " ** Modificar el peso de una Conexion **" << endl << endl ;

    cout << " Ingrese las ID de los enrutadores conectados:" << endl ;
    cout << endl << " 1) ";
    cin >> id_1 ;
    cout << endl << " 2) ";
    cin >> id_2 ;


    if( id_1 != id_2 ){

        iterador_red = red_enrutadores.find( id_1 ) ;

        iterador_red2 = red_enrutadores.find( id_2 ) ;


        if( iterador_red != red_enrutadores.end() && iterador_red2 != red_enrutadores.end() ){


            it1 = iterador_red->second.aristas_enrutador.begin() ;

            it2 = iterador_red2->second.aristas_enrutador.begin() ;


            if( it1 != iterador_red->second.aristas_enrutador.end() && it2 != iterador_red2->second.aristas_enrutador.end() ){


                cout << endl << " Ingrese el Nuevo peso entre las conexiones: " ;
                cin >> peso_modif ;


                if( peso_modif == 0 || peso_modif > 100 ){

                    cout << endl << endl << " Valor de Peso Invalido, se asignara 1 por defecto..." << endl << endl ;

                    peso_modif = 1 ;
                }


                //Primer enrutador

                 for(  ; it1 != iterador_red->second.aristas_enrutador.end() ; it1++ ){

                     if( (it1->origen == id_1 && it1->destino == id_2) || (it1->origen == id_2 && it1->destino == id_1) ){

                         it1->peso = peso_modif ;

                         match1 = true ;

                         break;
                     }

                 }


                 //Segundo enrutador

                 for(  ; it2 != iterador_red2->second.aristas_enrutador.end() ; it2++ ){

                     if( (it2->origen == id_1  && it2->destino == id_2 ) || (it2->origen == id_2  && it2->destino == id_1 ) ){

                        it2->peso = peso_modif ;

                        match2 = true ;

                        break;
                     }
                 }


                 if( match1 == true && match2 == true ){

                     cout << endl << endl << " **Conexion Correctamente Modificada**" << endl ;

                 }
                 else{

                     cout << endl << " ** NO EXISTE CONEXION ENTRE LOS ENRUTADORES **" << endl ;
                 }

            }
            else{


                cout << endl << " ** NO EXISTE CONEXION ENTRE LOS ENRUTADORES **" << endl ;

            }


        }
        else{

            cout << endl << " ** NO EXISTE CONEXION ENTRE LOS ENRUTADORES **" << endl ;

        }


    }
    else{

        cout << endl << " ** NO EXISTE CONEXION ENTRE UN MISMO ENRUTADOR **" << endl ;

    }


}





void Red::generacion_automatica(){


    unsigned short int op ;

    cout << " **************************************" ;
    cout << endl << " Si desea cargar una Red desde un archivo," ;
    cout << endl << " cualquier red que haya definido" ;
    cout << endl << " anteriormente, sera eliminada." << endl << endl ;
    cout << " **************************************" ;
    cout << endl << endl << " Desea continuar de todos modos?" << endl ;
    cout << "    Si [0]  ||  No [1]" << endl ;
    cout << endl << " su Opcion: " ;
    cin >> op ;


    switch( op ){


        case 0:{

            string nombre, texto1, texto2 ;

            ifstream archivo ;

            unsigned short int n_aristas = 0 ;


            cout << endl << endl << " ** Cargar Red **" << endl << endl ;


            red_enrutadores.clear() ;       //Vaciamos la red para poder utilizarla


            cout << endl << " Como se llama el archivo que contiene la red?" << endl ;
            cout << endl << endl << " ** ESCRIBA EL NOMBRE DEL ARCHIVO CON SU FORMATO RESPECTIVO **" << endl << endl ;
            cout << "    Nombre: " ;
            cin >> nombre ;

            archivo.open( nombre , ios::in );       //Se abre el archivo en modo lectura

            if( archivo.is_open() ){


                while( !archivo.eof() ){        //Obtencion del contenido del archivo

                    getline( archivo, texto2 ) ;

                    texto2 += ";" ;          //Separador ( por ahora esta useless :/ )

                    texto1.append( texto2 ) ;

                    n_aristas++ ;
                }
                //texto1.pop_back() ;  funcion por si algo, aun asi revisar el archivo de texto

                archivo.close() ;       //Cerramos el archivo una vez que obtenemos todo lo que contiene

                //CREACION DE ENRUTADORES

                char caracter ;



                for( unsigned short int i = 0 ; i < texto1.length() ; i++ ){

                    caracter = texto1[i] ;


                    if( (caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122) ){ //Verificamos que sea letra


                        Enrutador e2(1) ;           //Creamos los Enrutadores

                        e2.ID = caracter ;      //Asignamos una ID

                        if( red_enrutadores.count( caracter ) == 0 ){       //Si no esta replicado, lo guardamos
                                                                                //en la red de enrutadores
                            red_enrutadores.insert( pair< char , Enrutador >( caracter , e2 ) ) ;

                        }



                    }



                }//Fin ciclo for



                //CREACION DE CONEXIONES

                char id1, id2, peso ;

                int pos = 0 ;

                unsigned short peso_def ;

                Arista arist_1, arist_2 ;        //Creamos los objetos


                for( int aris = 0 ; aris < n_aristas ; aris++ ){    //ciclo que funciona de acuerdo al No de conexiones


                    id1 = texto1[pos] ;
                                                //Obtenemos las Ids de los nrutadores y el valor de la conexion
                    id2 = texto1[pos+2] ;

                    peso = texto1[pos+4] ;

                    peso_def = int(peso) - 48 ;     //Convertir de char a int el numero


                    iterador_red = red_enrutadores.find( id1 ) ;       //Buscamos en la red si está el enrutador ingresado

                    iterador_red2 = red_enrutadores.find( id2 ) ;


                    if( iterador_red != red_enrutadores.end() && iterador_red2 != red_enrutadores.end() ){

                            arist_1.origen = id1 ;

                            arist_1.destino = id2 ;

                            arist_2.origen = id2 ;
                                                            //Esto es codigo copiado y pegado de metodos anteriores
                            arist_2.destino = id1 ;

                            arist_1.peso = peso_def ;

                            arist_2.peso = peso_def ;

                            iterador_red->second.aristas_enrutador.push_back( arist_1 ) ;
                                                                                    //Agregamos la arista en el vector de aristas
                            iterador_red2->second.aristas_enrutador.push_back( arist_2 ) ;      //de cada enrutador
                    }

                    pos = pos + 6 ;     //Variable para ir moviendonos y obtener los datos del string
                                                //[no agarra nums de mas de 1 cifra jsjsjs ]
                }

                cout << endl << " ** Archivo Cargado **" << endl ;

            }
            else{

                cout << endl << " El Archivo [" << nombre << "] NO se encontro..." << endl ;
            }


        }break;


        default:

            //Saliendo

        break;


    }


}



bool comparacion( pair<char, unsigned int>a, pair<char, unsigned int>b ){

    bool c ;                        //Funcion que ayuda a ordenar la lista ordenada

    c = a.second < b.second ;

    return c ;

}



void Red::Envio_paquete(){


    char id_origen, id_destino ;

    cout << endl << " ** Costo y Camino Mas Eficiente **" << endl ;
    cout << endl << endl << " *Desde donde SALE el paquete?" << endl ;
    cout << " >Enrutador: " ;
    cin >> id_origen ;

    cout << endl << endl << " *Adonde debe LLEGAR el paquete?" << endl ;
    cout << " >Enrutador: " ;
    cin >> id_destino ;
    cout << endl << " Ruta:" << endl ;
    cout << " ---------------------------" << endl ;
    cout << endl << " " ;


    iterador_red = red_enrutadores.begin() ;

    if( iterador_red == red_enrutadores.end() ){        //Se mira si hay enrutadoes en la red

        cout << endl << endl << " Todavia NO hay Enrutadores" << endl << endl ;
    }
    else{


        //COMPROBAMOS SI NO ESTAN CONECTADOS DIRECTAMENTE

        vector<Arista>::iterator it ;

        bool comprobacion = false ;

        iterador_red = red_enrutadores.find( id_origen );

        it = iterador_red->second.aristas_enrutador.begin() ;

        for( ; it != iterador_red->second.aristas_enrutador.end() ; it++ ){


            if( it->destino == id_destino || it->origen == id_destino ){

                cout << endl << " Los enrutadores estan conectados directamente" ;
                cout << endl << " Costo: " << it->peso << endl ;

                comprobacion = true ;
                break;
            }

        }


        //SI NO ESTAN CONECTADOS DIRECTAMENTE HACEMOS LO SIEGUIENTE


        if( comprobacion == false ){


            vector<Arista>::iterator it ;       //Iterador de aristas

            char enrutador_actual, destino_actual, enru_aux ;

            string origenes ;

            unsigned int costo_actual = 0, band, band2 = 0 ;

            typedef pair<char, unsigned int> costo_enrutador ;          //Definimos un par tipo char-int

            typedef pair<char,char> enrutadorXenrutador ;           //Definimos un par tipo char-char

            list<costo_enrutador> lista_costos ;        //Listas

            list<costo_enrutador> lista_ordenada ;

            list<costo_enrutador>::iterator itlis, itlis2 ;     //Iteradores de listas

            stack<enrutadorXenrutador> pila ;               //Pila de tipo char-char

            lista_costos.push_back( costo_enrutador( id_origen , 0 ) );     //Inicializamos ambas listas con un par
                                                                            // < ID-0 >
            lista_ordenada.push_back( costo_enrutador( id_origen , 0 ) );



            while( !lista_ordenada.empty() ){


                enrutador_actual = lista_ordenada.front().first ;       //Obtenemos la ID del enrutador

                origenes.push_back( enrutador_actual );                 //Pusheamos dicha ID

                costo_actual = lista_ordenada.front().second ;          //Obtenemos el int que representa el costo

                lista_ordenada.pop_front() ;        //Se elimina el par char-int que este en la primera posicion


                if( enrutador_actual == id_destino ){       //Condicion para cuando se encuentre la Id de destino

                    band2 = 1 ;

                    destino_actual = id_destino ;



                    while( !pila.empty() ){


                        cout << destino_actual ;            //Se imprimen las Ids de los enrutadores desde
                                                            //el destino hasta el origen

                        while( !pila.empty() && pila.top().second != destino_actual ){


                            pila.pop() ;        //Se elimina un par char-char de la cola [el que este en el tope]


                        }//fin while3


                        if( !pila.empty() ){


                            destino_actual = pila.top().first ;     //Si hay elementos en la pila, cambia el destino

                            cout << "<-" ;

                        }


                    }//fin while2


                    break;


                }//fin if


                it = red_enrutadores.find(enrutador_actual)->second.aristas_enrutador.begin() ;

                enru_aux = it->destino ;      //Variable que contiene el atributo destino de las aristas del enrutador actual



                while( !origenes.find( enru_aux ) ){        //Condicion para que se mire si l ID en enru_aux ya fue usada
                                                            //si se repite, se itera y se cambia de arista
                    it++ ;

                    enru_aux = it->destino ;

                }


                while( it != red_enrutadores.find( enrutador_actual )->second.aristas_enrutador.end() ){

                    band = 0 ;

                    costo_actual = costo_actual + it->peso ;    //it->peso = peso del enrutador destino de la arista


                    for( itlis = lista_costos.begin() ; itlis != lista_costos.end() ; itlis++ ){    //Se itera sobre la
                                                                                                    //lista de costos

                        if( enru_aux == itlis->first ){     //Condicional que busca en la lista de costos la ID destino del enrutador actual



                            band = 1 ;


                            if( costo_actual < itlis->second ){     //Se compara el costo actual con el del enrutador en la lsita de costos

                                itlis->second = costo_actual ;      //Si es menor, se cambia la de la lista [Indica que el camino por ahi es mas barato]


                                for( itlis2 = lista_ordenada.begin() ; itlis2 != lista_ordenada.end() ; itlis2++ ){     //Se itera sobre la lista ordenada


                                    if( enru_aux == itlis2->first ){        //Se busca la ID del destino de la rista dentro de la lista ordenada


                                        itlis2->second = costo_actual ;     //Si esta, se le cambia su costo
                                    }

                                }


                                lista_ordenada.sort( comparacion ) ;        //Se ordena la lista

                                pila.push( enrutadorXenrutador( enrutador_actual, enru_aux ) ) ;    //Se agrega  la pila

                                costo_actual = costo_actual - it->peso ;        //Y se reestablece el costo actual


                            }

                        }

                    }//fin ciclo for


                    if( band == 0 ){        //Si el if del comienzo del ciclo for no se cumple, la bandera se mantiene en 0

                       lista_costos.push_back(costo_enrutador( enru_aux , costo_actual ) )  ;

                       lista_ordenada.push_back( costo_enrutador( enru_aux , costo_actual ) ) ;     //Añadimos a las listas un par char-int
                                                                                                    //con la ID del enrutador destino de la arista y su costo hata ahi
                       lista_ordenada.sort( comparacion ) ;     //Se ordena la lista de costos, de meno a mayor numero [int]

                       pila.push( enrutadorXenrutador( enrutador_actual , enru_aux ) ) ;        //Se agrega el par de IDs a la pila [Nodo actual - Nodo revisado]

                       costo_actual = costo_actual - it->peso ;     //El valor de costo actual se reestablece al anterior

                    }

                    it++ ;      //Se itera en las aristas

                    enru_aux = it->destino ;        //Se cambia el destino


                }//fin while4



            }//fin while1

            if( band2 == 0 ){       //Si todo el proceso termina y band2 es 0 es porque no hay forma de llegar de un enrutador a otro

                cout << endl << " Los enrutadores NO estan conectados..." << endl ;

                costo_actual = 0 ;
            }

            cout << endl << endl << " [ Costo: " << costo_actual << " ]" << endl ;


        }//fin super if


    }


}




void Red::red_aleatoria(){


    unsigned short int op ;

    cout << " **************************************" ;
    cout << endl << "  Si desea generar una Red Aleatoria" ;
    cout << endl << "   cualquier red que haya definido" ;
    cout << endl << "   anteriormente, sera eliminada." << endl << endl ;
    cout << " **************************************" ;
    cout << endl << endl << " Desea continuar de todos modos?" << endl ;
    cout << "    Si [0]  ||  No [1]" << endl ;
    cout << endl << " su Opcion: " ;
    cin >> op ;


    switch( op ){


        case 0:{

            cout << endl << endl << " ** Red Aleatoria **" << endl << endl ;

            int n ;             //Variable que representa el numero de enrutadores

            float p ;           //Variable que representa la probabilidad de enlace

            string IDs = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm" ;

            string creados ;

            red_enrutadores.clear() ;       //Vaciamos la red para poder utilizarla



            cout << endl << " Numero de Enrutadores" ;
            cout << endl << " ----------------------------" << endl ;

            do{     //Pedimos al usuario el numero de enrutadores [2 <= n <= 54]


               cout << endl << " Ingrese un numero entre 2 y 54" << endl ;
               cout << " Numero: " ;
               cin >> n ;

            }while( n < 2 || n > 54 );



            cout << endl << endl ;
            cout << endl << " Probabilidad de Enlace" ;
            cout << endl << " ----------------------------" << endl ;


            do{     //Pedimos al usuario un valor p [0<= p >= 1]


                cout << " Ingrese un numero entre 0 y 1" << endl ;
                cout << " Numero: " ;
                cin >> p ;

            }while( p < 0 || p > 1 );


            //GENERACION DE ENRUTADORES


            int random_int, lim = 52 ;      //lim = numero de latras en el string IDs

            char id_enrutador ;

            for( int i = 0 ; i < n ; i++ ){

                srand(time(NULL)) ;

                random_int = rand()%lim ;            //Generamos un numero aleatorio entre o y 51

                id_enrutador = IDs[ random_int ] ;      //Obtenemos el ID del enrutador

                IDs.erase( random_int, 1 ) ;           //Borramos dicho caracter del string, para que no se repita luego

                lim-- ;



                Enrutador e3(1) ;           //Creamos los Enrutadores

                e3.ID = id_enrutador ;      //Asignamos una ID

                red_enrutadores.insert( pair< char , Enrutador >( id_enrutador , e3 ) ) ;   //Los guardamos en la red

                creados.push_back( id_enrutador );  //String que contiene las ids de los enrutadores creados

            }



            //GENERADOR DE ENLACES

            //bool enlazar ;

            char ID1, ID2 ;

            unsigned int peso_ ;

            int num_prob, random_num ;


            Arista arist_1, arist_2 ;        //Creamos el objeto

            string NO_usados ;

            iterador_red = red_enrutadores.begin() ;

            num_prob = p*100 ;      //Sacamos un numero a partir de la multiplicacion de la probabilidad por 100


            for( ; iterador_red != red_enrutadores.end() ; iterador_red++ ){        //Recorremos los enrutadores


                ID1 = iterador_red->first ;

                iterador_red2 = iterador_red ;      //Nos paramos en un enrutador y empezamos luego a recorrer la red a partir de el

                iterador_red2++ ;


                for( ; iterador_red2 != red_enrutadores.end() ; iterador_red2++ ){


                    ID2 = iterador_red2->first ;

                    random_num = rand()%100 ;

                    peso_ = 1 + rand() % 100 ;

                    if( num_prob > random_num ){        //Condicion que determina si se mantiene el enlace entre 2 enrutadores

                        arist_1.origen = ID1 ;

                        arist_1.destino = ID2 ;

                        arist_1.peso = peso_ ;

                        arist_2.origen = ID2 ;

                        arist_2.destino = ID1 ;

                        arist_2.peso = peso_ ;

                        iterador_red->second.aristas_enrutador.push_back( arist_1 );

                        iterador_red2 ->second.aristas_enrutador.push_back( arist_2 ) ;

                    }
                    else{

                        NO_usados.push_back( ID2 ) ;        //Si un Id no se usa para un Enrutador, se agrega a este string
                    }



                }


                if( iterador_red->second.aristas_enrutador.empty() ){       //Condicion para garantizar que cada enrutador tengra por lo menos una arista

                    map <char,Enrutador>::iterator iterador_red3 ;

                    int pos ;

                    unsigned int pesso ;

                    char alter_ID ;


                    if( !NO_usados.empty() ){       //Usamos una Id aleatoria de las NO usadas

                        pos = rand()% NO_usados.length() ;

                        alter_ID = NO_usados[ pos ] ;
                    }
                    else{

                        alter_ID = creados[0] ;     //Si el ultimo enrutador no obtuvo ninguna conexion, se le asigna el primer enrutador que se creo
                    }

                    pesso = 1 + rand() % 100 ;

                    arist_1.origen = ID1 ;

                    arist_1.destino = alter_ID ;

                    arist_1.peso = pesso ;

                    arist_2.origen = alter_ID ;

                    arist_2.destino = ID1 ;
                                                                //se le asiganan sus datos correspondientes
                    arist_2.peso = pesso ;

                    iterador_red->second.aristas_enrutador.push_back( arist_1 );

                    iterador_red3 = red_enrutadores.find( alter_ID ) ;

                    iterador_red3->second.aristas_enrutador.push_back( arist_2 ) ;

                }

                NO_usados.clear() ;         //Se limpia el string de No usados para el ste enrutador

            }


            cout << endl << endl << " ** Red Aleatoria Correctamente Creada **" << endl << endl ;


        }break;


        //No hace nada

        default:


        break;


    }


}
