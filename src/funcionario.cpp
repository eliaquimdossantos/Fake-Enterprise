#include "funcionario.h"
#include "data.h"

Funcionario::Funcionario(string nome_, float salario_, Data dataAdm_){
	nome = nome_;
	salario = salario_;
	dataAdm = dataAdm_;
}
Funcionario::Funcionario(){

}
Funcionario::~Funcionario(){

}
void Funcionario::setNome(string nome1_, string nome2_){
	nome = nome1_ + " " + nome2_;
}
string Funcionario::getNome(){
	return nome;
}
void Funcionario::setSalario(float salario_){
	salario = salario_;
}
float Funcionario::getSalario(){ 
	return salario;
}
void Funcionario::setDataAdm(Data dataAdm_){
	dataAdm = dataAdm_;
}
Data Funcionario::getDataAdm(){
	return dataAdm;
}
void Funcionario::addTotal_func(const int n_){
	total_func += n_;
}
int Funcionario::getTotal_func(){
	return total_func;
}
ostream& operator<< (ostream &o, Funcionario f){
	o << "------------------------------------" << endl;
	o << "	Nome: " << f.nome << endl;
	o << "	Salario: R$ " << f.salario << endl;
	o << "	Data de admissao: " << f.dataAdm ;
	o << "------------------------------------" << endl;
	o << endl;
	return o;
}

bool operator==(Funcionario f, Funcionario d) {
  return ((d.getNome() == f.getNome()) && (f.getSalario() == d.getSalario()) && (f.getDataAdm() == d.getDataAdm()));
}