#pragma once
#include "aluno.h"
#include <string>
#include <vector>

class Lista
{
public:
    void adicionar(Aluno valor);
    void ordena();
    void imprimeAluno();
    void MaxMin() const;
    float calMediaGlobal() const;
private:
    std::vector<Aluno> m_alunos;
};


