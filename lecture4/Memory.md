## Pixel 

uma imagem digital é uma matriz 

cada elemento da matriz em uma imagem é denominado pixel (picture element)

cada pixel descreve, de alguma forma apropriada, uma cor para aquele ponto da imagem

como uma imagem é armazenada com um número finito de bytes, cada um (talvez) representando um valor vermelho, verde ou azul para cada pixel

## Hexadecimal

extremamente comum para representar as cores rgb, o hexadecimal ou base-16 é uma forma diferente de representar dados:

0 1 2 3 4 5 6 7 8 9 A B C D E F

onde os digitos de 0 a 9 representam a si mesmos e A ao F representam de 10 a 15

ele foi criado pois é mais fácil de ler (comparado com binário) além de ser mais fácil converter hex to bin do que dec to bin

leitura recomendada: Code: the hidden language of computer hardware and software

## Memory Address

outra utilização muito comum do hex é descrever o endereço de memoria 

0x0  0x1  0x2  0x3  0x4  0x5  0x6  0x7 

0x8  0x9  0xA  0xB  0xC  0xD  0xE  0xF

0x10 0x11 0x12 0x13 0x14 0x15 0x16 0x17

0x18 0x19 0x1A 0x1B 0x1C 0x1D 0x1E 0x1F ...

## Pointers

Um ponteiro é uma variavel especial que contém um endereço na memória armazenado, em vez de dados comuns. Esse endereço é, no geral, a posição na memória de outra variável. Desta forma, a variavel que contém esse endereço aponta para a outra variável. E por isso o nome "ponteiro".

ou seja ponteiro é uma variável com um endereço que aponta para outra variável.
(só pra lembrar que variável é um pedaço de memoria que guarda algum dado)

Ponteiros são muito importantes em C, especialmente para criar filas e lista encadeadas entre outras estruturas de dados.

## Declarar Ponteiro

datatype *varName;

o * (star) é o 

## Dereference Operator 

## Strings 

nas primeiras semanas do cs50, o tipo de dado string foi amplamente usado, advindo da cs50.h

por exemplo a string

    string s = "HI!";

que basicamente armazena 'HI!\0' na variavel s

onde o:

s[0] = 'H'
s[1] = 'I'
s[2] = '!'
s[3] = '\0'

(o \0 é a forma de informar ao computador que é o fim da string)

se hipoteticamente os endereços de memoria dessa string forem

0x123 = 'H'
0x124 = 'I'
0x125 = '!'
0x126 = '\0'

então se o computador está alocando esses chars na memória o que exatamente é a variavel s?
(obviamente s é um tipo de dado criado pela cs50.h, porém por baixo do capô, oq é s?)

s é um ponteiro, que aponta expecificamente para o endereço de memória da primeira letra da string

 'H'     'I'     '!'     '\0'
0x123   0x124   0x125   0x126
  ^
  |
  s

no exemplo acima vemos o s apontar para o enderço, ok?

s aponta para o inicio e \0 indica que é o final

se s é um ponteiro, para um char (o primeiro da string), então s é:

char *s = "HI!";

## Datatype string

typedef char *string;

## Pointer Arithmetic 

```
int main(void) 
{
    char *s = "HI!";
    char *s = ("%c\n", *s);  <- aqui vai printar o s e no caso o s é endereço do primeiro char
    char *s = ("%c\n", *(s + 1));  <- aqui vai printar endereço do s + 1 | se o endereço for 0x123 então s + 1 = 0x124
    char *s = ("%c\n", *(s + 2));  <- e assim por diante
    char *s = ("%c\n", *(s + 3));  <- aqui por ex vai printar o \0 que indica o fim da string
}

```

então podemos executar aritmetica com os ponteiro e seus endereços

exatamente como já faziamos com 's[0]'

e tudo isso ai de cima também vale para arrays (falavamos de arrays de char, porém), vale também para array de int float e assim por diante, todos são ponteiros apontando para o primeiro elemento do array.

## Compare and copy

se escrevermos o programa:

