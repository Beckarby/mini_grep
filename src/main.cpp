#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

void console_color(WORD c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main(int argc, char** argv){
    string busqueda = argv[1];
    string nombre_archivo = argv[2];
    char color_of_choice = ' ';
    color_of_choice = *argv[1];

    ifstream infile(nombre_archivo);
    if(!infile){
        cout << "No se ha encontrado el archivo" << endl;
        return 0;
    }
    string line;
    while(getline(infile, line)){
        if (line.find(busqueda) != string::npos){
            console_color(FOREGROUND_GREEN);
            cout << line << endl;
        }
    }
    /*
               
                        
        switch (color_of_choice){
        case '1':
            console_color(90);
            cout << color_of_choice << endl;
            break;
        case '2':
            console_color(FOREGROUND_RED);
            cout << color_of_choice << endl;
            break;
        case '3':
            console_color(FOREGROUND_GREEN);
            cout << color_of_choice << endl;
            break;
        case '4':
            console_color(93);
            cout << color_of_choice << endl;
            break;
        case '5':
            console_color(FOREGROUND_BLUE);
            cout << color_of_choice << endl;
            break;
        case '6':
            console_color(95);
            cout << color_of_choice << endl;
            break;
        case '7':
            console_color(96);
            cout << color_of_choice << endl;
            break;
        case '8':
            console_color(7);
            cout << color_of_choice << endl;
            break;
        default:
            cout << "ha ingresado un color equivocado." << endl;
            break;
        }
        
    }
    */
   console_color(7);

}