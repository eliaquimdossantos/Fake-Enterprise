#include <iostream>

#include "run.h"

int Funcionario::total_func = 0;
int Empresa::total_emp = 0;

int main(){
	Run * executar = new Run();

	executar->run();

	return 0;
}