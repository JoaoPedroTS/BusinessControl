//#include "cliente.hpp"
//#include "item.hpp"
#include "pedido.hpp"
//Verificar onde já foram usados emchecar a necessidade de incluir novamente
#include <vector>
#include <iostream>
#include <fstream>


//Cadastrar
bool cadastrarCliente(vector<Cliente> &ClientList, string n, string f);
bool cadastrarItem(vector<Item> &listaItem, string n, double p);
bool cadastrarPedido(vector<Pedido> &listaPedido, vector<Cliente> &ClientList, vector<Item> &listaItem,  size_t id_cli, size_t id_it);

//Buscar substring no vector;
bool searchSubstring(vector<Item> &listaItem, string substr);
bool searchSubstring(vector<Cliente> &ClientList, string substr);

//Atualizar
bool updateDadoIt(vector<Item> &listaItem, size_t id);
bool updateDadoCli(vector<Cliente> &ClientList, size_t id); 

//Remover
bool removeItem(vector<Item> &listaItem, vector<Pedido> &listaPedido, size_t id);
bool removeCliente(vector<Cliente> &ClientList, vector<Pedido> &listaPedido, size_t id);

//Verifica uso
bool checkUse(vector<Pedido> &listaPedido, size_t id, size_t tipo);

//SalvaDB
bool saveDbClient(vector<Cliente> &ClientList);
bool saveDbItem(vector<Item> &listaItem);
bool saveDbPedido(vector<Pedido> &listaPedido);

//Relatorios
void itCadastrados(vector<Item> &listaItem);
void cliCadastrados(vector<Cliente> &ClientList);
void pedCadastrados(vector<Pedido> &listaPedido);


