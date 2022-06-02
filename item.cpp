#include "item.hpp"

/*size_t Item::id_generator(){

// O id deverá ser gerado fora do objeto, uma vez que cada vez que um objeto for instanciado irá ser desenvolvido
// será criado um vetor do tipo size_t que ira armazenar o id do objeto;
// Por isso o gerador de Id deverá ser feito em uma função externa que atribui o id a a instancia do objeto quando for inicializado a instanciação do objeto;

	size_t size = m_id_it.size();
	cout << "size: " << size << endl;
	size_t id_temp;
	
	if (size == 0){
		id_temp = 1;
	} else{
		id_temp += size;
	}
	
	m_id_it.push_back(size);
	
	cout << "size: " << m_id_it.size() << endl;
	return id_temp;
};

size_t Item::id_generator(size_t id){
	
	size_t id_temp = id;
	
	for(size_t i = 0; i < m_id_it.size(); i++){
		
		if(id == m_id_it.at(i)){
			id_temp += m_id_it.size();
			break;
		}
	}
	
	return id_temp;
	
};*/

size_t Item::m_globalquantity = 0;

Item::Item(){
	
	m_globalquantity++;
	
	m_id = m_globalquantity;
	m_nome = " ";
	m_valor = 0.00;
}

Item::Item(string nome, double valor) : Item(){

	m_nome = nome;
	m_valor = valor;
	
}

Item::Item(size_t id, string nome, double valor) : Item(){

	m_nome = nome;
	m_valor = valor;

}

size_t Item::get_id(){
	return m_id;
}

string Item::get_nome(){
	return m_nome;
}

double Item::get_valor(){
	return m_valor;
}

void Item::set_id(size_t id){
	m_id = id;
}

void Item::set_nome(string nome){
	m_nome = nome;
}

void Item::set_valor(double valor){
	m_valor = valor;
}

Item::~Item(){};