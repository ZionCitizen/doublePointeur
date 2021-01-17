#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

// Programme pour voir l utilité des doubles pointeurs 
// Leçon a retenir pour modifier quoi que ce soit sans retour on pas par un pointeur c'est valable pour les pointeur 
//si on veut modifier un pointeur on passe par un pointeur sur pointeur !


//  pointeur marche pas !

void systemInitializer1(SDL_Window *window,SDL_Renderer *renderer){
   if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
   	  printf("Erreur Lors de L Initialisation des SubSystem \n");
   }else{
   	  printf("Initialisation des subsystemes Reussi !\n");
   }
  
   window = SDL_CreateWindow("Simulator",150,150,640,480,0);
   if(window==NULL){
   	  printf("Erreur Lors de la Creation de la Fenetre \n");
   }else{
   	 printf("Creation de la Fenetre Reussi !\n");
   }

   renderer = SDL_CreateRenderer(window,-1,0);
   if(renderer==NULL){
   	  printf("Erreur Lors de la creation Du Renderer \n");
   }else{ 
   	 printf("Creation du renderer Reussi !\n");
   }
}

//double pointeur ça marche !

void systemInitializer2(SDL_Window **window,SDL_Renderer **renderer){
   if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
   	  printf("Erreur Lors de L Initialisation des SubSystem \n");
   }else{
   	  printf("Initialisation des subsystemes Reussi !\n");
   }
  
   *window = SDL_CreateWindow("Simulator",150,150,640,480,0);
   if(*window==NULL){
   	  printf("Erreur Lors de la Creation de la Fenetre \n");
   }else{
   	 printf("Creation de la Fenetre Reussi !\n");
   }

   *renderer = SDL_CreateRenderer(*window,-1,0);
   if(*renderer==NULL){
   	  printf("Erreur Lors de la creation Du Renderer \n");
   }else{ 
   	 printf("Creation du renderer Reussi !\n");
   }
}



int main(int argc,char *argv[]){
   SDL_Window *window = NULL;
   SDL_Renderer *renderer = NULL;
   systemInitializer1(window,renderer);
  // systemInitializer2(&window,&renderer);
   if(window==NULL)printf("Les changements ne sont pas produit ici : allocation de la memoire echouer avec un(\n");
   else printf("Window a bien ete cree !\n");
   SDL_Delay(2000);
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();

        gcc projet.c fonctions.c -lSDL2 -lSDL2_image -lSDL2_ttf -o projet

	return EXIT_SUCCESS;
}