main(){
	
	vector<Cliente> ClientList;
	vector<Item> listItems;
	vector<Pedido> listPedidos;
	
	for(;;){
		
		
		cout << "-----------------------------" << endl;
		cout << "Sistema de Gestao de Negocios" << endl;
		cout << "1 - Gerir Cliente" << endl;
		cout << "2 - Gerir Item" << endl;
		cout << "3 - Gerir Pedido" << endl;
		cout << "4 - Emite relatorio" << endl;
		cout << "5 - Sair e salvar dados no BD" << endl;
		cout << "-----------------------------" << endl;
		char opt;
		cin >> opt;

		if (opt == '1'){ // Joao Pedro - Cliente
		    cout << "-----------------------------" << endl;
			cout << "1 - Cadastrar novo cliente" << endl;
			cout << "2 - Atualizar dado de cliente" << endl;
			cout << "3 - Remover cliente " << endl;
			cout << "-----------------------------" << endl;
			cin >> opt;
			
			if (opt == '1'){
				cout << "insira o nome do novo cliente" << endl;
				string tempNome;
				cin >> tempNome;
				cout << "Insira a funcao desse novo cliente" << endl;
				string tempFuncao;
				cin >> tempFuncao;

				bool conf;
				conf = cadastrarCliente(ClientList, tempNome, tempFuncao);

				if(conf){
					cout << "Cliente cadastrado" << endl;
				}else{
					cout << "Cliente nao foi cadastrado" << endl;
				}
			}
			if (opt == '2'){
				cout << "Digite o nome do cliente que deseja atualizar" << endl;
				string substr;
				cin >> substr;

				bool conf;
				conf = searchSubstring(ClientList, substr);

				if (conf){
					cout << "Informe o id do cliente que deseja atualizar" << endl;
					size_t tempId;
					cin >> tempId;
					conf = updateDadoCli(ClientList, tempId);
					
					if(conf){
						cout << "Cliente atualizado" << endl;
					} else {
						cout << "Cliente nao foi atualizado" << endl;
					}
					
				} else {
					cout << "Cliente não encontrado! Verifique o nome do cliente" << endl;
				}				
			}
			if (opt == '3'){
				cout << "Digite o nome do cliente que deseja remover" << endl;
				string substr;
				cin >> substr;

				bool conf;
				conf = searchSubstring(ClientList, substr);
				
				if (conf){
					cout << "Qual cliente deseja remover? Digite o Id" << endl;
					size_t id;
					cin >> id;
					conf = removeCliente(ClientList, listPedidos, id);
					if(conf){
						cout << "Cliente removido!" << endl;
					} else {
						cout << "Cliente nao pode ser removido" << endl;
					}
				}else{
					cout << "Item nao encontrado! Verifique o nome do produto" << endl;
				}
			}
			
			continue;
		}
		if (opt == '2'){ // Samady Corrêa - Item
			cout << "-----------------------------" << endl;
			cout << "1 - Cadastrar item " << endl;
			cout << "2 - Atualizar item" << endl;
			cout << "3 - Remover item " << endl;
			cout << "-----------------------------" << endl;
			cin >> opt;
			
			if ( opt == '1'){
				cout << "Insira o nome do Item" << endl;
				string nome_temp;
				//cin >> nome_temp;
				getline(cin, nome_temp);
				cin >> nome_temp;
				cout << "Insira o preco do Item" << endl;
				double preco_temp;
				cin >> preco_temp;
				
				bool deuBom;
				deuBom = cadastrarItem(listItems, nome_temp, preco_temp);
				
				if(deuBom){
					cout << "Item cadastrado" << endl;
				}else{
					cout << "Item nao foi cadastrado" << endl;
				}
			}
			if (opt == '2'){
				cout << "Digite o nome do item que voce deseja atualizar: " << endl;
				string substr;
				cin >> substr;
				
				bool deuBom;
				deuBom = searchSubstring(listItems,substr);
				
				if (deuBom){
					cout << "Qual item deseja atualizar? Digite o Id" << endl;
					size_t id;
					cin >> id;
					deuBom = updateDadoIt(listItems, id);
					
					if(deuBom){
						cout << "Item atualizado" << endl;
					} else {
						cout << "Item nao foi atualizado" << endl;
					}
					
				}else{
					cout << "Item nao encontrado! Verifique o nome do produto" << endl;
				}
			}
			
			if (opt == '3'){
				cout << "Digite o nome do item que voce deseja remover: " << endl;
				string substr;
				cin >> substr;
				
				bool deuBom;
				deuBom = searchSubstring(listItems,substr);
				
				if (deuBom){
					cout << "Qual item deseja remover? Digite o Id" << endl;
					size_t id;
					cin >> id;
					deuBom = removeItem(listItems, listPedidos, id);
					if(deuBom){
						cout << "Item removido!" << endl;
					} else {
						cout << "Item nao pode ser removido" << endl;
					}
				}else{
					cout << "Item nao encontrado! Verifique o nome do produto" << endl;
				}
			}
			
			continue;
		}
		if (opt == '3'){
			cout << "-----------------------------" << endl;
			cout << "1 - Lancar Pedido" << endl;
			cout << "2 - Corrigir pedido" << endl;
			cout << "3 - Buscar Pedido" << endl;
			cout << "4 - Recibo" << endl;
			cout << "-----------------------------" << endl;
			
			cin >> opt;
			
			if (opt == '1'){
				cout << "Escolha um cliente. Digite o Id" << endl;
				cliCadastrados(ClientList);
				size_t id_cli_temp;
				cin >> id_cli_temp;
				
				cout << "Escolha um item. Digite o Id" << endl;
				itCadastrados(listItems);
				size_t id_it_temp;
				cin >> id_it_temp;
				
				bool deuBom;
				deuBom = cadastrarPedido(listPedidos, ClientList, listItems, id_cli_temp, id_it_temp);
				
				if(deuBom){
					cout << "Pedido cadastrado com sucesso" << endl;
				} else {
					cout << "Pedido nao foi cadastrado" << endl;
				}
				
				
			}
			if (opt == '2'){
				cout << "Não implementado" << endl;
			}
			if (opt == '3'){
				cout << "Não implementado" << endl;
			}
			if (opt == '4'){
				cout << "Não implementado" << endl;
			}
			
			continue;
		}
		if (opt == '4'){
			cout << "Relatorios" << endl;
			cout << "--------------------------------------------" << endl;
			cout << "1 - Relatorio de Cadastro de Item e Clientes" << endl;
			cout << "2 - Relatorio de Substrings de Itens" << endl;
			cout << "3 - Relatorio de Pedidos vs Valores" << endl;
			cout << "4 - Relatorio de Vendas por Cliente" << endl; //ordem alfabetica por cliente
			cout << "5 - Relatorio de Vendas por Item" << endl; // ordem alfabetica e por valores decrescentes
			cout << "--------------------------------------------" << endl;
			
			cin >> opt;
			
			if ( opt == '1'){
				cout << "Cadastro de Itens:" << endl;
				itCadastrados(listItems);
				cout << "Cadastro de Clientes:" << endl;
				cliCadastrados(ClientList);
			
			}
			if (opt == '2'){
				cout << "Substrings" << endl;
				cout << "Informe a substring que deseja procurar:" << endl;
				string substr;
				cin >> substr;
				
				bool deuBom;
				deuBom = searchSubstring(listItems,substr);
				
			}
			if ( opt == '3'){
				cout << "Pedidos - Valores" << endl;
				pedCadastrados(listPedidos);
			}
			if (opt == '4'){
				cout << "Não implementado" << endl;
			}
			if ( opt == '5'){
				cout << "Não implementado" << endl;
			}
			
			
			continue;
		}
		
		if (opt == '5'){
			cout << "Salvar dados" << endl;
			bool deuBomIt, deuBomCli, deuBomPed;

			deuBomIt = saveDbItem(listItems);
			deuBomCli = saveDbClient(ClientList);
			deuBomPed = saveDbPedido(listPedidos);
			
			if (deuBomIt == true && deuBomCli == true && deuBomPed == true){
				cout << "Dados salvos com sucesso" << endl;
			} else {
				cout << "Itens não foram salvos" << endl;
			}
			
			break;
		}
		
		
		
	}

	return(0);
	 
}


