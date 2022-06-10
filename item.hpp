#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Item{

	private:
		size_t m_id;
		string m_nome;
		double m_valor;
		
	public:
		// Constructor
		Item();
		Item(string nome, double valor);
		Item(size_t id, string nome, double valor);
		
		// Destructor
		~Item();
		
		//Gets
		size_t get_id();
		string get_nome();
		double get_valor();
		
		//Sets
		void set_id(size_t id);
		void set_nome(string nome);
		void set_valor(double valor);
		
		//Show info
		void show_info();
		//Id generator
		static size_t m_globalquantity;

};

#endif
