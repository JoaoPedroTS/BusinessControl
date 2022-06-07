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
    void GetInfo();
    size_t GetId();
    string GetNome();
    string GetFuncao();

    //Sets
    void UpdateId();
    void UpdateNome();
    void updateFuncao();

    static size_t m_clientQuantity;
};