bool saveDbClient(vector<Cliente> &ClientList){
	
	string filename = "Clientes.txt";
	ofstream fileWriter1(filename);
	
	if (fileWriter1.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <ClientList.size(); i++){
		
		fileWriter1 << ClientList.at(i).get_nome() << endl;
		fileWriter1 << ClientList.at(i).get_id() << endl;
		fileWriter1 << ClientList.at(i).get_funcao() << endl;
		
	}
	
	fileWriter1.close();

	return true;
}

bool saveDbItem(vector<Item> &listaItem){
	
	string filename = "Itens.txt";
	ofstream fileWriter2(filename);
	
	if (fileWriter2.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <listaItem.size(); i++){
		
		fileWriter2 << listaItem.at(i).get_nome() << endl;
		fileWriter2 << listaItem.at(i).get_id() << endl;
		fileWriter2 << listaItem.at(i).get_valor() << endl;
		
	}
	
	fileWriter2.close();

	return true;
}

bool saveDbPedido(vector<Pedido> &listaPedido){
	
	string filename = "Pedidos.txt";
	ofstream fileWriter3(filename);
	
	if (fileWriter3.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <listaPedido.size(); i++){
		fileWriter3 << listaPedido.at(i).get_id() << endl;
		fileWriter3 << listaPedido.at(i).get_item().get_valor() << endl;
	}

	fileWriter3.close();	

	return true;
}

bool cadastrarCliente(vector<Cliente> &ClientList, string n, string f){
	bool conf = false;

	//Verifica tamanho do vetor
	if (ClientList.empty()){
		Cliente tempClient(n, f);
		ClientList.push_back(tempClient);
		conf = true;
	}
	else{
		//Verifica se o item já foi cadastrado
		for (size_t i = 0; i < ClientList.size(); i++){
			if(ClientList.at(i).get_nome() == n){
				cout << "Cliente ja cadastrado" << endl;
				return conf;
			}
		}
		//Realiza o push_back
		Cliente tempClient(n, f);
		ClientList.push_back(tempClient);
		conf = true;
	}
	return conf;
};

bool cadastrarItem(vector<Item> &listaItem, string n, double p){
	
	bool deuBom = false;
	
	//Verificar tamanho do vetor
	if (listaItem.empty()){
		Item item_temp(n, p);
		listaItem.push_back(item_temp);
		deuBom = true;
	}else{
		//Verifica se o item já foi cadastrado
		for(size_t i = 0; i < listaItem.size(); i++){
			if(listaItem.at(i).get_nome() == n){
				cout << "Item ja cadastrado" << endl;
				return deuBom;
			}
		}
		//Realiza o push_back
		Item item_temp(n, p);
		listaItem.push_back(item_temp);
		deuBom = true;
	}
	return deuBom;
};

