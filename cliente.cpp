#include "cliente.hpp"

size_t Cliente::m_clientQuantity = 0;

Cliente::Cliente(){
    m_clientQuantity++;

    m_id = m_clientQuantity;
    m_nome = " ";
    m_funcao = " ";
}

Cliente::Cliente(string nome, string funcao) : Cliente(){
    m_nome = nome;
    m_funcao = funcao;
}

void Cliente::show_info(){
	cout << "Nome: " << m_nome << endl;
    cout << "id: " << m_id << endl;
    cout << "Funcao: " << m_funcao << endl;
}

size_t Cliente::get_id(){
    return m_id;
}

string Cliente::get_nome(){
    return m_nome;
}

string Cliente::get_funcao(){
    return m_funcao;
}

void Cliente::set_id(size_t id){
    m_id = id;
}
void Cliente::set_nome(string nome){
    m_nome = nome;
}
void Cliente::set_funcao(string funcao){
    m_funcao = funcao;
}

Cliente::~Cliente(){}
