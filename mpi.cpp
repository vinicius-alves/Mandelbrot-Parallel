#include <iostream>
#include <complex>
#include <cmath>
#include <string>
#define PASSO 0.01

using namespace std;

// verifica se um dado ponto pertence ao conjunto de mandelbrot
inline bool verificarPonto(const float &x, const float &y, float &cnt){
	complex<float> z(0.0,0.0);
    complex<float> c(x,y);
    for (cnt =0; cnt<300;cnt++){
        z=z*z+c;
        if (abs(z)>=4){
            return false;
        }
    }
    return true;
	
} 


int main(void){

register unsigned short dimensao_x= 1/PASSO;
register unsigned short dimensao_y= 1/PASSO;

float matriz[dimensao_x][dimensao_y][3];
bool results[dimensao_x][dimensao_y];

unsigned short i, j;
unsigned short a=0;

float x,y,d;
string json="{";
string tempx, tempy,tempd;

// gera uma matriz de pontos
#pragma omp parallel private(i,j) shared(results,matriz)
{
	#pragma omp for collapse(2)
	for(i=0;i<dimensao_x;i++){
		for (j=0;j<dimensao_y;j++){
			matriz[i][j][0]=i*PASSO-0;
			matriz[i][j][1]=j*PASSO-0;
		}
	}

	// calcula quais pontos da matriz anterior são do conjunto
	// e salva o resultado em uma matriz de booleans
	#pragma omp for collapse(2) 
	for(i=0;i<dimensao_x;i++){
		for (j=0;j<dimensao_y;j++){
			verificarPonto(x,y,matriz[i][j][2]);
			x = matriz[i][j][0];
			y = matriz[i][j][1];
			//cout<<"("<<x<<","<<y<<")"<<endl;
				d = matriz[i][j][2];
				//cout<<"("<<x<<","<<y<<")"<<endl;
				//cout<<x<<endl;
				//cout<<y<<endl;
				a++;
				tempx = to_string(x).substr(0,4);
				tempy = to_string(y).substr(0,4);
				tempd = to_string(d).substr(0,5);
				json+="{"+tempx+","+tempy+","+tempd+"},";
			if(verificarPonto(x,y,matriz[i][j][2])){
				results[i][j] = true;

			}
			else{
				results[i][j] = false;
			}
		}
	}
	json+="};";
		cout << json <<endl;
		cout<<a<<" pontos"<<endl;


}



	return 0;
}