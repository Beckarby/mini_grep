#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <sstream>


using namespace std;

void console_color(WORD c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main(int argc, char** argv){
    string busqueda = argv[1];                          //palabra a buscar
    string nombre_archivo = argv[2];                    //ruta del archivo txt
    char color_of_choice = ' ';
    color_of_choice = *argv[3];                        //color del texto encontrado
    string linea;
    int parrafos = 0;
    int cont = 0;

    ifstream infile(nombre_archivo);                    
    if(!infile){
        std::cout << "No se ha encontrado el archivo" << endl;
        return 0;
    }
   
    while(getline(infile, linea)){                //busca la palabra u expresion sin importan mayus o minus
        size_t pos = linea.find(busqueda);

            if (search(linea.begin(), linea.end(), busqueda.begin(), busqueda.end(),          
                [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); }) != linea.end()) {
                    
                    cout << linea.substr(0, pos);
                                    
                if (pos != string::npos) {
                    switch (color_of_choice) {
                        case '1':
                            console_color(1);   // blue
                            break;
                        case '2':
                            console_color(2); // green
                            break;
                        case '3':
                            console_color(3); // light blue or cyan
                            break;
                        case '4':
                            console_color(4); // red
                            break;
                        case '5':
                            console_color(5); // purple
                            break;
                        case '6':
                            console_color(6); // yellow
                            break;
                        case '7':
                            console_color(7); // white
                            break;
                        case '8':
                            console_color(8); // grey
                            break;
                        default:
                            console_color(7); // default white
                            break;
                    } 
                   
                    cout << linea.substr(pos, busqueda.length());
                    console_color(7);
                    cout << linea.substr(pos + busqueda.length()) << endl;                
                    cont++;
                }           
                
            }
    }
    if(cont > 1){
        std::cout << endl <<"Han habido " << cont << " coincidencias";
    }else {
        cout << "No se encontraron coincidencias" << endl;
    }
    infile.close();

}