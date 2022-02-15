# Entendendo Método Java

## Criação

* O que é: sub-rotina disponibilizada por uma classe.
* Como definir e utilizar: public static *_retorno_ _nome_(_parâmetros_) { _corpo_ }*
  * Ex: public String getNome() {...}
  * Utilizar: nome_da_classe.nome_do_metodo();

* Boas práticas em sua criação e uso:
  * nomes devem ser descritivos, mas curtos;
  * camelCase;
  * Possuir entre 80 e 120 linhas;
  * Evitar lista de parâmetros longa;
  * Visibilidades adequadas.

## Sobrecarga

* O que é: capacidade de definir métodos para diferentes contextos, preservando seu nome, mudando os parâmetros.
* Sobrecarga vs Sobrescrita:
  * Sobrecarga: mantém o nome e muda os parâmetros;
  * Sobrescrita: relacionado à orientação a objetos, ligado à herança.

## Retornos

* O que é: uma instrução de interrupção, com simbologia *return* 
* Um método executa o retorno quando:
  * Completa todas as instruções internas;
  * Chega a uma declaração explicita de retorno;
  * Lança uma exceção.

* O tipo de dado do return deve ser compatível com o do método.

