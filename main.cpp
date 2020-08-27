#include <iostream>
#include <fstream>
using namespace std;

ofstream archivo;

void interpolacion ();

int main() {
  string nombre;
  cout << "Ingrese el nombre del archivo: ";
  getline(cin, nombre);
  archivo.open(nombre.c_str(), ios::app);
  interpolacion ();
  return 0;
}

void interpolacion (){
  int A[7] = {1, 2, 3, 4, 5, 6, 7};
  int primero = 0;
  int ultimo = 7-1;
  int medio;
  int n = 5;
  int contador = 0;

  while(A[primero] != n & contador < 7){
    medio = primero + ((n-A[primero])* (ultimo-primero)) / (A[ultimo] - A[primero]);

    if (A[medio]<n){
      ultimo = medio + 1;
    }
    else if (A[medio] >n){
      ultimo = medio - 1;
    }
    else{
      primero = medio;
    }
    contador++;
    break;
  }

  if (A[primero] == n){
    cout << "Elemento encontrado en la posición: " << primero << endl;
    archivo << "Elemento encontrado en la posición: " << primero << endl;
  }
  else {
    cout << "Elemento no encontrado" << endl;
    archivo << "Elemento no encontrado" << endl;
  }
}