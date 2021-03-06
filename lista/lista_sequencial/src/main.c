#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <lista_seq.h>

int
main()
{
  LISTA l;
  int i;
  TIPO_DADO v;
  srand(time(NULL));

  if (!lista_inicializa(&l))
  {
    return 1;
  }

  printf("A lista tem %d itens armazenados, e %d posicoes estao livres\n",
         lista_tamanho(&l), lista_nos_livres(&l));

  for (i = 0 ; i < TAM_LISTA + 2; i++)
  {
    v = (TIPO_DADO)(rand() % 1000);

    if (!lista_insere_ordenado(&l, &v))
    {
      printf("Lista cheia\n");
    }
    else
    {
      printf("Inserido ordenado\n");
    }
  }

  lista_imprime(&l);
  printf("Removendo o inicio... ");

  if (lista_remove_inicio(&l, &v))
  {
    printf("valia %d\n", v);
  }
  else
  {
    printf("Nao deu certo!\n");
  }

  lista_imprime(&l);
  printf("Removendo o final... ");

  if (lista_remove_final(&l, &v))
  {
    printf("valia %d\n", v);
  }
  else
  {
    printf("Nao deu certo!\n");
  }

  lista_imprime(&l);
  printf("Removendo da posicao 3... ");

  if (lista_remove_posicao(&l, &v, 3))
  {
    printf("valia %d\n", v);
  }
  else
  {
    printf("Nao deu certo!\n");
  }

  lista_imprime(&l);
  printf("Inserindo '111' no final... ");
  v = 111;

  if (lista_insere_final(&l, &v))
  {
    printf("Foi\n");
  }
  else
  {
    printf("Nao deu certo!\n");
  }

  lista_imprime(&l);
  printf("Inserindo '999' no inicio... ");
  v = 999;

  if (lista_insere_inicio(&l, &v))
  {
    printf("Foi\n");
  }
  else
  {
    printf("Nao deu certo!\n");
  }

  lista_imprime(&l);
  printf("Inserindo '777' na posicao 1... ");
  v = 777;

  if (lista_insere_posicao(&l, &v, 1))
  {
    printf("Foi\n");
  }
  else
  {
    printf("Nao deu certo!\n");
  }

  lista_imprime(&l);
  printf("Removendo chave '777'... ");
  v = 777;

  if (lista_remove_chave(&l, &v))
  {
    printf("Foi\n");
  }
  else
  {
    printf("Nao existe!\n");
  }

  lista_imprime(&l);
  printf("Removendo chave '-1'... ");
  v = -1;

  if (lista_remove_chave(&l, &v))
  {
    printf("Foi\n");
  }
  else
  {
    printf("Nao existe!\n");
  }

  lista_imprime(&l);
  printf("Quem esta na posicao 5?  ");

  if (lista_consulta_posicao(&l, 5, &v))
  {
    printf("%d\n", v);
  }
  else
  {
    printf("Nao existe!\n");
  }

  lista_imprime(&l);
  printf("Destruindo a lista\n");
  lista_destroi(&l);
  printf("Situacao final\n");
  lista_imprime(&l);
  return 0;
}
