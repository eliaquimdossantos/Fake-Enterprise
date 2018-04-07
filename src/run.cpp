#include "run.h"

void Run::run(){
	
	c->cadastrarDataAtual();

	do{
		cout << "#########################################################################\n";
		cout << "# (1) - Cadastrar empresa                                               #\n";
		cout << "# (2) - Cadastrar funcionario                                           #\n";
		cout << "# ----------------------------------------------------------------------#\n";
		cout << "# (3) - Aumentar os salarios dos funcionarios em x%                     #\n";
		cout << "# ----------------------------------------------------------------------#\n";
		cout << "# (4) - Listar funcionarios em periodo de experiencia                   #\n";
		cout << "# (5) - Listar media de funcionarios por empresa                        #\n";
		cout << "# (6) - LISTAR TODAS AS EMPRESAS                                        #\n";
		cout << "#                                                                       #\n";
		cout << "# (7) - Sair do programa                                                #\n";
		cout << "#########################################################################\n";
		cout << "		";
		cin >> op;
		if(op!= 1 && op != 2 && op != 3 && op != 4 && op !=5 && op!=6 && op!=7){
			cout << "\n****************";
			cout << "\nOPCAO INVALIDA\n";
			cout << "****************\n";
			op = 7;
		}else{
			switch (op){
				case 1:
					c->cadastrarEmpresa();
				break;

				case 2:
					c->cadastrarFuncionario(); 
				break;
				case 3:
					c->cadastrarAumentoSalarial(); //reponsavel por aumentar uma determinada porcentagem nos salarios
				break;
				case 4:
					c->listarFuncEmExp(); //lista de funcionarios em periodo de experiencia
				break;
				case 5:
					c->listarMediaFuncEmp(); //exibe a media de funcionarios por empresa
				break;
				case 6:
					//exibe todas as empresas com seus respectivos funcionarios registrados
					c->listarEmpresas();
				break;
				case 7:
					cout << endl << "Saindo..." << endl;
				break;
			}
		}

	}while(op != 7);
}

Run::~Run(){

}