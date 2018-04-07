#ifndef CADASTRO_H
#define CADASTRO_H

#include "empresa.h"
#include "data.h"
#include "funcionario.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Cadastro{
private:
	vector<Empresa*> e;	//vetor para objeto do empresa
	Funcionario * f; //ponteiro para objeto funcionario
	string nome1_;	//responsavel por armazenar o primeiro nome de um usuario
	string nome2_;	//responsavel por armazenar o segundo nome de um usuario
	string nome;	//responsavel por armazenar o nome de uma empresa ou funcionario
	long cnpj;		
	Data hoje; 		//armazena a data atual
	Data dataAdm;	//responsavel por armazenar a data de admissao de um funcionario
	float salario;	//responsavel por armazenar o salario de um funcionario

public:
	int end_empresa_existente(); //verifica se a empresa com determinado cnpj existe
	void cadastrarEmpresa();	
	void cadastrarFuncionario();
	void cadastrarDataAtual();
	void cadastrarAumentoSalarial(); 
	void listarEmpresas(); //lista as empresas cadastradas
	void listarFuncEmExp(); //lista os funcionarios de determinada empresa em periodo de experiencia
	void listarMediaFuncEmp(); //lista a media de funcionarios por empresa

	~Cadastro();
};

#endif