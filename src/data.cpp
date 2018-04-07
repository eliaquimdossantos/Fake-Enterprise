#include "data.h"

//Construtor
Data::Data(const short dia_, const short mes_, const short ano_){
	dia = dia_;
	mes = mes_;
	ano = ano_;
}

//Construtor padrão
Data::Data(){
	dia = 0;
	mes = 0;
	ano = 0;
}

//Destrutor da classe
Data::~Data(){

}

//Sobrecarga do operador >>
std::istream& operator>> (std::istream &i, Data &d){
	std::cout << "Ao inserir o campo solicitado, tecle ENTER." << std::endl;
	std::cout << "OBS: DATA NO FORMATO: DD" << std::endl;
	std::cout << "                      MM" << std::endl;
	std::cout << "                     AAAA" << std::endl;

	std::cout << "\tDia: ";
	i >> d.dia;
	std::cout << "\tMes: ";
	i >> d.mes;
	std::cout << "\tAno: ";
	i >> d.ano;
	std::cout << std::endl;

	return i; 
}

//Sobrecarga do operador <<
std::ostream& operator<< (std::ostream &o, Data d){
	o << d.dia << "/" << d.mes << "/" << d.ano << std::endl;
	return o;
}

bool operator== (Data a, Data b){
	return ((a.dia == b.dia) && (a.mes == b.mes) && (a.ano == b.ano));
}

//Cálculo de tempo decorrido
int Data::tempoDecorrido(Data agora){
	//x neste escopo representa o tempo decorrido
	int x = 0;

	//os "ifs" são usados para verificar se o resultado da subtração
	//é positivo ou não
	if((agora.dia - dia) >= 0)
		x = agora.dia - dia;
	else
		x = dia - agora.dia;

	if((agora.mes - mes) >= 0)
		x += 30*(agora.mes - mes);
	else
		x += 30*(mes - agora.mes);
	
	if((agora.ano - ano) >= 0)
		x += 365*(agora.ano - ano);
	else
		x += 365*(mes - agora.ano);

	return x;
}