#pragma once
#include <string>

class Aluno
{
public:
    Aluno(std::string name, std::string curso, int matricula);

    //Getters
    std::string getName() const;
    std::string getCurso() const;
    int getMatricula() const;
    float getNota() const;

    //função imprimir na tela
    void imprime() const;

    //Setters
    bool setNota(float valor);
private:
    std::string m_nome;
    std::string m_curso;
    int m_matricula;
    float m_nota;
};

bool operator<(Aluno izq, Aluno dir);
