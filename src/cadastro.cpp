#include "cadastro.h"

int Cadastro::end_empresa_existente(){
	bool encontrar = false;	//true quando o cnpj informado é encontrado
	int aux = Empresa::getTotal_empresas(); //informa a quantidade de empresas cadastradas
	int i = 0;
	cout << "	Por favor informe o CNPJ da empresa desejada: " << endl;
	cout << "		";
	cin >> cnpj;

	while(!encontrar && (i < aux)){
		if(e[i]->getCnpj() == cnpj){ //verifica se existe uma empresa cadastrada com o cnpj passado
			encontrar = true;
			return i;
		}else if(i == aux-1){
			cout << "\n**************************************************************\n";
			cout << "ERRO: Nao existe uma empresa cadastrada com o CNPJ informado!";
			cout << "\n**************************************************************\n";
			return aux; //retorna o valor de aux para que quando essa "aux" apareça nos ifs
						//de outros métodos, a condição testada seja falsa, informando que
						//não possui uma empresa com o cnpj informado.
		}	
		++i;
	}
	return aux; //nunca chega aqui
}

void Cadastro::cadastrarEmpresa(){
	bool empresa_duplicada = false; //true quando existe alguma empresa duplicada

	cout << "	Por favor informe o nome da empresa a ser cadastrada: " << endl;
	cout << "		";
	cin.ignore();
	getline(cin, nome);
	cout << "	...agora informe o CNPJ da empresa a ser cadastrada: " << endl;
	cout << "		";
	cin >> cnpj;

	for(int i = 0; i < Empresa::getTotal_empresas(); i++){
		if(e[i]->getCnpj() == cnpj){
			cout << "\n**************************************************************\n";
			cout << "ERRO: Ja existe uma empresa cadastrada com o" << endl << "CNPJ informado!";
			cout << "\n**************************************************************\n";
			empresa_duplicada = true;
		}
	}
	if(!empresa_duplicada)
		e.push_back(new Empresa(nome, cnpj)); //se nao existe duplicaçao, entao uma nova empresa
											  //sera criada

}

void Cadastro::cadastrarFuncionario(){
	int aux = end_empresa_existente(); //aux recebe o contador na posicao da empresa encontrada (se encontrada)
									   //com as informacoes passadas pelo usuario

	if(aux < Empresa::getTotal_empresas()){
		cout << "	Por favor informe o primeiro nome do funcionario: " << endl;
		cout << "		";
		cin.ignore();
		getline(cin, nome1_);
		cout << "	Por favor informe o segundo nome do funcionario: " << endl;
		cout << "		";
		getline(cin, nome2_);
		nome = nome1_ + " " + nome2_; //concatenaçao do nome e sobrenome
		cout << "	...agora informe a data de admissao do funcionario: " << endl;
		cin >> dataAdm;
		cout << "	e por fim, o salario: " << endl;
		cout << "		";
		cin >> salario;

		f = new Funcionario(nome, salario, dataAdm); //cria um novo funcionario com as informaçoes passadas

		e[aux]->addFuncionario(f); //adiciona o funcionado passado para a empresa de cnpj
	}
}

void Cadastro::cadastrarDataAtual(){
	cout << endl;
	cout << "Ola!!! Por favor ajuste a data atual:" << endl;
	cin >> hoje;

	cout << endl << endl;
	cout << "POR FAVOR SELECIONE UMA DAS OPCOES:\n";
	cout << "Dica: Selecione a opcao desejada teclando o numero a esquerda da \n";
	cout << "opcao e em seguida tecle ENTER.\n\n";
}

void Cadastro::cadastrarAumentoSalarial(){
	int aux = end_empresa_existente(); //aux recebe o contador na posicao da empresa encontrada (se encontrada)
									   //com as informacoes passadas pelo usuario
	int porcentagem = 0;
	if(aux < Empresa::getTotal_empresas()){
		cout << "	Por favor informe a porcentagem de aumento desejada:" << endl;
		cout << "		";
		cin >> porcentagem;
			
			e[aux]->aumentarSalarios(porcentagem); //aumenta todos os salarios de uma determinada empresa
	}
}

void Cadastro::listarEmpresas(){
	vector<Empresa*>::iterator it; //iterador para o vector de empresas

	for(it=e.begin(); it != e.end(); it++){
		cout << *(*it);
	}
}

void Cadastro::listarFuncEmExp(){
	int aux = end_empresa_existente(); //aux recebe o contador na posicao da empresa encontrada (se encontrada)
									   //com as informacoes passadas pelo usuario
	if(aux < Empresa::getTotal_empresas()){
		e[aux]->listarFunc_per_exp(hoje); //reponsavel por listar os usuarios em periodo de experiencia
	}
}

void Cadastro::listarMediaFuncEmp(){
	float media_func_emp = (float)Funcionario::getTotal_func()/Empresa::getTotal_empresas();
	cout << endl;
	cout << "	Quantidade de funcionarios cadastrados: = ";
	cout << Funcionario::getTotal_func() << endl;
	cout << "	---------------------------------------  --- = ";
	cout << media_func_emp << endl;
	cout << "  	  Quantidade de empresas cadastradas:   = ";
	cout << Empresa::getTotal_empresas()  << endl << endl;
}

Cadastro::~Cadastro(){
	
}
