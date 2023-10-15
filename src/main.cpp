#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>



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
    ifstream infile(nombre_archivo);                    
    if(!infile){
        cout << "No se ha encontrado el archivo" << endl;
        return 0;
    }

    while(getline(infile, linea)){                      //busca la palabra u expresion sin importan mayus o minus
        if (search(linea.begin(), linea.end(), busqueda.begin(), busqueda.end(),          
            [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); }) != linea.end()) {
            switch (color_of_choice)
            {
            case '1':
                console_color(1);   //blue
                break;
            case '2':
                console_color(2); //green
                break;
            case '3':
                console_color(3); //light blue or cya
                break;
            case '4':
                console_color(4); //red
                break;
            case '5':
                console_color(5); //purple
                break;
            case '6':
                console_color(6); //yellow
                break;
            case '7':
                console_color(7); //white
                break;
            case '8':
                console_color(8); //grey
                break;
            default:
                console_color(7); //default white
                break;
            }
             
            cout << linea << endl;
        }
    }
    
   console_color(7);

}