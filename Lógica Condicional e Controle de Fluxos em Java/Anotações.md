# Lógica Condicional e Controle de Fluxos em Java

Curso com a intenção de mostrar operadores lógicos e relacionais, além de estruturas de controle de fluxo e blocos.

### Operadores Relacionais

* O que são: símbolos especiais que realizam comparações e, em seguida, retorna um resultado.
* Como utilizá-los: similaridade ( ==, != ), tamanho ( > , >=, <, <=)

### Operadores Lógicos

* O que são:  realizam comparações lógicas entre operandos lógicos ou expressões e, em seguida, retornam um resultado.
  * Conjunção;
  * Disjunção;
  * Disjunção exclusiva;
  * Negação.
* Como utilizá-los: conjunção ( && - and), disjunção ( || - or ), disjunção exclusiva ( ^ - xor ) e negação ( ! - inversão ).
* Boas práticas:
  * Crie variáveis auxiliares para guardar resultados intermediários

### Controle de fluxo

* O que são: estruturas com capacidade de direcionar o fluxo de execução de um código.
* Como utilizá-los: decisão(if, if-else, if-else-if, switch, operador ternário), repetição( for, while, do while) e interrupção(break, continue, return).
* Boas práticas: 
  * Switch é para valores exatos e if para expressões booleanas;
  * Evitar usar o default do switch para "cases genéricos";
  * Evitar o efeito "flecha" dos if's;
  * Evitar muitos if's aninhados.

### Blocos

* O que são: um grupo de 0 ou mais códigos que trabalham em conjunto para executar uma operação.
* Tipos: 
  * Locais: dentro de métodos;
  * Estáticos: dentro de classes;
  * Instância: dentro de classes.