```
int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (s == t )
    {
        printf("same\n");
    }
    else 
    {
        printf("different\n");
    }
}
```

mesmo as strings sendo iguais o retorno será diferente

isso acontece por causa que cada string é um ponteiro para um local diferente na memória
então mesmo que os chars sejam iguais, o print vai ser "Different"

uma forma de contornar esse problema é usar o strcmp() da biblioteca <string.h>

## copy.c

veja o codigo a seguir

```
int main(void)
{
    string s = get_string("s: ");

    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```

nitidamente o que ele faz é captalizar APENAS a primeira letra de t

porém o que recebemos de print é:

```
$ ./copy
s: hi!
s: Hi!
t: Hi!
```

captalizando as duas variaveis

isso acontece pq quando fizemos 't = s', como s é um apontador para o endereço x, t passou apontar para x também, ou seja se alterarmos um, altera o outro pq estão apontando para o mesmo lugar

em uma analogia

        'hi!'
        0x123
          ^
          |\
          s t 
os dois estão apontando para o mesmo espaço de memoria e não aconteceu o que queriamos, que era criar uma cópia do 'hi!'


e para contornamos isso precisamos usar alocação dinamica de memória

## malloc and free

o nome malloc é uma abreviatura de memory allocation 

malloc é uma função que recebe um numero x e aloca x espaço para um bloco de bytes consecutivos na memória RAM retornando o endereço onde esse espaço foi alocado
então significa dizer que podemos guardar esse endereço dentro de memória dentro de um ponteiro!

por ex:

```
char *s = malloc(4);

char *s = "HALU!";
char *t = malloc(strlen(s) + 1); // strlen + 1 for \0 at the final of str

int *x = malloc(3 * sizeof(int));
```

## valgrind

é uma ferramenta que ajuda a encontrar bug relacionados a alocação de memoria

para usar valgrind:

```
$ valgrind ./programName


```

## gabarge values

se você por exemplo fizer:

int scores[3]; 
e printar os valores, sem por nada dentro o computador vai retornar valores lixos, resquicios de ints, chars, strings, floats anteriormente usados por outra parte do computador ou semelhante.

então não se deve esquecer nunca de declarar um valor pra dentro de uma variável.
você pode até declarar uma variável sem valor, porém faça-o!

isso é bem perigoso, existem varios exemplos de sistemas que foram invadidos por causa de declarar uma variavel sem atribuição de valor, imagine (no contexto da web) que naquele pedaço de memoria estava o n do cartão de crédito e tomalhe o urubu do pix. ou até mesmo uma senha ou outro dado sensivel.

## swap 

vamos pensar no codigo seguinte:
```
#include <cs50.h>
#include <stdio.h>

void swap(int a,int b);

int main(void)
{
    int x = 1;
    int y = 2;

    swap(x, y);

    printf("\n");
    // precisava de trocar aqui e não funciona
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;

    //agora aqui dentro desse escopo o swap funciona
    printf("a is %i, b is %i\n", a, b);
}
```
infelizmente ele não funciona como o planejado, se obersarmos os comentários providos no código

No exemplo acima a função swap usa copias das variaveis de main, a e b são variaveis locais e só se alteram dentro do escopo da função, ou seja, não muda os valores de x e y no main

## memory layout

o computador usa a memória de uma forma bastante convencional, não apenas aleatório, ou coloca as coisas apenas onde está disponível

Dentro da memória do nosso computador, há diferentes tipos de dados que precisam ser armazenados para nosso programa e são organizados em diferentes seções:

| machine code |
| :----------: |
|    globals   |
|     heap     |
|      ↓       |
|              |
|              |
|              |
|      ↑       |
|    stack     |

* "machine code" armazena o código binário do nosso programa compilado. Ou seja, quando executamos nosso programa, esse código é carregado nessa parte da memória.

* logo abaixo, ou na próxima parte estão "globals" que amazena as variáveis globais, que são todas as variáveis que estão fora de main e fora de qualquer função

