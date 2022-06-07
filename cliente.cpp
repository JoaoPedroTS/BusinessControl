#ifndef CLIENTE_HPP
#define CLIENTE_HPP

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

void Cliente::GetInfo(){
    cout << "id: " << m_id << endl;
    cout << "Nome: " << m_nome << endl;
    cout << "Função: " << m_funcao << endl;
}

size_t Cliente::GetId(){
    return m_id;
}

string Cliente::GetNome(){
    return m_nome;
}

string Cliente::GetFuncao(){
    return m_funcao;
}

void Cliente::UpdateId(size_t id){
    m_id = id;
}
void Cliente::UpdateNome(string nome){
    m_nome = nome;
}
void Cliente::UpdateFuncao(string funcao){
    m_funcao = funcao;
}

Cliente::~Cliente(){
}

#endif