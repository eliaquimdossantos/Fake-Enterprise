#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "data.h"
#include <string>

using namespace std;

class Funcionario{
private:
	string nome;
	string nome1;
	string nome2;

	float salario;
	Data dataAdm; //Data de admissão
	static int total_func;
public:
	Funcionario(string nome_, float salario_, Data dataAdm_);
	Funcionario();
	~Funcionario();
	void setNome(string nome1_, string nome2_);
	string getNome();
	void setSalario(float salario_);
	float getSalario();
	void setDataAdm(Data dataAdm_);
	Data getDataAdm();
	static void addTotal_func(const int n);
	static int getTotal_func();
	friend ostream& operator<< (ostream &o, Funcionario f);
	friend bool operator==(Funcionario f, Funcionario d);

};

#endif