# Métodos de Ordenação

## Algoritmos

### shuffle.c

Compilação: gcc shuffle.c -o shuffle

Uso: ./shuffle (nome do arquivo) (qtd de elementos)

Complexidade no pior caso: $O(n)$.

Algoritmo: Gera arquivos.txt com a informação de um conjunto ${1, 2, 3, ..., n-1}$ com $n$ elementos.

No arquivo e na primeira linha, está o tamanho $n$. E nas $n$ linhas seguintes, há os elementos do conjunto dispostos de forma embaralhada.

### BogoSort

Compilação: gcc bogosort.c -o bogosort

Uso: ./bogosort (nome do arquivo)

Complexidade no pior caso: $O(n!)$.

Algoritmo: Dado vetor lido no arquivo, reembaralha até que, por pura sorte, encontre o vetor ordenado. 

Por exemplo, se houver 5 elementos, o algoritmo terá feito ordenação se alcançar uma das 5! = 120 permutações possíveis. Da mesma forma, se houver 10 elementos, o algoritmo deve sortear uma das 10! = 3628800 permutações possíveis. I. e., a cada iteração, existe $\frac{1}{3628800} = 0.000027557\%$ de chance de atingir a ordenação.

OBS.: A _seed_ do _rand()_ é $f(x) = x, x\in\mathbb{N}$. Assim sendo e para determinada sequência a ser ordenada, o tempo de execução será sempre o mesmo. 