bool cadastrarPedido(vector<Pedido> &listaPedido, vector<Cliente> &ClientList, vector<Item> &listaItem,  size_t id_cli, size_t id_it){
	
	bool deuBom = false;
	bool id_cliExis = false;
	bool id_itExis = false;
	size_t i = 0, j = 0, k = 0;
	
	while(i < ClientList.size()){
		
		if(ClientList.at(i).get_id() == id_cli){
			id_cliExis = true;
			break;
		} else{
			i++;
		}
	}
	
	while(j < listaItem.size()){
		
		if(listaItem.at(j).get_id() == id_it){
			id_itExis = true;
			break;
		} else{
			j++;
		}
	}
	
	if(id_cliExis == true && id_itExis == true){
		
		Pedido pedido_temp(ClientList.at(i), listaItem.at(j));
		listaPedido.push_back(pedido_temp);
		deuBom = true;
		
	} else{
		cout << "Verifique os ids informados" << endl;
	}
	
	
	return deuBom;
}

bool searchSubstring(vector<Cliente> &ClientList, string substr){

	bool hasfound = false;

	for (size_t i = 0; i < ClientList.size(); i++){
		
			string word = ClientList.at(i).get_nome();
			size_t possub = word.find(substr);
			
			if (possub < word.length()){
				ClientList.at(i).show_info();
				hasfound = true;
			}
	}
	return hasfound;
}

bool searchSubstring(vector<Item> &listaItem, string substr){

	bool hasfound = false;

	for (size_t i = 0; i < listaItem.size(); i++){
		
			string word = listaItem.at(i).get_nome();
			size_t possub = word.find(substr);
			
			if (possub < word.length()){
				listaItem.at(i).show_info();
				hasfound = true;
			}
	}
	return hasfound;
}

bool updateDadoCli(vector<Cliente> &ClientList, size_t id){
	
	bool deuBom = false;
	bool idExiste = false;
	size_t i = 0;

	while(i < ClientList.size()){
		
		if(ClientList.at(i).get_id() == id){
			idExiste = true;
			break;
		} else{
			i++;
		}
	}
	
	if (idExiste){
		cout << "Atualizar:" << endl;
		cout << "1- Nome" << endl;
		cout << "2- Id" << endl;
		cout << "3- Funcao" << endl;
		char opt;
		cin >> opt;
		
		if(opt == '1'){
			cout << "digite o novo nome" << endl;
			string nome_temp;
			cin >> nome_temp;
			//verifica se já existe o nome pois não podem existir dois nomes de iten iguais
			for (size_t j =0; j < ClientList.size(); j++){
				if (ClientList.at(j).get_nome() == nome_temp){
					return deuBom;
				}
			}
			ClientList.at(i).set_nome(nome_temp);
			deuBom = true;
		} else if (opt == '2'){
			cout << "digite o novo id" << endl;
			size_t id_temp;
			cin >> id_temp;
			//verifica se já existe o id pois nao podem existir dois ids de item iguais
			for (size_t j =0; j < ClientList.size(); j++){
				if (ClientList.at(j).get_id() == id_temp){
					return deuBom;
				}
			}
			ClientList.at(i).set_id(id_temp);
			deuBom = true;
		} else if (opt == '3'){
			cout << "Digite a nova funcao" << endl;
			string tempFuncao;
			cin >> tempFuncao;
			ClientList.at(i).set_funcao(tempFuncao);
			deuBom = true;
		} else {
			cout << "Opcao invalida" << endl;
		}
	} else {
		cout << "Id inexistente" << endl;
	}
	
	return deuBom;
}

