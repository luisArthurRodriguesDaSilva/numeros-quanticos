//atm.cpp
#include "atm.h"
#include <iostream>
using namespace std;

atm::atm(int a)
{
	numero_atomico = a;
	processo(numero_atomico);
	printar();
	cout << "_____________" << endl;
}

void atm::processo(int numero_atomico)
{
	camada = 1;
	maior_camada = 0;
	subnivel = 0;
	soma_dos_eletrons = 0;
	numero_de_concluidos = 0;

	for (
		camada = 1, subnivel = numero_de_concluidos;
		soma_dos_eletrons < numero_atomico;
		camada++, subnivel--
		) {
		if (subnivel >= 0) {
			for (
				int i = 0;
				i < (subnivel * 4) + 2 &&
				(subnivel < camada) &&
				(soma_dos_eletrons < numero_atomico);
				i++
				)
			{
				soma_dos_eletrons++;
				eletrons_no_subnivel = i + 1;
				//cout << "___-entrou no for___";
			}
			maior_camada = (camada > maior_camada) ? camada : maior_camada;

		}
		else
		{
			numero_de_concluidos++;
			subnivel = numero_de_concluidos;
			camada = 1;
		}
		/*cout <<" soma_dos_eletrons"<< soma_dos_eletrons << endl
			<< "nc"<<numero_de_concluidos << endl
			<< "camada"<<camada << endl <<
			"sub:"<<subnivel<<endl<<
			"e no sub"<<eletrons_no_subnivel<<
			"_____"<<endl;*/
	}
	// cout << ++subnivel << "____________fim" << endl; 
}

int atm::m(int e)
{
	int descarte = e % ((subnivel * 2) + 1);
	int m = -subnivel;
	int i = 1;

	/*	cout << m<< endl;
		cout<< descarte<<endl;
		cout<<i<<endl;*/

		//cout<<"enreou"<<endl;
	if (descarte == 0) m = subnivel;
	else {
		while (i < descarte) {
			m++;
			i++;
			/*cout << m++ << endl;
			cout<< descarte<<endl;
			cout<<i++<<endl;*/
		}
	}
	return m;
}

/*m(int e) {
int descarte=e%((subnivel*2)+1);
int m=-subnivel;
while(int i=1<descarte) {m++;i++;}
return m;
}
*/
void atm::printar()
{
	cout << "valencia:" << maior_camada << endl;
	cout << "n: " << camada - 1 << endl;
	cout << "l: " << ++subnivel << endl;
	cout << "e no sub" << eletrons_no_subnivel << endl;
	cout << "m:" << m(eletrons_no_subnivel) << endl;
	spin(eletrons_no_subnivel);
}

void atm::spin(int a)
{
	//processo();
	if (a <= (subnivel * 2) + 1)
		cout << "+1/2" << endl;
	else cout << "-1/2" << endl;
}