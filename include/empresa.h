#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"
#include <iostream>
#include <vector>
#include <string>

class Empresa{
private:
	string nomeEmpresa;
	long cnpj;
	int total_func_empresa;
	vector<Funcionario*> funcionarios;
	static int total_emp;
public:
	Empresa(string nomeEmpresa_, long cnpj_);
	~Empresa();
	void setNome(string nomeEmpresa_);
	string getNome();
	void setCnpj(long cnpj_);
	long getCnpj();
	int getTotal_func_empresa();
	void addFuncionario(Funcionario* funcionario_);
	void aumentarSalarios(int porcentagem_);
	void listarFunc_per_exp(Data hoje);
	vector<Funcionario*> getFuncionarios();
	friend ostream& operator<< (ostream &o, Empresa e);
	static int getTotal_empresas();
};

#endif