# Projeto: Problema de Somas de Pares

## Descrição do Problema
Este projeto visa implementar soluções para o **Problema de Somas de Pares (Pair Sum Problem)**, utilizando a linguagem C. O objetivo é auxiliar no entendimento de diferentes abordagens algorítmicas para resolver problemas de busca e otimização.

O **Problema de Somas de Pares** consiste em, dado um conjunto de números, determinar se existem dois números cuja soma seja igual a um valor-alvo específico. Este problema é amplamente estudado em ciência da computação devido à sua relevância em áreas como segurança de dados, análise de algoritmos e sistemas de recomendação.

### Aplicabilidade Prática
Este problema possui diversas aplicações no mundo real, como:
- **Análise de dados**: Identificação de padrões em grandes conjuntos de dados.
- **Segurança de sistemas**: Verificação de combinações que atendam a critérios específicos.
- **E-commerce**: Busca de produtos cujo valor combinado atenda a um orçamento.

## Algoritmos Implementados
1. **Força Bruta**: Testa todas as combinações possíveis de pares no conjunto de números, verificando quais atendem ao valor-alvo. Tem complexidade \(O(n^2)\).

2. **Dividir e Conquistar**: O conjunto de números é dividido em subproblemas menores, resolvidos separadamente. Os resultados são então combinados para encontrar a solução. A complexidade é \(O(n \log n)\) considerando uma ordenação inicial.

3. **Programação Dinâmica**: Utiliza uma abordagem otimizada armazenando soluções intermediárias em uma tabela, evitando recomputações desnecessárias. A complexidade é reduzida em relação à força bruta.

## Como Rodar
1. Clone este repositório:
   ```bash
   git clone <link-do-repositorio>
   ```
2. Compile o programa no terminal utilizando o GCC ou outra ferramenta compatível com C:
   ```bash
   gcc -o main.o main.c somapares.c
   ```
3. Execute o programa:
   ```bash
   ./main.o
   ```
4. Edite o arquivo `main.c` para testar diferentes tamanhos de conjuntos de números e somas-alvo.