#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	unsigned DNI;
	char Nombre[32];
	char Apellidos[64];
	char FechaNacimiento[11];
	void *siguiente_elemento; /* se pone como void porque no podemos usar el
	tipo —Elemento“, que aún no está definido */
} Elemento;

typedef Elemento * Lista; /* Una lista es un puntero a su primer elemento (NULL) si está vacía */ 

void Inicio();
Lista Lista_Crear(void);
void Lista_Agregar(Lista *l, const Elemento *elem); /* agrega una copia de elem al final de la lista.*/ 
void Lista_Mostrar(const Lista l);
int Lista_Vacia(const Lista l);
void Lista_Vaciar(Lista *l); /* borra todos los elementos de la lista.*/
void Borrar_Elemento(Lista list);


int main (void) {
	int opcion=0;
	Lista list=Lista_Crear();
	Lista *lptr=&list;
	list=malloc(sizeof(Elemento));
	Inicio();
	Elemento *elem1;
	Elemento *elem2;
	Elemento *elem3;
	elem1=(Elemento*)malloc(sizeof(Elemento));
	elem2=(Elemento*)malloc(sizeof(Elemento));
	elem3=(Elemento*)malloc(sizeof(Elemento));
	
	elem1->DNI=1;
	strcpy(elem1->Nombre,"Pepe");
	strcpy(elem1->Apellidos,"Jimenez Sanchez");
	strcpy(elem1->FechaNacimiento,"12/6/1986");
	elem1->siguiente_elemento=elem2;
	Lista_Agregar(lptr,elem1);
	elem2->DNI=15;
	strcpy(elem2->Nombre,"Paco");
	strcpy(elem2->Apellidos,"Moreno Rodriguez");
	strcpy(elem2->FechaNacimiento,"16/04/1992");
	elem2->siguiente_elemento=NULL;
	Lista_Agregar(lptr,elem2);
	
	
	scanf("%d",&opcion);
	switch (opcion) {
		case 1:
			
			printf("Introduzca DNI: ");
			scanf("%u",&elem3->DNI);
			printf("\nIntroduzca Nombre: ");
			scanf("%s",&elem3->Nombre);
			printf("\nIntroduzca Apellidos: ");
			scanf("%s",&elem3->Apellidos);
			printf("\nIntroduzca Fecha de Nacimiento: ");
			scanf("%s",&elem3->FechaNacimiento);
			Lista_Agregar(lptr,elem3);
			break;
		case 2:
			Borrar_Elemento(list);
			break;
		case 3:
			Lista_Mostrar(list);
		case 4:
			Lista_Vaciar(lptr);
			break;
		default:
			printf("Opción no soportada\n");
			break;
	}
	Lista_Mostrar(list);
	
}

void Inicio () {
	printf("Elija una opción:\n1)Añadir elemento\n2)Borrar elemento\n3)Imprimir el elemento enésimo\n4)Vaciar la lista\n");
}

Lista Lista_Crear(void) {
	Lista lista;
	lista=NULL;
	return lista;
} /* crea la lista y la devuelve, vacía. */

void Lista_Agregar(Lista *l, const Elemento *elem) {
	Elemento *ulti=malloc(sizeof(Elemento));
	Elemento *nuevo=malloc(sizeof(Elemento));
	ulti=*l;
	while (ulti->siguiente_elemento!=NULL) {
		ulti=ulti->siguiente_elemento;
	}
	nuevo->DNI=elem->DNI;
	strcpy(nuevo->Nombre,elem->Nombre);
	strcpy(nuevo->Apellidos,elem->Apellidos);
	strcpy(nuevo->FechaNacimiento,elem->FechaNacimiento);
	(*ulti).siguiente_elemento=nuevo;
	nuevo->siguiente_elemento=NULL;

}
void Borrar_Elemento (Lista list) {
	Lista temp;
	
	temp=list->siguiente_elemento;
	
	while (temp->siguiente_elemento!=NULL) {
		list=temp;
		temp=temp->siguiente_elemento;
	}
	free(list->siguiente_elemento);
	list->siguiente_elemento=NULL;
	
}
void Lista_Mostrar(const Lista l) {
	 Lista aux=l->siguiente_elemento;
	
	int i=1;
	while (aux!=NULL) {
		printf("Elemento de la lista %d:\n %u\n%s\n%s\n%s\n",i,aux->DNI, aux->Nombre, aux->Apellidos, aux->FechaNacimiento );
		aux=aux->siguiente_elemento;
		i++;
	}
}
int Lista_Vacia(const Lista l) {
	int ret=0;
	if (l==NULL) {
		ret=1;
	}
	return ret;
}
void Lista_Vaciar(Lista *l) {
	*l=NULL;
}
