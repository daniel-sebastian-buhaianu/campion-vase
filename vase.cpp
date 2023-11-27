#include <fstream>
using namespace std;
int main()
{
	ifstream citeste("vase.in");
	ofstream scrie("vase.out");
	int nrVase;
	citeste >> nrVase;
	long long
		volum[nrVase],
		gradatieStanga = 0,
		gradatieDreapta = 0;
	int culoare;
	for (culoare = 0; culoare < nrVase; culoare++)
	{
		citeste >> volum[culoare];
		char ramura;
		citeste >> ramura;
		if (ramura == 'S')
		{
			gradatieStanga += volum[culoare];
		}
		else
		{
			gradatieDreapta += volum[culoare];
		}
		gradatieStanga = gradatieDreapta
		= (gradatieStanga + gradatieDreapta)/2;
	}
	int culoareCautata;
	citeste >> culoareCautata;
	culoareCautata--; // am retinut indicii de la 0
	citeste.close();
	scrie << gradatieStanga << endl; // gradatia maxima
	gradatieDreapta *= -1;
	for (culoare = nrVase-1;
	     culoare >= culoareCautata; culoare--)
	{
		gradatieStanga = gradatieDreapta;
		gradatieDreapta += volum[culoare];
	}
	if (gradatieStanga == 0 || gradatieDreapta == 0)
	{
		if (gradatieDreapta == 0)
		{
			scrie << gradatieStanga*(-1);
			scrie << " S\n0 S";
		}
		else
		{
			scrie << gradatieDreapta;
			scrie << " D\n0 D";
		}
	}
	else
	{
		scrie << gradatieStanga*(-1) << " S\n";
		scrie << gradatieDreapta << " D";
	}
	scrie.close();
	return 0;
}
