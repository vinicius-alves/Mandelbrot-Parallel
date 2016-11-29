#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

// verifica se um dado ponto pertence ao conjunto de mandelbrot
bool verificarPonto(const float &x, const float &y){
	complex<float> z(0.0,0.0);
    complex<float> c(x,y);
    unsigned short cnt=0;
    while (cnt<300){
        z=z*z+c;
        cnt++;
        if (abs(z)>=4){
            return false;
        }
    }
    return true;
	
} 


int main(void){

float matriz[10][10][2];
bool results[10][10];

unsigned short i, j;

float x,y;

// gera uma matriz de pontos
#pragma omp parallel private(i,j) shared(matriz)
{
	#pragma omp for collapse(2)
	for(i=0;i<10;i++){
		for (j=0;j<10;j++){
			matriz[i][j][0]=i;
			matriz[i][j][1]=j;
		}
	}

	// calcula quais pontos da matriz anterior são do conjunto
	// e salva o resultado em uma matriz de booleans
	#pragma omp for collapse(2)
	for(i=0;i<10;i++){
		for (j=0;j<10;j++){
			x = matriz[i][j][0];
			y = matriz[i][j][1];
			if(verificarPonto(x,y)){
				results[i][j] = true;
			}
			else{
				results[i][j] = false;
			}
		}
	}

}



	return 0;
}