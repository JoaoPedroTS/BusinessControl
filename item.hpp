#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item{

	private:
		size_t m_id;
		string m_nome;
		double m_valor;
		//static para compartilhar entre objetos;
		//static size_t m_globalquantity = 0;
		
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
		//string show_info();
		//Sets
		void set_id(size_t id);
		void set_nome(string nome);
		void set_valor(double valor);
		
		//Necessidades do Objeto:
		//Atualizar();
		//Remover();
		static size_t m_globalquantity;

};

#endif
