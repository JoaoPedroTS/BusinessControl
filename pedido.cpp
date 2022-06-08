#include "pedido.hpp"

size_t Pedido::m_globalquantity = 0;

Pedido::Pedido(){
	
	m_globalquantity++;
	
	m_id = m_globalquantity;
	m_item = Item();
	m_cliente = Cliente();
}

Pedido::Pedido(Cliente cli, Item it) : Pedido(){

	m_item = it;
	m_cliente = cli;
	
}

Pedido::Pedido(size_t id, Cliente cli, Item it) : Pedido(){
	
	m_id = id;
	m_item = it;
	m_cliente = cli;
	
}

Pedido::~Pedido(){};

size_t Pedido::get_id(){
	return m_id;
}

Item Pedido::get_item(){
	return m_item;
}

Cliente Pedido::get_cliente(){
	return m_cliente;
}


void Pedido::set_id(size_t id){
	m_id = id;
}

void Pedido::set_item(Item it){
	m_item = it;
}

void Pedido::set_cliente(Cliente cli){
	m_cliente = cli;
}