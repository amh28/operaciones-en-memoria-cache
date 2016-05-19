#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

//IMPRIME LOS VALORES DE LA MATRIZ
void print(VVI &mat)
{
	for(auto i:mat)	
	{
		for(auto j:i)
		cout<<j<<" ";
	cout<<endl;
	}
}

//ENCUENTRA EL MINIMO ENTRE DOS NUMEROS
int findMin(int a , int b)
{
	return a<b?a:b;	
}

//GENERA UNA MATRIZ CUADRADA DE TAMANO SIZE
VVI gen_square_matrix(int size)
{
	VVI matrix(size,VI(size));
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			matrix[i][j]= i*size+j+1;
	return matrix;
	
}

//GENERA UNA MATRIZ DE DIMENSIONES F Y C
VVI gen_matrix(int f, int c)
{
	VVI matrix(f,VI(c));
	for(int i=0;i<f;i++)
		for(int j=0;j<c;j++)
			matrix[i][j]= i*f+j+1;
	return matrix;
	
}


//MULTIPLICACION DE MATRICES(3 BUCLES) BAJO EL ENFOQUE FILA-COLUMNA
VVI mult_naive_filcol(VVI A, VVI B)
{
	int f1=A.size(), c=A[0].size(), c2=B[0].size();
	VVI rslt(f1,VI(c2));
	for(int i=0;i<f1;i++)	
		for(int j=0;j<c2;j++)
		{
			int sum=0;
			for(int k=0;k<c;k++)			
				sum+=A[i][k]*B[k][j];
			
			rslt[i][j]=sum;
		}			
	return rslt;	
}



//MULTIPLICACION DE MATRICES(3 BUCLES) BAJO EL ENFOQUE COLUMNA-FILA
VVI mult_naive_colfil(VVI A, VVI B)
{
	int f1=A.size(), c=A[0].size(), c2=B[0].size();
	VVI rslt(f1,VI(c2));
	for(int i=0;i<c2;i++)	
		for(int j=0;j<f1;j++)
		{
			int sum=0;
			for(int k=0;k<c;k++)			
				sum+=A[k][i]*B[j][k];
			
			rslt[j][i]=sum;
		}			
	return rslt;	
}


//MULTIPLICACION DE DOS MATRICES CUADRADAS(6 BUCLES) CON PARTICIONAMIENTO
VVI mult_block(VVI &A, VVI &B, int &b)
{
	int size=A.size(); 
	VVI rslt(size,VI(size));
	
	for(int i0=0;i0<size;i0+=b)
		for(int j0=0;j0<size;j0+=b)
			for(int k0=0;k0<size;k0+=b)
				for(int i=i0;i<findMin(i0+b,size);i++)					
					for(int j=j0;j<findMin(j0+b,size);j++)
					{
						int sum=0;
						for(int k=k0;k<findMin(k0+b,size);k++)			
						sum+=A[i][k]*B[k][j];			
						rslt[i][j]+=sum;
					}				
					
	return rslt;
	
}


//SUMA DE MATRICES BAJO EL ENFOQUE COLUMNA-FILA
VVI sum_colfil(VVI A, VVI B)
{

	int size=A.size(); 
	VVI rslt(size,VI(size));

	for(int i=0;i<size;i++)	
		for(int j=0;j<size;j++)
			rslt[j][i]=A[j][i]+B[j][i];
	return rslt;
	
}


//SUMA DE MATRICES BAJO EL ENFOQUE FILA-COLUMNA
VVI sum_filcol(VVI A, VVI B)
{

	int size=A.size(); 
	VVI rslt(size,VI(size));
	
	for(int i=0;i<size;i++)	
		for(int j=0;j<size;j++)
			rslt[i][j]=A[i][j]+B[i][j];
	return rslt;
	
}


int main()
{
VVI A,B,rslt;	A=B=gen_square_matrix(1000);
int block=500;

//MULTIPLICACION POR BLOQUES
//rslt=mult_block(A,B,block);

//MULTIPLICACION NAIVE FILA-COLUMNA
//rslt=mult_naive_filcol(A,B);


//MULTIPLICACION NAIVE COLUMNA-FILA
//rslt = mult_naive_colfil(A,B);

//SUMA FILA-COLUMNA
rslt=sum_filcol(A,B);

//SUMA COLUMNA-FILA
//rslt=sum_colfil(A,B);


//cout<<"Result"<<endl; print(rslt);
return 0;	
	
}

