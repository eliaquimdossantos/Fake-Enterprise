#ifndef RUN_H
#define RUN_H

#include "data.h"
#include "empresa.h"
#include "cadastro.h"
#include <iostream>

using namespace std;

class Run{
private:
	Cadastro * c = new Cadastro(); 		//objeto para cadastro de empresas, funcionarios, e outros objetos
	int op;								//variavel responsavel por obter a opcao no menu
public:
	void run();							//executa o menu com as opçoes disponiveis
	~Run();
};

#endif