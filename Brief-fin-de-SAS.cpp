#include<stdio.h>

int size =0;
int choix, n ,indice ;

//declaration de la structure date
struct Date{
	int jour;
	char mois[50];
	int annee;
};

//declaaration de la structure Tache
struct tache{
	char titre[100];
	char description[1000]; 
    struct Date date_echeance;
	char priorite[15];
};




//declaration de la methode ajouter
void ajouter (struct tache tab[] ){
	printf("entrer le nombre de tache a ajouter : ");
	scanf("%d",&n);
     tab[n] ; 

      n=size+n;
	
     
    	for(int i=size;i<n;i++){
		printf("entrer le titre de la tache %d : ",i+1);
	    scanf("%99s",tab[i].titre);
	    
	    printf("entrer la descrirtion de la tache %d : ",i+1);
	    scanf("%999s",tab[i].description);
	    
	    printf("entrer le jour de la tache %d : ",i+1);
	    scanf("%d",&tab[i].date_echeance.jour);
	    
	    printf("entrer le mois de la tache %d : ",i+1);
	    scanf("%49s",tab[i].date_echeance.mois);
	    
	    printf("entrer l\'annee de la tache %d : ",i+1);
	    scanf("%d",&tab[i].date_echeance.annee);
	    
	    printf("entrer la priorite de la tache %d (high or low) : ",i+1);
	    scanf("%14s",tab[i].priorite);
	    // Lire jusqu'à la fin de la ligne
    // Le format %99[^\n] lit jusqu'à 99 caractères ou jusqu'à un retour à la ligne
	    size=i+1;
	}
	
}

//declaration de la fonction afficher
void afficher(struct tache tab[],int n ){
	//affichage des information de chaque personne
	  
	  if (size==0){
	  		printf("il y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	    	
	  for(int i=0;i<size;i++){ 
	    printf("\t ********** information sur les taches: %d**********\t\n",i+1);
		printf(" Titre : %s\n Descriprtion : %s\n +++++ Date_echeance : \n Jour : %d\n Mois : %s\n Annee : %d\nPriorite : %s\n  ",tab[i].titre,tab[i].description,
		tab[i].date_echeance.jour,tab[i].date_echeance.mois,tab[i].date_echeance.annee,tab[i].priorite);
	   //size=i+1;
	}
	 }
}

//declaration de la fonction modifier
void modifier(struct tache tab[] ,int n ,int indice){
	int c;
	if (size==0){
	  		printf("il y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	  	    printf("\nentrer l\'indice de la tache que voullez vous modifier: " );
	        scanf("%d", &indice);	         
	          if(indice>size){
	        	printf("vous avez depassez le nombre des taches");
	         }else{
			
	          do{
	printf("******** menu de modification ******** \t  \n");
    printf("\t1 : titre\n");
	printf("\t2 : description\n");
	printf("\t3 : date d'echeance\n");
	printf("\t4 : priorite\n");
	printf("\t5 : tout les parametres\n");
	printf("\t6 : quitter\n");
	printf("\tchoisir le parametre a modifier de 1 a 6 : ");
	scanf("%d",&c);

	         switch(c){
	         	 case 1:
			        printf("entrer le nouveau titre de la tache %d : ",indice);
	                scanf("%s",tab[indice-1].titre);
		    	break;
		        case 2:
			        printf("entrer la nouvelle description de la tache %d : ",indice);
	                 scanf("%s",&tab[indice-1].description);
			    break;
		        case 3:
			       printf("entrer la nouvelle date d\'echeance de la tache %d : ",indice);
	               scanf("%s",tab[indice-1].date_echeance);
			    break;
	         	case 4:
			        printf("entrer la nouvelle priorite de la tache %d : ",indice);
	                scanf("%s",tab[indice-1].priorite);
		     	break;
		        case 5:
		          printf("entrer le nouveau titre de la tache %d : ",indice);
	              scanf("%s",tab[indice-1].titre);
	    
	              printf("entrer la nouvelle description de la tache %d : ",indice);
	              scanf("%s",&tab[indice-1].description);
	    
	              printf("entrer la nouvelle date d\'echeance de la tache %d : ",indice);
	              scanf("%s",tab[indice-1].date_echeance);
	     
	              printf("entrer la nouvelle priorite de la tache %d : ",indice);
	              scanf("%s",tab[indice-1].priorite);
			    break;
			    case 6:
			    	break;
		            default : printf("veuillez choisir 1 , 2 , 3 ou 4");
			 } }
			 while(c!=6);}
			 }}

      


//declaration de la methode supprimer
void supprimer(struct tache tab[] ,int n ,int indice){
	
		if (size==0){
	  		printf("il y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	  	printf("\n entrer l\'indice de la tache que voullez vous suprimer: " );
	    scanf("%d", &indice);
	       if(indice>size){
		       printf("vous avez depassez le nombre des taches");
	       }else{
		       for (int i = indice-1; i<n; i++){
		    	tab[i]=tab[i+1];
		
	    	}
	    	size--;
		printf("La tache %d a ete supprimee\n",indice);
	
	}}
}

int main(){	
	struct tache tab[1000]; // Un tableau pour stocker jusqu'à n tache 
   do{
	printf("\t ******** menu ********\t  \n");
    printf("\t\t1 : ajouter\n");
	printf("\t\t2 : afficher\n");
	printf("\t\t3 : modifier\n");
	printf("\t\t4 : supprimer\n");
	printf("\t\t5 : quitter\n");
	printf("\tchoisir un nombre de 1 a 4 : ");
	scanf("%d",&choix);
	switch(choix){
		case 1: 
		    ajouter(tab);
			break;
		case 2:
			afficher(tab,n);
			break;
		case 3:
			modifier(tab,n, indice);
			break;
		case 4:
			supprimer(tab,n,indice);
			break;
		case 5:
			break;
  default : printf("veuillez choisir 1 , 2 , 3 ou 4");

	
}}
 while (choix != 5);
return 0;
}


