#include "lista.h"
#include <stdio.h>

void probar_lista_eliminando(){
  lista_t* lista = lista_crear();
  char q='q', w='w', e='e', r='r', t='t';
  
  lista_insertar(lista,&q);
  lista_insertar(lista,&w);
  lista_insertar(lista,&e);
  lista_insertar(lista,&r);
  lista_insertar(lista,&t);
  printf("Elementos en la lista: ");
  for(size_t i=0;i<lista_elementos(lista);i++)
    printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));
  lista_destruir(lista);
}

void eliminando_en_posiciones_bordes(){
  lista_t* lista = lista_crear();
  char q='q', w='w', e='e', r='r', t='t';
  
  lista_insertar(lista,&q);
  lista_insertar(lista,&w);
  lista_insertar(lista,&e);
  lista_insertar(lista,&r);
  lista_insertar(lista,&t);
  printf("Elementos en la lista: ");
  for(size_t i=0;i<lista_elementos(lista);i++)
    printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));
  printf("\n\n");

  printf("Elimino un elemento pos 0\n");
  lista_borrar_de_posicion(lista, 0);

  printf("Elementos en la lista: ");
  for(size_t i=0;i<lista_elementos(lista);i++)
    printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));

  printf("\n\n");

  printf("Elimino un elemento pos 3\n");
  lista_borrar_de_posicion(lista, 3);  
  printf("Elementos en la lista: ");
  for(size_t i=0;i<lista_elementos(lista);i++)
    printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));

  printf("\n\n");

  printf("Elimino un elemento fuera del rango\n");
  lista_borrar_de_posicion(lista,100);  
  printf("Elementos en la lista: ");
  for(size_t i=0;i<lista_elementos(lista);i++)
    printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));

  printf("\n\n");

  lista_destruir(lista);  
}
void mostrar_elemento(void* elemento, void* contador){
  if(elemento && contador)
    printf("Elemento %i: %c \n", (*(int*)contador)++, *(char*)elemento);
  
}


void probar_operaciones_lista(){
 lista_t* lista = lista_crear();
  
  char a='a', b='b', c='c', d='d', w='w';
  
  lista_insertar(lista, &a);
  lista_insertar(lista, &c);
  lista_insertar_en_posicion(lista, &d, 100);
  lista_insertar_en_posicion(lista, &b, 1);
  lista_insertar_en_posicion(lista, &w, 3);

  lista_borrar_de_posicion(lista, 3);

  printf("Elementos en la lista: ");
  for(size_t i=0;i<lista_elementos(lista);i++)
    printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));

  printf("\n\n");

  printf("Imprimo la lista usando el iterador externo: \n");
  lista_iterador_t* it = lista_iterador_crear(lista);
  while(lista_iterador_tiene_siguiente(it))
    printf("%c ", *(char*)lista_iterador_siguiente(it));
  printf("\n\n");

  lista_iterador_destruir(it);

  int contador=0;
  printf("Imprimo la lista usando el iterador interno: \n");
  lista_con_cada_elemento(lista, mostrar_elemento, (void*)&contador);
  printf("\n");
  
  lista_destruir(lista);
}

void probar_operaciones_cola(){
  lista_t* cola = lista_crear();

  int numeros[]={1,2,3,4,5,6};

  for(size_t i=0;i<sizeof(numeros)/sizeof(int);i++){
    printf("Encolo %i\n", numeros[i]);
    lista_encolar(cola, &numeros[i]);
  }
  
  printf("\nDesencolo los numeros y los muestro: ");
  while(!lista_vacia(cola)){
    printf("%i ", *(int*)lista_primero(cola));
    lista_desencolar(cola);
  }
  printf("\n");
  lista_destruir(cola);
}

void probar_operaciones_pila(){
  lista_t* pila = lista_crear();
  char* algo="somtirogla";

  for(int i=0;algo[i]!= 0;i++){
    printf("Apilo %c\n", algo[i]);
    lista_apilar(pila, &algo[i]);
  }

  printf("\n\n");
  printf("\nDesapilo y muestro los elementos apilados: ");
  while(!lista_vacia(pila)){
    printf("%c", *(char*)lista_tope(pila));
    lista_desapilar(pila);
  }
  printf("\n");

  lista_destruir(pila);
}

int main(){
  /*printf("Pruebo lista eliminando simple\n");
  probar_lista_eliminando();

  printf("Pruebo que la lista se comporte como lista\n");
  probar_operaciones_lista();
  
  printf("\nPruebo el comportamiento de cola\n");
  probar_operaciones_cola();

  printf("\nPruebo el comportamiento de pila\n");
  probar_operaciones_pila();*/

  printf("\nPruebo eliminando en bordes\n");
  eliminando_en_posiciones_bordes();
  return 0;
}
