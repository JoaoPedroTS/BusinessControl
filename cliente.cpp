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
    cout << "Informe o id do cliente que deseja consultar" << endl;
    size_t tempId;
    cin >> tempId;
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

Cliente::~Cliente(){
}

#endif