#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "cliente.hpp"
#include "item.hpp"

class Pedido{

	private:
		size_t m_id;
		Item m_item;
		Cliente m_cliente;

	public:
		//Constructor
		Pedido();
		Pedido(Cliente cli, Item it);
		Pedido(size_t id, Cliente cli, Item it);
		
		//Destructor
		~Pedido();
		
		//Gets
		size_t get_id();
		Item get_item();
		Cliente get_cliente();
		
		//Sets
		void set_id(size_t id);
		void set_item(Item it);
		void set_cliente(Cliente cli);
		
		//Id generator
		static size_t m_globalquantity;	
};

#endif