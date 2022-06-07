//#include "cliente.hpp"
#include "item.hpp"
#include <vector>
#include <iostream>
#include <fstream>
//#include "pedido.hpp"

//Cadastrar
// bool cadastrarCliente();
bool cadastrarItem(vector<Item> &listaItem, string n, double p);

//Buscar substring no vector;
bool searchSubstring(vector<Item> &listaItem, string substr);
//bool searchSubstring(vector<Cliente> &listaCliente, string substr);

//Atualizar
// bool updateDadoCli(vector<Cliente> &listaCliente, size_t id);
bool updateDadoIt(vector<Item> &listaItem, size_t id);

//Remover
bool removeItem(vector<Item> &listaItem, size_t id);
// bool removeCliente();

//Verifica uso
//bool checkUse( vector<Pedido> listaPedido, size_t id, size_t tipo);

//SalvaDB
//bool saveDbClient(const vector<Clientes> &listaCliente);
bool saveDbItem(vector<Item> &listaItem);
//bool saveDbPedidos(const vector<Item> &listaPedido);

//Relatorios
void itCadastrados(vector<Item> &listaItem);
//void cliCadastrados();
void pedCadastrados(vector<Pedidos> &listaPedido);


main(){
	
	//vector<Cliente> listClients;
	vector<Item> listItems;
	vector<Pedidos> listPedidos;
	
	for(;;){
		
		
		cout << "-----------------------------" << endl;
		cout << "Sistema de Gestao de Negocios" << endl;
		cout << "1 - Gerir Cliente" << endl;
		cout << "2 - Gerir Item" << endl;
		cout << "3 - Lancar Pedido" << endl;
		cout << "4 - Emite relatorio" << endl;
		cout << "5 - Sair e salvar dados no BD" << endl;
		cout << "-----------------------------" << endl;
		char opt;
		cin >> opt;

		if (opt == '1'){ // Joao Pedro - Cliente
			cout << "1 - Cadastrar novo cliente" << endl;
			cout << "2 - Atualizar dado de cliente" << endl;
			/*cin >> opt;
			
			if ( opt == "1"){
				
			}
			if (opt == "2"){

			}*/
			
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
					deuBom = removeItem(listItems, id);
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
		}/*
		if (opt == '3'){
			cout << "1 - Pedido" << endl;
			cout << "2 - Corrigir pedido" << endl;
			cout << "3 - Buscar Pedido" << endl;
			cout << "4 - Recibo" << endl;
			
			cin >> opt;
			
			if ( opt == '1'){
				
			
			}
			if (opt == '2'){
				
			}
			if ( opt == '3'){
				
			
			}
			if (opt == '4'){
				
			}
			
			continue;
		}*/	
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
				
			}
			if ( opt == '5'){
				
			
			}
			
			
			continue;
		}
		
		if (opt == '5'){
			cout << "Salvar dados" << endl;
			bool deuBom;

			deuBom = saveDbItem(listItems);
			
			if (deuBom){
				cout << "Itens salvos com sucesso" << endl;
			} else {
				cout << "Itens não foram salvos" << endl;
			}
			
			break;
		}
		
		
		
	}

	return(0);
	 
}

/*
bool saveDbClients(const vector<Clientes> &listClients){
	
	ofstream fileWriter1("Clientes.txt");
	
	if (fileWriter1.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <listClients.size(); i++){
		
		fileWriter1 << listClients.at(i);
		
	}
	
	fileWriter1.close();

	return true;

}
*/
bool saveDbItem(vector<Item> &listaItem){
	
	string filename = "Itens.txt";
	ofstream fileWriter2(filename);
	
	if (fileWriter2.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <listaItem.size(); i++){
		
		//fileWriter2 << "Item: " << listaItem.at(i).get_nome() << " Id: " << listaItem.at(i).get_id() << " Valor: " << listaItem.at(i).get_valor() << endl;
		fileWriter2 << listaItem.at(i).get_nome() << endl;
		fileWriter2 << listaItem.at(i).get_id() << endl;
		fileWriter2 << listaItem.at(i).get_valor() << endl;
		
	}
	
	fileWriter2.close();

	return true;
}
/*
bool saveDbPedidos(const vector<vector<pair<size_t, Itenm>>> &listPedidos){)
	ofstream fileWriter3("Pedidos.txt");
	
	if (fileWriter3.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <listClients.size(); i++){
		
		fileWriter2 << listClients.at(i);
		
	}
	
	fileWriter3.close();	
	
	return true;
	
}

*/

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

bool searchSubstring(vector<Item> &listaItem, string substr){

	bool hasfound = false;

	for (size_t i = 0; i < listaItem.size(); i++){
		
			string word = listaItem.at(i).get_nome();
			size_t possub = word.find(substr);
			
			if (possub < word.length()){
				//cout << "Informacoes do Item:" << endl;
				listaItem.at(i).show_info();
				hasfound = true;
			}
	}
	return hasfound;
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

bool removeItem(vector<Item> &listaItem, size_t id){
	
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
		//verifica se possui algum pedido com aquele item
		// função que retorna uma booleana checkUse()
		listaItem.erase(listaItem.begin() + i);
		deuBom = true;
	} else{
		cout << "Id inexistente" << endl;
	}
	
	return deuBom;
	
}

void itCadastrados(vector<Item> &listaItem){
	
	cout << "Item - Id - Valor" << endl;
	for(size_t i = 0; i < listaItem.size(); i++){
		cout << listaItem.at(i).get_nome() << " - " << listaItem.at(i).get_id() << " - " << listaItem.at(i).get_valor() << endl;
	}
	
}


void pedCadastrados(vector<Pedidos> &listaPedido){
	cout << "Pedido - Valor" << endl;
	for(size_t i = 0; i < listaPedido.size(); i++){
		cout << listaPedido.at(i).get_id() << " - " << listaPedido.at(i).get_m_item().get_valor() << endl;
	}
};