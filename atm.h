#pragma once
class atm
{
private:

public:
	int camada, numero_atomico, subnivel, eletrons_no_subnivel, numero_de_concluidos, soma_dos_eletrons, eletrons_no_ultimo_subnivel, maior_camada, maior_subnivel;
	//bool confirmados[7];
	atm(int a);
	void processo(int numero_atomico);
	int m(int e);
	void printar();
	void spin(int a);


};

