#include <fstream>
using namespace std;
struct Vas { int indice; Vas *urmatorul; };
struct ListaVase { Vas *primul, *ultimul; };
void adaugaLaInceputulListei(ListaVase &, int);
void adaugaLaSfarsitulListei(ListaVase &, int);
int main()
{
	ifstream citeste("vase.in");
	ofstream scrie("vase.out");
	ListaVase L;
	L.primul = 0;
	L.ultimul = 0;
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
			adaugaLaInceputulListei(L, culoare);
		}
		else
		{
			gradatieDreapta += volum[culoare];
			adaugaLaSfarsitulListei(L, culoare);
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
	for (Vas *v = L.primul; v; v = v->urmatorul)
    {
        gradatieStanga = gradatieDreapta;
		gradatieDreapta += volum[v->indice];
		if (v->indice == culoareCautata)
        {
            break;
        }
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
	    if (gradatieStanga < 0 && gradatieDreapta < 0)
        {
            scrie << gradatieStanga*(-1) << " S";
            scrie << gradatieDreapta*(-1) << " S\n";
        }
        else if (gradatieStanga > 0 && gradatieDreapta > 0)
        {
            scrie << gradatieDreapta << " D\n";
            scrie << gradatieStanga << " D";
        }
        else
        {
            scrie << gradatieStanga*(-1) << " S\n";
            scrie << gradatieDreapta << " D";
        }
	}
	scrie.close();
	return 0;
}
void adaugaLaInceputulListei(ListaVase & L, int indice)
{
    Vas *v = new Vas;
    v->indice = indice;
    v->urmatorul = 0;
    if (!L.primul)
    {
        L.primul = L.ultimul = v;
    }
    else
    {
        v->urmatorul = L.primul;
        L.primul = v;
    }
}
void adaugaLaSfarsitulListei(ListaVase & L, int indice)
{
    Vas *v = new Vas;
    v->indice = indice;
    v->urmatorul = 0;
    if (!L.ultimul)
    {
        L.primul = L.ultimul = v;
    }
    else
    {
        L.ultimul->urmatorul = v;
        L.ultimul = v;
    }
}
