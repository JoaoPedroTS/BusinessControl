#include <iostream>
#include <string>
#include "cliente.hpp"
#include "item.hpp"

class Pedido{

	private:
		size_t m_id;
		Item m_item;
		Cliente m_cliente;
		//posso usar pair?
	public:
		//Constructor
		Pedido();
		Pedido(Cliente cli, Item it);
		//Pedido(Cliente cli, Item it, Item it);
		//Pedido(Cliente cli, Item it, Item it, Item it);
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
		
		//Gerador de Id
		static size_t m_globalquantity;
		
};