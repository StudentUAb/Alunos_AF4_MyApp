#include "lista.h"
#include <iostream>
#include <algorithm>

//Adiciona alunos a lista
void Lista::adicionar(Aluno valor){
    m_alunos.push_back(valor);  //adiciona valores ao vector
}

//ordena por matricula
void Lista::ordena(){
    std::sort(std::begin(m_alunos),std::end(m_alunos));
}

//Imprime os alunos na tela
void Lista::imprimeAluno(){
    for (const auto& valoratual : m_alunos){
        valoratual.imprime();
    }
    return;
}

//Calcula menor e maior
void Lista::MaxMin() const{
    if(m_alunos.size() == 0){
        return;
    }
    auto minimo = std::min_element(std::begin(m_alunos),std::end(m_alunos));
    auto maximo = std::max_element(std::begin(m_alunos),std::end(m_alunos));
    std::cout << "Nota mais baixa" << std::endl;
    (*minimo).imprime();

    std::cout << "Nota mais alta" << std::endl;
    (*maximo).imprime();
}

//Calcula Media Global
float Lista::calMediaGlobal() const{
    float valorTotal = 0.0f;
    for (const Aluno& valoratual : m_alunos){
        valorTotal += valoratual.getNota();
    }
    return valorTotal / m_alunos.size();
}
