#include "item.hpp"

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

void Item::show_info(){
	cout << "Item: " << m_nome << endl;
	cout << "Id: " << m_id << " Valor: " << m_valor << endl;
};

Item::~Item(){};