* "heap" ou "amontoar", sempre que usamos malloc ele vai para heap, vimos algo sobre isso quando usamos valgrind

* "stack" ou "pilha", sempre que usamos funções e variavéis locais eles vão para stack

se prestarmos atenção nas setinhas acima, heap "caminha" em direção ao stack e visse versa, ou seja:

se usarmos muito malloc, para alocar muita memória, nós teremos um *heap overflow*, tendo em vista que ele irá se "chocar" com stack

e se usarmos muito funções sem nenhum returno vindo delas, nós teremos um *stack overflow*, tendo em vista o mesmo motivo ao contrário

o programa de trocar inteiros pode ter uma stack parecida com:

```
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  tmp      |  |  |  |  |
swap -------------------------
     |  a    1   |  b    2   |
     -------------------------
main |  x    1   |  y    2   |
     -------------------------

```

o `main` tem duas variavéis locais, `x` e `y`. 

o `swap`, quando chamado, é empilhado em cima de `main`, e ele tem três variáveis locais, `a`, `b` e `tmp`.

porém quando `swap` é chamado, ele recebe cópias dos valores `x` e `y`, para dentro de seu escopo, então ele executa, troca somente as cópias dentro de seu próprio escopo e depois que `swap` termina de ser executado, a pilha que ele estava ocupando é liberada e seus valores se tornam *garbage values*, e como você pode perceber e as variáveis em main não são tocadas, só a cópia de seus valores dentro do escopo de swap que sofreram alterações, main se mantem igual.

ou seja, os valores contidos em `swap` são apenas cópias dos valores contidos em main.

Para contornar isso, podemos passar os endereços de `x` e `y`, e assim `swap` será capaz de alterar os valores originais:

```
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

Os endereços de `x` e `y` são passados do `main` para o `swap` com `&x` e `&y`, e usamos a sintaxe `int *a` para declarar que a função swap irá receber um ponteiro.

Ou seja, não serão cópias dos valores, igual ao primeiro código, e sim ponteiros para o endereço de onde estão as variáveis de main, alterando assim não só o escopo local, e sim o escopo de main, tendo em vista que os valores que estão sendo alterados são os que estão sendo apontados e não apenas cópias.

vamos ao passo a passo do que está acontecendo no código:

no caso o poteiro *a está apontando para o endereço da memória onde está armazenado 1

O `tmp` recebe o valor para onde o ponteiro `*a` está apontando, que no caso é `1`.
O `*a` recebe o valor para onde o ponteiro `*b` está apontando, que no caso é para `2`.
O `*b` recebe o valor de tmp, que no caso é `1`.

em uma representação gráfica, a pilha da memória seria:

```
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  tmp      |  |  |  |  |
swap -------------------------
     |  a  0x123 |  b  0x127 |
     -------------------------
main |  x    1   |  y    2   |
     -------------------------
```

se o `x` está no endereço `0x123`, `*a` irá apontar para esse valor.
se o `y` está no endereço `0x127`, `*b` irá apontar para esse valor.

no primeiro passo, o valor de `x` será colocado dentro de `tmp` seguindo para onde aponta o ponteiro `a`.
no primeiro passo, seguindo para onde o ponteiro `a` aponta, no caso aponta para o valor de `x`, esse valor é colocado dentro de `tmp`

```
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  tmp  1   |  |  |  |  |
swap -------------------------
     |  a  0x123 |  b  0x127 |
     -------------------------
main |  x    1   |  y    2   |
     -------------------------
```

então, seguindo o valor para onde o ponteiro `b` aponta, no caso aponta para `y`, esse valor é guardado lá para onde aponta o ponteiro `a`, que no caso é `x`.

```
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  tmp  1   |  |  |  |  |
swap -------------------------
     |  a  0x123 |  b  0x127 |
     -------------------------
main |  x    2   |  y    2   |
     -------------------------
```

e por fim, seguindo para o local apontado por `b`, que no caso é `y`, e colocamos o valor de `tmp` dentro dele, que no caso é `1`

```
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  |  |  |  |  |  |  |  |
     -------------------------
     |  tmp  1   |  |  |  |  |
