#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void agregarUsuario(string name) {
    ofstream archivo("usuarios.txt", ios::app); // Abre el archivo en modo de agregar (append)
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo usuarios.txt" << endl;
        return;
    }

    if (!archivo.tellp()) { // Verifica si el archivo está vacío
        archivo << name; // No agrega el ";" antes del primer nombre
    } else {
        archivo << ";" << name; // Agrega el ";" antes del nombre
    }
    
    archivo.close();
}

void agregarPermisos(string name, const vector<int>& permisos) {
    ofstream archivo("permisos.txt", ios::app); // Abre el archivo en modo de agregar (append)
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo permisos.txt" << endl;
        return;
    }

    archivo << name << ";";
    for (size_t i = 0; i < permisos.size(); ++i) {
        archivo << permisos[i];
        if (i < permisos.size() - 1) {
            archivo << ",";
        }
    }
    archivo << endl; // Agrega una nueva línea al final de los permisos

    archivo.close();
}




void sumatoria(vector<int> v);
void promedio(vector<int> v);
void moda(vector<int> v);
void contar(vector<int> v);
bool verificarUsuario(string nombre);
vector<int> permisosInput(string permisos);
vector<int> permisosTxt(string usuario);


int main(int argc, char* argv[]){
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <usuario>:<permiso1>;<permiso2>;<permiso3>" << endl;
        return EXIT_FAILURE;
    }

    string usuarioYPermisos = argv[1];
    string usuario = usuarioYPermisos.substr(0, usuarioYPermisos.find(':'));

    if(!verificarUsuario(usuario)){
        cout << "¿Deseas agregarlo? (S/N): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            agregarUsuario(usuario);
            cout << "Usuario agregado correctamente." << endl << endl;

            cout << "Ingrese los permisos separados por comas (ej: 1,2,3): ";
            string permisosStr;
            cin.ignore(); 
            getline(cin, permisosStr);

            vector<int> nuevosPermisos = permisosInput(permisosStr);
            agregarPermisos(usuario, nuevosPermisos);
            cout << "Permisos agregados correctamente." << endl << endl;

        } else {
            return EXIT_FAILURE;
        }
    }

    
    cout << "USUARIO: " << usuario << endl;

    string permisosStr = usuarioYPermisos.substr(usuarioYPermisos.find(':')+1);
    // cout << permisosStr << endl;

    vector<int> vectorInput = permisosInput(permisosStr);
    vector<int> permisostxt = permisosTxt(usuario);
    cout << endl;
    sort(permisostxt.begin(), permisostxt.end());

    for (int permiso : permisostxt) {
        switch (permiso){
            case 1:
                cout << "1) realizar sumatoria del vector" << endl;
                break;
            case 2:
                cout << "2) realizar promedio del vector" << endl;
                break;
            case 3:
                cout << "3) realizar moda del vector" << endl;
                break;
            case 4:
                cout << "4) contar elementos del vector" << endl;
                break;
            default:
                cout << "No valido" << endl;
                return EXIT_FAILURE;
        }
    }

    int opcion;
    do{
        cout << "Ingrese opcion (0 para terminar): ";
        cin >> opcion;
        if (find(permisostxt.begin(), permisostxt.end(), opcion) == permisostxt.end() && opcion != 0){
            cout << "El usuario no tiene permiso para " << opcion << endl << endl;
        }
        else{
            switch (opcion){
                case 1:
                    sumatoria(vectorInput);
                    break;
                case 2:
                    promedio(vectorInput);
                    break;
                case 3:
                    moda(vectorInput);
                    break;
                case 4:
                    contar(vectorInput);
                    break;
                default:
                    cout << "No valido" << endl;
                    return EXIT_FAILURE;
            }  
        }

    }while(opcion != 0);
    
    return EXIT_SUCCESS;

}


bool verificarUsuario(string name){
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo usuarios.txt" << endl;
        return EXIT_FAILURE;
        return 1;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string token;
        vector<string> nombres;

        while (getline(iss, token, ';')) {
            nombres.push_back(token);
        }

        for (const string& nombre : nombres) {
            if (nombre == name) {
                cout << "El nombre '" << name << "' está en el archivo." << endl;
                archivo.close();
                return true;
            }
        }
    }

    cout << "El nombre '" << name << "' no se encontró en el archivo." << endl;
    archivo.close();
    return false;
}

vector<int> permisosInput(string permisosStr){
    size_t startPos = 0; 
    size_t endPos = permisosStr.find(',');
    vector<int> permisos;

    while (endPos != string::npos) {
        int number = stoi(permisosStr.substr(startPos, endPos - startPos));
        permisos.push_back(number);
        
        startPos = endPos + 1;
        endPos = permisosStr.find(',', startPos);
    }
    
    if (startPos < permisosStr.length()) {
        int number = stoi(permisosStr.substr(startPos));
        permisos.push_back(number);
    }

    // for (int num : permisos) {
    //     cout << num << " ";
    // }

    return permisos;
}

vector<int> permisosTxt(string nombre) {
    vector<int> numeros;
    
    ifstream archivo("permisos.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return numeros; // Devolver vector vacío en caso de error
    }
    
    string linea;
    while (getline(archivo, linea)) {
        size_t separador = linea.find(';');
        if (separador != string::npos) {
            string nombreEnArchivo = linea.substr(0, separador);
            if (nombreEnArchivo == nombre) {
                string numerosStr = linea.substr(separador + 1);
                size_t pos = 0;
                while ((pos = numerosStr.find(',')) != string::npos) {
                    numeros.push_back(stoi(numerosStr.substr(0, pos)));
                    numerosStr.erase(0, pos + 1);
                }
                numeros.push_back(stoi(numerosStr));
                break;
            }
        }
    }
    
    archivo.close();
    // for (int num : numeros) {
    //     cout << num << " ";
    // }
    return numeros;
}

void sumatoria(vector<int> v){
    int suma = 0;

    for (int num : v) {
        suma += num;
    }

    cout << "La suma de los elementos es: " << suma << endl;
    cout << endl;
}

void promedio(vector<int> v){
    int suma = 0;

    for(int num: v){ 
        suma += num;
    }

    cout << "El promedio de los elementos es: " << suma/v.size() << endl;
    cout << endl;
}

void moda(vector<int> v) {
    std::unordered_map<int, int> frequency;
    for (int num : v) {
        frequency[num]++;
    }

    int maxFrequency = 0;
    int moda = 0;

    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            moda = pair.first;
        }
    }

    cout << "La moda es " << moda << endl;
    cout << endl;
}

void contar(vector<int> v) {
    std::unordered_map<int, int> counts;

    for (int num : v) {
        counts[num]++;
    }

    for (const auto& pair : counts) {
        std::cout << "Cantidad de " << pair.first << ": " << pair.second << std::endl;
    }
    cout << endl;
}
