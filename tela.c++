//Lomas Castillo Uriel
//Hernandez Zamora Alejandro
//Maldonado Romero Daniel

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class figura {
public:

    virtual bool esp_disp(int x, int y, vector<vector<figura* > >& superficie) = 0;
    virtual void ubicacion(int x, int y, vector<vector<figura* > >& superficie) = 0;
   
};

class cuadrado : public figura {
public:
    int size;
   
    cuadrado(int size) {
        this->size = size;
    }

    bool esp_disp(int x, int y, vector<vector<figura* > >& superficie) override {
        int ancho = superficie.size();
        int altura = superficie[0].size();
       
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (x + i >= ancho || y + j >= altura || superficie[x + i][y + j] != nullptr) {
                    return false;
                }
            }
        }       
        return true;
    }
   
void ubicacion(int x, int y, vector<vector<figura* > >& superficie) override {      
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {            
                superficie[x + i][y + j] = this;
            }
        }
    }
};

class rectangulo : public figura {
public:
    int ancho;
    int altura;

    rectangulo(int ancho, int altura) {
        this->ancho = ancho;
        this->altura = altura;
    }
   
    bool esp_disp(int x, int y, vector<vector<figura* > >& superficie) override {
        int superficie_ancho = superficie.size();
        int superficie_altura = superficie[0].size();
    
        for (int i = 0; i < ancho; ++i) {
            for (int j = 0; j < altura; ++j) {            
                if (x + i >= superficie_ancho || y + j >= superficie_altura || superficie[x + i][y + j] != nullptr) {
                    return false;
                }
            }
        }
        return true;
    }

   
void ubicacion(int x, int y, vector<vector<figura* > >& superficie) override {     
        for (int i = 0; i < ancho; ++i) {
            for (int j = 0; j < altura; ++j) {             
                superficie[x + i][y + j] = this;
            }
        }
    }
};

class circulo : public figura {
public:
    int radio;
   
    circulo(int radio) {
        this->radio = radio;
    }
   
    bool esp_disp(int x, int y, vector<vector<figura* > >& superficie) override {
        int superficie_ancho = superficie.size();
        int superficie_altura = superficie[0].size();
        int r_cuadradod = radio * radio;
       
        for (int i = -radio; i <= radio; ++i) {
            for (int j = -radio; j <= radio; ++j) {
                int cordenada_x = x + i;
                int cordenada_y = y + j;              
                if (i * i + j * j <= r_cuadradod) {              
                    if(cordenada_x < 0 || cordenada_x >= superficie_ancho || cordenada_y < 0 || cordenada_y >= superficie_altura || superficie[cordenada_x][cordenada_y] != nullptr) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
   
    void ubicacion(int x, int y, vector<vector<figura* > >& superficie) override {
        int r_cuadradod = radio * radio;     
        for (int i = -radio; i <= radio; ++i) {
            for (int j = -radio; j <= radio; ++j) {             
                if (i * i + j * j <= r_cuadradod) {                  
                    superficie[x + i][y + j] = this;
                }
            }
        }
    }
};    

class triangulo : public figura {
public:
    int base;
   
    triangulo(int base) {
        this->base = base;
    }
   
    bool esp_disp(int x, int y, vector<vector<figura* > >& superficie) override {
        int superficie_ancho = superficie.size();
        int superficie_altura = superficie[0].size();
       
        for (int i = 0; i < base; ++i) {
            for (int j = 0; j <= i; ++j) {
                int cordenada_x = x + i;
                int cordenada_y = y + base / 2 - i / 2 + j;
              
                if (cordenada_x < 0 || cordenada_x >= superficie_ancho || cordenada_y < 0 || cordenada_y >= superficie_altura || superficie[cordenada_x][cordenada_y] != nullptr) {
                    return false;
                }
            }
        }
        return true;
    }
   
void ubicacion(int x, int y, vector<vector<figura* > >& superficie) override {   
        for (int i = 0; i < base; ++i) {
            for (int j = 0; j <= i; ++j) {
                superficie[x + i][y + base / 2 - i / 2 + j] = this;
            }
        }
    }
};




class telar {
public:
   
    int ancho;
    int altura;
 
    vector<vector<figura* > > superficie;
   
    telar(int ancho, int altura) {
        this->ancho = ancho;
        this->altura = altura;
        this->superficie = vector<vector<figura*> >(ancho, vector<figura*>(altura, nullptr));
    }
   
    bool añadir(figura* figura) {
        for (int i = 0; i < ancho; ++i) {
            for (int j = 0; j < altura; ++j) {              
                if (figura->esp_disp(i, j, superficie)) {
                    figura->ubicacion(i, j, superficie);                 
                    return true;
                }
            }
        }     
        return false;
    }

void print() {     
        for (int i = 0; i < ancho; ++i) {
            for (int j = 0; j < altura; ++j) {               
                cout << (superficie[i][j] == nullptr ? '-' : 'o');
            }           
            cout << '\n';
        }
    }
};

int main() {
    int anchotel, alturatel, lim;
    cout << "\nIngrese el ancho y la altura de la tela (Ejemplo: x y): ";
    cin >> anchotel >> alturatel;
    telar tela(anchotel, alturatel);

    ifstream archivo("Figuras.txt");
    figura* figura;
    lim = 0;
    while(!archivo.eof()){
        int size, base, ancho, altura;
        string fig;
        getline(archivo, fig); cout<< endl;
        if(fig == "Cuad"|| fig == "cuad"){
            archivo >> size;
            cout<< endl;
            figura = new cuadrado(size);
        }
        if(fig == "Rect"|| fig == "rect"){
            archivo >> altura;
            cout<< endl;
            archivo >> ancho;
            cout<< endl;
            figura = new rectangulo(ancho, altura);
        }
        if(fig == "Circ"|| fig == "circ"){
            archivo >> size;
            cout<< endl;
            figura = new circulo(size);
        }
        if(fig == "Tri"|| fig == "tri"){
            archivo >> base;
            cout<< endl;
            figura = new triangulo(base);
        }
        if (!tela.añadir(figura)) {
            delete figura;
            cout << "No se pudo agregar la figura. Se terminara la tela o no alcanza.\n";
            break;
        }
    }
    tela.print();  
    return 0;
}