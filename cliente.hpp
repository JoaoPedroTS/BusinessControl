#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>

using namespace std;

class Cliente{
private:
    size_t m_id;
    string m_nome;
    string m_funcao;
public:
    //Costrutores
    Cliente();
    Cliente(string nome, string funcao);
    ~Cliente();

    //Gets
    size_t get_id();
    string get_nome();
    string get_funcao();

    //Sets
    void set_id(size_t id);
    void set_nome(string nome);
    void set_funcao(string funcao);

	//Show info
	void show_info();
	//Id generator
    static size_t m_clientQuantity;
};

#endif