bool updateDadoIt(vector<Item> &listaItem, size_t id){
	
	bool deuBom = false;
	bool idExiste = false;
	size_t i = 0;

	while(i < listaItem.size()){
		
		if(listaItem.at(i).get_id() == id){
			idExiste = true;
			break;
		} else{
			i++;
		}
	}
	
	if (idExiste){
		cout << "Atualizar:" << endl;
		cout << "1- Nome" << endl;
		cout << "2- Id" << endl;
		cout << "3- Valor" << endl;
		char opt;
		cin >> opt;
		
		if(opt == '1'){
			cout << "digite o novo nome" << endl;
			string nome_temp;
			cin >> nome_temp;
			//verifica se já existe o nome pois não podem existir dois nomes de iten iguais
			for (size_t j =0; j < listaItem.size(); j++){
				if (listaItem.at(j).get_nome() == nome_temp){
					return deuBom;
				}
			}
			listaItem.at(i).set_nome(nome_temp);
			deuBom = true;
		} else if (opt == '2'){
			cout << "digite o novo id" << endl;
			size_t id_temp;
			cin >> id_temp;
			//verifica se já existe o id pois nao podem existir dois ids de item iguais
			for (size_t j =0; j < listaItem.size(); j++){
				if (listaItem.at(j).get_id() == id_temp){
					return deuBom;
				}
			}
			listaItem.at(i).set_id(id_temp);
			deuBom = true;
		} else if (opt == '3'){
			cout << "digite o novo valor" << endl;
			double valor_temp;
			cin >> valor_temp;
			listaItem.at(i).set_valor(valor_temp);
			deuBom = true;
		} else {
			cout << "Opcao invalida" << endl;
		}
	} else {
		cout << "Id inexistente" << endl;
	}
	
	return deuBom;
}

bool removeCliente(vector<Cliente> &ClientList, vector<Pedido> &listaPedido, size_t id){
	
	bool deuBom = false;
	bool idExiste = false;
	size_t i = 0;
	
	while(i < ClientList.size()){
		
		if(ClientList.at(i).get_id() == id){
			idExiste = true;
			break;
		} else{
			i++;
		}
	}

	if(idExiste){
		bool used;
		// verifica se possui algum pedido com aquele cliente - função que retorna uma booleana checkUse()
		used = checkUse(listaPedido, id, 0);
		if(!used){
			ClientList.erase(ClientList.begin() + i);
			deuBom = true;
		} else{
			cout << "Cliente nao pode ser removido pois esta em um pedido" << endl;
		}
	} else{
		cout << "Id inexistente" << endl;
	}
	
	return deuBom;
	
}

bool removeItem(vector<Item> &listaItem, vector<Pedido> &listaPedido, size_t id){
	
	bool deuBom = false;
	bool idExiste = false;
	size_t i = 0;
	
	while(i < listaItem.size()){
		
		if(listaItem.at(i).get_id() == id){
			idExiste = true;
			break;
		} else{
			i++;
		}
	}

	if(idExiste){
		bool used;
		// verifica se possui algum pedido com aquele item - função que retorna uma booleana checkUse()
		used = checkUse(listaPedido, id, 1);
		if(!used){
			listaItem.erase(listaItem.begin() + i);
			deuBom = true;
		} else{
			cout << "Item nao pode ser removido pois esta em um pedido" << endl;
		}
	} else{
		cout << "Id inexistente" << endl;
	}
	
	return deuBom;
	
}

void cliCadastrados(vector<Cliente> &ClientList){
	//verifica se o vetor está vazio
	cout << "Cliente - Id - Funcao" << endl;
	for(size_t i = 0; i < ClientList.size(); i++){
		cout << ClientList.at(i).get_nome() << " - " << ClientList.at(i).get_id() << " - " << ClientList.at(i).get_funcao() << endl;
	}
	
}

void itCadastrados(vector<Item> &listaItem){
	//verifica se o vetor está vazio
	cout << "Item - Id - Valor" << endl;
	for(size_t i = 0; i < listaItem.size(); i++){
		cout << listaItem.at(i).get_nome() << " - " << listaItem.at(i).get_id() << " - " << listaItem.at(i).get_valor() << endl;
	}
	
}

void pedCadastrados(vector<Pedido> &listaPedido){
	//verifica se o vetor está vazio
	for(size_t i = 0; i < listaPedido.size(); i++){
		cout << "Id: " << listaPedido.at(i).get_id() << " - Valor: " << listaPedido.at(i).get_item().get_valor() << endl;
	}
}

bool checkUse(vector<Pedido> &listaPedido, size_t id, size_t tipo){
	
	bool used = false;
	
	if(tipo == 0){ //Cliente
		for(size_t i = 0; i < listaPedido.size(); i++){
			if(listaPedido.at(i).get_cliente().get_id() == id){
				used = true;
				break;
			}
		}
	} else if (tipo == 1){ //Item
		for(size_t i = 0; i < listaPedido.size(); i++){
			if(listaPedido.at(i).get_item().get_id() == id){
				used = true;
				break;
			}
		}
	} 
	
	return used;
}