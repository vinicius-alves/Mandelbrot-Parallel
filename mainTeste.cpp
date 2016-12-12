#include "teste.cpp"
#include <iostream>

//Declaração Vairável Externa
extern float matriz[10000][3];

int main(){

	std::cout<<"Coordenada X: "<<matriz[9999][0]<<std::endl;
	std::cout<<"Coordenada Y: "<<matriz[9999][1]<<std::endl;
	std::cout<<"Coordenada D: "<<matriz[9999][2]<<std::endl;

	return 0;

}