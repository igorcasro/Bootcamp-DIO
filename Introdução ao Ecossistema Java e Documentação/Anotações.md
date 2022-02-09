# Anotações Sobre Java

* Trabalha com a JVM: traduz os bytecodes do compilador Javac em código de máquina.
* JVM interpreta os bytecodes para qualquer um dos sistemas operacionais.
* JRE: executa os programas em Java.
* JDK: permite o desenvolvimento de programas em Java.

## Instalando a JVM

* sudo apt install curl

* Utilizar o JVM para uso de diversas versões do Java: curl -sL https://github.com/shyiko/jabba/raw/master/install.sh | bash && . ~/.jabba/jabba.sh

  

  ### Utilizando JVM

  * jabba ls-remote
  * jabba install openjdk@1.11
  * jabba use openjdk@1.11
  * java -version

  
  
  ### Compilar
  
  * Retornar para a pasta raiz
  * jabba use openjdk@1.11
  * javac -d target/ -sourcepath src/ src/com/dio/MyFirstProgram.java
  
  
  
  ### Executar
  
  * Acessa pasta target: cd target/
  * Executa com: java com.dio.MyFirstProgram
  
  





## Links úteis

[Download ]()