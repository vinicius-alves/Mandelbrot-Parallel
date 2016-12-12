#include <iostream>
#include <complex>
#include <cmath>
#include <string>
#include <fstream>
#include <omp.h>
#define PASSO 0.005

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

	register const unsigned short dimensao_x= 3/PASSO;
	register const unsigned short dimensao_y= 1/PASSO;

	cout<<"Programa iniciado com "<<dimensao_x*dimensao_y << " pontos"<<endl;

	float matriz[dimensao_x][dimensao_y][3];
	//bool results[dimensao_x][dimensao_y];

	unsigned int i, j;

	register float x,y,d;
	string json="";//"{";
	string meta = "";
	string tempx, tempy,tempd;

	ofstream out;
	out.open("data.csv");
	unsigned short rank;

	// gera uma matriz de pontos
	#pragma omp parallel private(rank,x,y,d,tempx,tempy,tempd,i,j) firstprivate(meta) shared(matriz,json)
	{
		rank = omp_get_thread_num();
		

		#pragma omp for collapse(2)
		for(i=0;i<dimensao_x;i++){
			for (j=0;j<dimensao_y;j++){
				matriz[i][j][0]=i*PASSO-2;
				matriz[i][j][1]=j*PASSO-0;	

			}
		}

		// calcula quais pontos da matriz anterior são do conjunto
		#pragma omp for collapse(2) nowait
		for(i=0;i<dimensao_x;i++){
			for (j=0;j<dimensao_y;j++){
				
				x = matriz[i][j][0];
				y = matriz[i][j][1];
				verificarPonto(x,y,matriz[i][j][2]);
				d = matriz[i][j][2];
				tempx = to_string(x).substr(0,6);
				tempy = to_string(y).substr(0,6);
				tempd = to_string(d).substr(0,5);
				
				//meta+="{"+tempx+","+tempy+","+tempd+"},";
				if(verificarPonto(x,y,matriz[i][j][2])){
					meta+= tempx +" "+ tempy+" \n";

				}
				
			
			}
		}

		#pragma omp critical
		{
			//cout<<"thread "<<rank<<", meta :\n"<<meta<<endl;
			json +=meta;
		}

	}
	//json.pop_back();

	out << json;//<<"};";
	out.close();

		return 0;
}