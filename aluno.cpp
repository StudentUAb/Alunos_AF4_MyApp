#include "aluno.h"
#include <iostream>
#include <string>
#include <fstream>

Aluno::Aluno(std::string nome, std::string curso, int matricula)
    :m_nome(nome), m_curso(curso), m_matricula(matricula), m_nota(0.0)
{
    //construtor vazio
}

//Getters
std::string Aluno::getName() const{
    return m_nome;
}
std::string Aluno::getCurso() const{
    return m_curso;
}
int Aluno::getMatricula() const{
    return m_matricula;
}
float Aluno::getNota() const{
    return m_nota;
}

void Aluno::imprime() const{
    std::ofstream myfile;
    myfile.open ("alunos.txt");
    if(myfile.is_open()){
    std::cout << m_nome << " " << m_curso << " " << m_matricula
              << " " << m_nota << std::endl;
    myfile << m_nome << " " << m_curso << " " << m_matricula
           << " " << m_nota << std::endl;
    }
}

//Setters
//Valida a entrada da nota
bool Aluno::setNota(float valor){
    if (valor < 0.0 || valor > 10.0){
        return false;
    }
    m_nota=valor;
    return true;
}

//O algoritmo de ordenação utiliza por padrão o simbolo <
bool operator<(Aluno izq, Aluno dir){
    return izq.getMatricula() < dir.getMatricula();
}
