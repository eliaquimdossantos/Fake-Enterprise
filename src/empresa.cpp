#include "empresa.h"

using namespace std;

//Construtor da classe
Empresa::Empresa(string nomeEmpresa_, long cnpj_){
	nomeEmpresa = nomeEmpresa_;
	cnpj = cnpj_;
	total_func_empresa = 0; //registra o total de funcionarios desta empresa
	total_emp++; //registra o total de empresas;
}

//Destrutor da classe
Empresa::~Empresa(){}

void Empresa::setNome(string nomeEmpresa_){
	nomeEmpresa = nomeEmpresa_;
}
string Empresa::getNome(){
	return nomeEmpresa;
}
void Empresa::setCnpj(long cnpj_){
	cnpj = cnpj_;
}
long Empresa::getCnpj(){
	return cnpj;
}
int Empresa::getTotal_func_empresa(){
	return total_func_empresa;
}

//Método responsável por adicionar funcionários
void Empresa::addFuncionario(Funcionario* funcionario_){
	bool usuario_duplicado = false; //true se existir algum funcionario duplicado

	for(int i = 0; i < total_func_empresa; i++){ 
		if(*funcionario_ == *funcionarios[i]){
			usuario_duplicado = true;
			i = total_func_empresa;
			cout << "\n**************************************************************\n";
			cout << "ERRO: O funcionario que voce esta tentando adicionar ja \n";
			cout << "foi adicionado a esta empresa.";
			cout << "\n**************************************************************\n\n";
		}
	}
	if(!usuario_duplicado){
		Funcionario::addTotal_func(1);
		funcionarios.push_back(funcionario_); //adicionar o funcionário passado por referência ao
										  	  // final do vetor de funcionários	
		++total_func_empresa;
	}
}

void Empresa::listarFunc_per_exp(Data hoje){
	for(int i = 0; i < total_func_empresa; i++){
		if(funcionarios[i]->getDataAdm().tempoDecorrido(hoje) <= 90){
			cout << *funcionarios[i];
		}
	}
}

//Obter o vetor de funcionarios
vector<Funcionario*> Empresa::getFuncionarios(){
	return funcionarios;
}

void Empresa::aumentarSalarios(int porcentagem_){
	float newSalario; 

	for(int i = 0; i < total_func_empresa; i++){
		newSalario = funcionarios[i]->getSalario() + ((funcionarios[i]->getSalario()*porcentagem_)/100);
		funcionarios[i]->setSalario(newSalario);
	}
}

//Sobrecarga do opeardor <<
ostream& operator<< (ostream &o, Empresa e){
	o << "+++++++++++++++++++++++++++++++++++\n";
	o << "-Nome da Empresa: " << e.nomeEmpresa << endl << "-CNPJ: " << e.cnpj << endl 
	<< endl << "-Lista de funcionarios: " << endl << endl;
	
	for(int i = 0; i < e.total_func_empresa; i++){
		o <<*e.funcionarios[i];
	}
	o << "+++++++++++++++++++++++++++++++++++\n";
	return o;
}

int Empresa::getTotal_empresas(){
	return total_emp;
}

