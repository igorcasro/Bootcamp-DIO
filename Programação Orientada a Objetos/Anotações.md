# Programação Orientada a Objetos

Curso que possui o objetivo de ensinar todos os conceitos relativos à Orientação a Objetos (OO).

### Por que usar?

* Enquanto um Paradigma Estruturado (PE) tem uma representação mais simplista, o Paradigma Orientado a Objetos (POO) tem uma representação mais realista.
* PEE foca em operações(funções) e dados, já POO foca na modelagem de entidades e nas interações entre estas.
* PE foca mais em "como fazer" enquanto POO foca mais no "que fazer".
* Vantagens da POO:
  * Melhor coesão;
  * Melhor acoplamento;
  * Diminuição do Gap semântico;
  * Coletor de lixo.

### Os fundamentos

* O que é a OO: um paradigma de análise, projeto e programação de sistemas de software baeado na composição e interação entre diversas unidades de software chamadas de objetos.
* Pilares:
  * Abstração: processo pelo qual se isolam características de um objeto, considerando os que tenham em comum certos grupos de objetos;
  * Reuso: capacidade de criar novas unidades de código a partir de outras já existentes;
  * Encapsulamento: capacidade de esconder complexidades e proteger dados.

### A estrutura

Conceitos que criam as estruturas básicas da OO:

* Classe: uma estrutura que abstrai um conjunto de objetos com características similares. Uma classe define o comportamento de seus objetos através de métodos e os estados possíveis destes objetos através de atributos. Em outros termos, uma classe descreve os serviços providos por ses objetos e quais informações eles podem armazenar.
  * Dicas:
    * Substantivos;
    * Nomes significativos;
    * Contexto deve ser considerado.
* Atributo: é o elemeto de uma classe responsável por definir sua estrutura de dados. O conjuntos destes será responsável por representar suas características e fará parte ds objetos criados a partir da classe.
  * Atributo x Variável:
    * Atributo: o que é próprio e peculiar a alguém ou alguma coisa;
    * Variável: sujeto a variações ou mudanças; pode variar; inconstante, instável.
  * Dicas:
    * Substantivos e adjetivos;
    * Nomes significativos;
    * Contexto deve ser considerado;
    * Abstração;
    * Tipos adequados.
* Método: é uma porção de código (sub-rotina) que é disponibilizado pela classe. Este é executado quando é feita uma requisição a ele. Um método serve para identificar quais serviços, ações, que a classe oferece. Eles são responsáveis por definir e realizar um determinado comportamento.
  * Dicas:
    * Verbos;
    * Nomes significativos;
    * Contexto deve ser considerado.
  * Métodos especiais:
    * Construtor: constrói objetos a partir de nossas classes; pode prover valores iniciais à criação de um objeto;
    * Destrutor: auxilia na destruição de um objeto; boa prática fazer a implementação do destrutor para liberar recursos.
    * Sobrecarga: mudar a assinatura(nome + parâmetros) de acordo com a necessidade;
* Objeto e Mensagem: 
  * Objeto: um objeto é a representação de um conceito/entidade do mundo real, que pode ser física ou conceitual e possui um significado bem definido para um determinado software. Para esse conceito/entidade, deve ser definida inicialmente uma classe a partir da qual posteriormente serão instanciados objetos distintos.
  * Mensagem: é o processo de ativação de um método de um objeto. Isto ocorre quando uma requisição(chamada) a esse método é realizada, assim disparando a execução de seu comportamento descrito por sua classe. Pode também ser direcionada diretamente à classe, caso a requisição seja para um método estático.

### As relações

* Herança:
  * Conceito: é o relacionamento entre classes em que uma classe chamada de subclasse é uma extensão(subtipo) de outra classe chamada de superclasse. Devido a isto, a subclasse consegue reaproveitar os atributos e métodos dela. Além dos herdados, a subclasse pode definir seus próprios membros.
  * Tipos: 
    * Simples: uma classe filha tem só uma classe mãe;
    * Múltipla: a classe filha tem uma ou mais classes mães(Java e C# não possuem).
  * Upcast x Downcast:
    * Upcast: sobe na hierarquia de classes; sempre implícito;
    * Downcast: desce na hierarquia de classes; é explícito.
  * Polimorfirsmo e Sobrescrita:
    * Polimorfismo: a mesma ação se comportando diferente(mesmo método usado diferente);
    * Sobrescrita: a mesma ação podendo se comportar diferente.
* Associação:
  * Conceitos: possibilita um relacionamento entre classes/objetos, no qual estes possam pedir ajuda a outras classes/objetos e representar de forma completa o conceito ao qual se destinam. Neste tipo de relacionamento, as classes e os objetos interagem entre si para atingir seus objetivos.
  * Tipos: 
    * Estrutural:
      * Composição: com parte todo;
      * Agregação; sem parte todo.
    * Comportamental:
      * Dependência: depende de.
* Interface:
  * Conceito: define um contrato que deve ser seguido pela classe que a implementa. Quando uma classe implementa uma interface ela se compromete a realizar todos os comportamentos que a interface disponibiliza.
  * Como utiliza: em java coloca a palavra especial _interface_ A { } e é chamada por class B _implements_ A { }



### A organização

* Pacotes:
  * Conceito: são uma organização física ou lógica criada para separar classes com responsabilidades distintas. Com isso, espera-se que a aplicação fique mais organizada e seja possível separar classes de finalidades e representatividades diferentes.
* Visibiliades:
  * Conceito:



### Próximos passos



## PASTAS NO DIRETÓRIO

* POO-DIO: diz respeito a polimorfismo; (HERANÇA)
* POO-DIO2: diz respeito a sobrescrita; (HERANÇA)
* POO-DIO3: diz respeito a Associação;
* POO-DIO4: diz respeito a Interface;
