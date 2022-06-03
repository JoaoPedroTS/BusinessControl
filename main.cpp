//#include "cliente.hpp"
#include "item.hpp"
#include <vector>
#include <iostream>
//#include "pedido.hpp"

// size_t id_generator();
// size_T id_generator(size_t id);

// bool cadastrarCliente();
bool cadastrarItem(vector<Item> &listaItem, string n, double p);

// buscar substring no vector;
bool searchSubstring(/*const*/ vector<Item> &listaItem, string substr);
//bool searchSubstring(*const*/ vector<Cliente> &listaCliente, string substr);

// bool updateDadoCli(vector<Cliente> &listaCliente, size_t id);
bool updateDadoIt(vector<Item> &listaItem, size_t id);

// bool removerCliente();
// bool removerItem();

//bool saveDbClient(const vector<Clientes> &listaCliente);
bool saveDbItem(const vector<Item> &listaItem, string n, double p);
//bool saveDbPedidos(const vector<Item> &listaPedido);


main(){
	
	//vector<Cliente> listClients;
	vector<Item> listItems;
	//vector<vector<pair<Cliente,Item>>> listPedidos;
	
	for(;;){
		
		
		cout << "-----------------------------" << endl;
		cout << "Sistema de Gestao de Negocios" << endl;
		cout << "1 - Cadastrar Cliente" << endl;
		cout << "2 - Cadastrar Item" << endl;
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
			cout << "1 - Cadastrar item novo" << endl;
			cout << "2 - Atualizar dado de item" << endl;
			cout << "-----------------------------" << endl;
			cin >> opt;
			
			if ( opt == '1'){
				cout << "Insira o nome do Item" << endl;
				string nome_temp;
				cin >> nome_temp;
				cout << "Insira o preco do Item" << endl;
				double preco_temp;
				cin >> preco_temp;
				
				bool deuBom;
				deuBom = cadastrarItem(listItems, nome_temp, preco_temp);
				
				if(deuBom){
					cout << "Item cadastrado" << endl;
					for(size_t i =0; i < listItems.size(); i++){
						listItems.at(i).show_info();
					}
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
					updateDadoIt(listItems, id);
				}else{
					cout << "Item nao encontrado! Verifique o nome do produto" << endl;
				}
				
				//Ideia é usar uma substring para buscar e depois remover conforme as opções que aparecerem;
				//cin >> opt;
				if(opt == '1'){
					//updateDadoIt();
				}
				if(opt == '2'){
					//updateDadoIt();
				}
				if(opt == '3'){
					//updateDadoIt();
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
		}
		
		if (opt == '4'){
			cout << "Relatorios" << endl;
			
			cin >> opt;
			
			if ( opt == '1'){
				
			
			}
			if (opt == '2'){
				
			}
			if ( opt == '3'){
				
			
			}
			if (opt == '4'){
				
			}
			if ( opt == '5'){
				
			
			}
			
			
			continue;
		} */
		
		if (opt == '5'){
			cout << "Salvar dados" << endl;
			
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
bool saveDbItens(const vector<Item> &listItems){
	
	ofstream fileWriter2("Itens.txt");
	
	if (fileWriter2.is_open() == false){
		cout << "Erro" << endl;
		return false;
	}

	for (size_t i = 0; i <listClients.size(); i++){
		
		fileWriter2 << listClients.at(i);
		
	}
	
	fileWriter2.close();

	return true;
}
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

bool searchSubstring(/*const*/ vector<Item> &listaItem, string substr){

	bool hasfound = false;

	for (size_t i = 0; i < listaItem.size(); i++){
		
		//for (size_t j = 0; j < listaItem.at(i).size(); j++){
		
			string word = listaItem.at(i).get_nome(); //.at(j);
			size_t possub = word.find(substr);
			
			if (possub < word.length()){
				//cout << filename.at(i) << " has word: " << word << endl;
				cout << "Informacoes do Item:" << endl;
				listaItem.at(i).show_info();
				hasfound = true;
			}
		//}
	}
	return hasfound;
}

bool updateDadoIt(vector<Item> &listaItem, size_t id){
	
	bool deuBom = false;
	size_t i = 0;
	
	while(listaItem.at(i).get_id() != id){
		i++;
	}
	
	cout << "Atualizar:" << endl;
	cout << "1- Nome" << endl;
	cout << "2- Id" << endl;
	cout << "3- Valor" << endl;
	char opt;
	cin >> opt;
	
	//for(;;){}
	if(opt == '1'){
		cout << "digite o novo nome" << endl;
		string nome_temp;
		cin >> nome_temp;
		//verifica se já existe o nome
		listaItem.at(i).set_nome(nome_temp);
		deuBom = true;
	} else if (opt == '2'){
		cout << "digite o novo id" << endl;
		size_t id_temp;
		cin >> id_temp;
		//verifica se já existe o id
		listaItem.at(i).set_id(id_temp);
		deuBom = true;
	} else if (opt == '3'){
		cout << "digite o novo valor" << endl;
		double valor_temp;
		cin >> valor_temp;
		//verifica se já existe o valor
		listaItem.at(i).set_valor(valor_temp);
		deuBom = true;
	} else {
		cout << "Opcao invalida" << endl;
	}
	
	return deuBom;
}