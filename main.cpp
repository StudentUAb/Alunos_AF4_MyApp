#include "aluno.h"
#include "lista.h"
#include <iostream>


//função para validar as notas entre 0 e 10
float le_nota(std::string texto){
    // while para validar entre 0 e 10 as notas dos alunos
    while(true){
        std::string notatexto;
        float notaConvertidaFinal;
        std::cout << texto << std::endl;
        std::cin >> notatexto;
        try{
            notaConvertidaFinal = std::stof(notatexto);
           bool sucesso = notaConvertidaFinal >= 0 && notaConvertidaFinal <= 10;
            if (sucesso==true){
                return notaConvertidaFinal;
            }else{
                std::cout << "O numero tem de estar entre 0 e 10" << std::endl;
            }
        }catch(...){
            std::cout << "Valor invalido, entre com numero"<< std::endl;
        }
    }
    return 0;
}






// inicio do main
   int main (){
       // Inicicializa variaveis
       char op = 0;
       auto lista = Lista();
       //loop infinito para cadastrar
       while(true){
           std::cout << "Quer (c)adastrar ou (s)air?" << std::endl;
           std::cin >> op;
           if (op !='c'){
               break;
           }
           //variaveis para ler de dados
           std::string nome;
           std::string curso;
           std::string matricula;
           std::string nota;
           int matriculaConvertida;
           //float notaConvertida;

           //Interação com o utilizador
           std::cout << "Entre o nome do aluno:" << std::endl;
           std::cin >> nome;
           std::cout << "Entre o nome do curso do aluno:" << std::endl;
           std::cin >> curso;
           //Matricula pode falhar, se a pessoa introduzir algo que nâo seja numero
           while(true){
               std::cout << "Entre o numero da matricula do aluno:" << std::endl;
               std::cin >> matricula;
               //converte de string para float pode falhar, então temos o try/catch
               try{
                   matriculaConvertida = std::stoi(matricula);  // string-to-int
                   break;
               }catch (...){
                   std::cout << "Valor invalido, entre com um numero." << std::endl;
               }
           }

//           //Nota pode falhar, se a pessoa introduzir algo que nâo seja numero
//           while(true){
//               std::cout << "Entre o valor da nota do aluno entre 0.0 e 10.0" << std::endl;
//               std::cin >> nota;

//               //converte de string para float pode falhar, então temos o try/catch
//               try{
//                 float notaConvertida = std::stof(nota);  // string-to-float
//                   break;
//               }catch (...){
//                   std::cout << "Valor invalid, entre com um numero." << std::endl;
//               }
//           }
           // Objeto alunoatual
           auto alunoatual = Aluno(nome,curso, matriculaConvertida);
                alunoatual.setNota(le_nota("Entre a nota do aluno (0-10):"));
                //adiciona dados a lista
                lista.adicionar(alunoatual);
       }

       std::cout << "______________________________" << std::endl;
       //Ordena a lista
       lista.ordena();
       //Imprime a lista ja ordenada por matricula
       lista.imprimeAluno();

       std::cout << "Media Global:" << lista.calMediaGlobal() << std::endl;
       std::cout << "______________________________" << std::endl;
       //imprime a nota maior e menor
       lista.MaxMin();

       return 0;
   }