swap -------------------------
     |  a  0x123 |  b  0x127 |
     -------------------------
main |  x    2   |  y    1   |
     -------------------------
```

e é por isso que os valores dentro de `main` são alterados

## scanf

nas primeiras, para armazenar um dado inserido pelo usuario em uma variavel utilizamos `get_int` ou `get_string` e assim por diante, que são funções disponiveis em cs50.h, isso faz com que o codigo fique mais seguro e um tanto quanto inquebravel, essas funções são rodinhas, para tornar nossa vida mais fácil. 

Já existe um jeito de fazer isso e se chama `scanf`

```
#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);
}

```

scanf pega o %i, digitado pelo usuário, que será "escaneado" e colocado no endereço que foi passado para ele, no caso `&x`

se tentarmos fazer o mesmo para uma string:


```
#include <stdio.h>

int main(void)
{
    char *s;
    printf("s: ");
    scanf("%s", &s);
    printf("s: %i\n", s);
}
```
receberemos o prompt

```
$ ./scanf
s: hi!
s: (null)
```
como não alocamos nenhuma memória para s, scanf está escrevendo o input do usuário em um lugar desconhecido da memória.

para contornar isso podemos usar `malloc`
```
#include <stdio.h>

int main(void)
{
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", &s);
    printf("s: %i\n", s);
}
```
e então funcionará:

```
$ ./scanf
s: hi!
s: hi!
```
outro jeito é declarar um array de quatro caracteres:

```
#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", &s);
    printf("s: %i\n", s);
}
```
agora o código funcionará se o usuário digitar uma string de 3 caracteres ou menos
se a string for maior que 3 o programa irá crashar:
```
$ ./scanf
s: hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
s: hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
Segmentation fault (core dumped)
```

`get_string` de cs50.h aloca mais memória continuamente ata acabar de "scanear" a string e não possui esses problemas de `scanf`

## Files

com a habilidade de usar ponteiros, agora podemos abrir arquivos, como uma lista telefonica digital:

```
// Saves names and numbers to a CSV file
  
#include <cs50.h>
#include <stdio.h>
#include <string.h>
  
int main(void)
{
    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a");
    if (!file)
    {
        return 1;
    }
  
    // Get name and number
    string name = get_string("Name: ");
    string number = get_string("Number: ");
  
    // Print to file
    fprintf(file, "%s,%s\n", name, number);
  
    // Close file
    fclose(file);
}
```

`fopen`/"file open" é uma função que possibilita abrir um arquivo com um tipo
`fprintf` pode ser usado para escrever no arquivo

## JPEG

qualquer foto no formato jpeg como com três bytes escritos desse jeito:

> 0xFF 0xD8 0xFF

```
// Detects if a file is a JPEG
  
#include <stdint.h>
#include <stdio.h>
  
typedef uint8_t BYTE;
  
int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        return 1;
    }
  
    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }
  
    // Read first three bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);
  
    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Yes, possibly\n");
    }
    else
    {
        printf("No\n");
    }
  
    // Close file
    fclose(file);
}
```

no passo a passo do código acima
* primeiro definimos o tipo de dados `BYTE`, como 8 bits para ficar mais fácil de referenciar e usar no restante do código
* usamos `fread` para ler o arquivo e colocar o 3 primeiros bytes na variavel `bytes`
* checamos se os 3 primeiros bytes são iguais aos de um jpeg

## BMP

isso também funciona para arquivos BMP e outros formatos de imagens.

```
#include "helpers.h"
  
// Only let red through
void filter(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = 0x00;
            image[i][j].rgbtGreen = 0x00;
        }
    }
}
```

esse programa tem a função filter que recebe altura e largura de uma imagem
varre em um loop alinhado todos os pixels da imagem
e ela remove o azul e verde de cada pixel da imagem
deixando assim só pixels vermelhos, sejas eles com mais ou menos intensidade de vermelho 0x000000 0xFF0000
