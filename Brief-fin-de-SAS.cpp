#include<stdio.h>
#include<time.h>
#include<string.h>
int size =0;
int choix, n ,indice ;

//declaration de la structure date
struct Date{
	int jour;
	int mois;
	int annee;
};

//declaaration de la structure Tache
struct tache{
	struct Date dateCreation;
	char titre[100];
	char description[1000]; 
    struct Date date_echeance;
	char priorite[15];
};
//declaration de la fonction tempActuelle pour retourné le temps d'aujourd'hui
struct Date tempActuelle(){
	struct Date t;
	time_t tempactuelle;//instance de la structue time_t : variable specifique existe dans le fichier <time.h>
	time(&tempactuelle);
		//convertir time_t ---> tm struct (seconds ---> string)en utilisant la fonction localtime
	struct tm *nowTime = localtime(&tempactuelle);
	t.annee = nowTime->tm_year+1900;
	t.mois = nowTime->tm_mon+1;
	t.jour = nowTime->tm_mday;
	return t;
	
}

//declaration de la methode verification du temps entree
void verificationTemps(struct tache tab[]){
	int i;
	while(1){
	
	if (tab[i].date_echeance.annee <tab[i].dateCreation.annee ||
                     (tab[i].date_echeance.annee == tab[i].dateCreation.annee && 
                      (tab[i].date_echeance.mois < tab[i].dateCreation.mois || tab[i].date_echeance.mois > 12)) ||
                     (tab[i].date_echeance.annee == tab[i].dateCreation.annee &&
                      tab[i].date_echeance.mois == tab[i].dateCreation.mois &&
                      (tab[i].date_echeance.jour < tab[i].dateCreation.jour ||tab[i].date_echeance.jour > 31))) {
                printf("La date d\'echeance est inferieure a la date actuelle ou la valeur du jour ou mois est invalide.\n Entrer une nouvelle date pour la tache %d :\n", i + 1);
                printf("Année : ");
                scanf("%d", &tab[i].date_echeance.annee);
                printf("Mois : ");
                scanf("%d", &tab[i].date_echeance.mois);
                printf("Jour : ");
                scanf("%d", &tab[i].date_echeance.jour);
            } 
            // Sortir de la boucle si la date est valide
            else {
                break;
            }
	
		}
}

//declaration de la methode ajouter
void ajouter (struct tache tab[] ){
	printf("entrer le nombre de tache a ajouter : ");
	scanf("%d",&n);
     tab[n] ; 

      n=size+n;
	
     
    	for(int i=size;i<n;i++){
    	tab[i].dateCreation = tempActuelle();
		printf("*********tache %d *********\n",i+1)	;
		printf("entrer le titre  : ");
	    scanf(" %[^\n]s",tab[i].titre);
	    
	    printf("entrer la descrirtion : ");
	    scanf(" %[^\n]s",tab[i].description);
	    
	    printf("entrer le jour : ");
	    scanf("%d",&tab[i].date_echeance.jour);
	    
	    printf("entrer le mois : ");
	    scanf("%d",&tab[i].date_echeance.mois);
	    
	    printf("entrer l\'annee : ");
	    scanf("%d",&tab[i].date_echeance.annee);
	    verificationTemps(tab);
	    
	    printf("entrer la priorite (high or low) : ");
	    scanf(" %[^\n]s",tab[i].priorite);
	    size=i+1; 
						 }
	    
	}
	


//declaration de la fonction afficher
void afficher(struct tache tab[],int n ){
	//affichage des information de chaque personne
	  
	  if (size==0){
	  		printf("\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	    	
	  for(int i=0;i<size;i++){ 
	    printf("\t ********** information sur la tache: %d **********\t\n",i+1);
		printf(" \tTitre : %s\n \tDate de creation jj/mm/aaaa : %d/%d/%d\n \tDescriprtion : %s\n \tDate_echeance jj/mm/aaaa : %d/%d/%d\n \tPriorite : %s\n  ",tab[i].titre,tab[i].dateCreation.jour,tab[i].dateCreation.mois,tab[i].dateCreation.annee,tab[i].description,
		tab[i].date_echeance.jour,tab[i].date_echeance.mois,tab[i].date_echeance.annee,tab[i].priorite);
	   //size=i+1;
	}
	 }
}

//declaration de la fonction modifier
void modifier(struct tache tab[] ,int n ,int indice){
	int c;
	if (size==0){
	  		printf("\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	  	    printf("\n\tentrer l\'indice de la tache que voullez vous modifier: \n" );
	        scanf("%d", &indice);	         
	          if(indice>size){
	        	printf("\tvous avez depassez le nombre des taches");
	         }else{
			
	          do{
	printf("******** menu de modification ******** \t  \n");
    printf("\t\t1 : titre\n");
	printf("\t\t2 : description\n");
	printf("\t\t3 : date d'echeance\n");
	printf("\t\t4 : priorite\n");
	printf("\t\t5 : tout les parametres\n");
	printf("\t\t6 : quitter\n");
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
		        	int k;
		        	 do{
		        	 	//modification da la date
		        	printf("******** menu de modification de la date ******** \t  \n");
                    printf("\t\t1 : jour\n");
	                printf("\t\t2 : mois\n");
					printf("\t\t3 : annee\n");
					printf("\t\t4 : date\n");
					printf("\t\t5 : quitter\n");
					printf("\tchoisir le parametre a modifier de 1 a 5 : ");
					scanf("%d",&k);
					switch(k){
					case 1:
			        	printf("entrer le nouveau jour de la tache %d : ",indice);
	                	scanf("%d",&tab[indice-1].date_echeance.jour);
		    		break;
		        	case 2:
			        	printf("entrer le nouveau mois de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.mois);
			    	break;
			    	case 3:
			        	printf("entrer la nouvelle annee de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.annee);
	                 	if(tab[indice-1].date_echeance.annee<2024){
	                 		printf("cette date est deja depasser.\n");
						 }
			    	break;
			    	case 4:
			    		printf("entrer le nouveau jour de la tache %d : ",indice);
	                	scanf("%d",&tab[indice-1].date_echeance.jour);
	                	printf("le jour est modifiee");
	                	printf("entrer le nouveau mois de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.mois);
	                 	printf("le mois est modifiee");
	                 	printf("entrer la nouvelle annee de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.annee);
	                 	verificationTemps(tab);
	                 	printf("l\'annee est modifiee");
	                break;
					case 5:
					break;
					default : printf("veuillez choisir 1 , 2 , 3 ,4 ou 5");
					break; 	
					}}
					while(k!=5);
			       
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
	    
	              	printf("entrer le nouveau jour de la tache %d : ",indice);
	            	scanf("%d",&tab[indice-1].date_echeance.jour);
	                printf("entrer le nouveau mois de la tache %d : ",indice);
	                scanf("%d",&tab[indice-1].date_echeance.mois);
	                printf("entrer la nouvelle annee de la tache %d : ",indice);
	                scanf("%d",&tab[indice-1].date_echeance.annee);
	                verificationTemps(tab);	     
	              	printf("entrer la nouvelle priorite de la tache %d : ",indice);
	              	scanf("%s",tab[indice-1].priorite);
			    break;
			    case 6:
			    	break;
		            default : printf("veuillez choisir 1 , 2 , 3 ,4 ou 5");
			 } }
			 while(c!=6);}
			 }}

//fonction afficher une tache
 void afficher_tache(struct tache tab[],int i){
 	printf("\t ********** information sur la tache: %d **********\t\n",i+1);
		printf(" \tTitre : %s\n \tDate de creation jj/mm/aaaa : %d/%d/%d\n \tDescriprtion : %s\n \tDate_echeance : \n \tJour / Mois / Annee : \t%d / %d / %d\n \tPriorite : %s\n  ",tab[i].titre,tab[i].dateCreation.jour,tab[i].dateCreation.mois,tab[i].dateCreation.annee,tab[i].description,
		tab[i].date_echeance.jour,tab[i].date_echeance.mois,tab[i].date_echeance.annee,tab[i].priorite);
 }
      
//declaration de la fonction filtrer_par_priorite
void filtrer_par_priorite(struct tache tab[]){
	if (size==0){
	  		printf("\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	
	char fp[15];
	printf("\tentrer le type de priorite (low/high) recherchee: ");
	scanf("%s",fp);
	int found=0;
	for(int i=0;i<size;i++){
		if(strcmp(tab[i].priorite,fp)==0){
			afficher_tache(tab,i);	   
			found=1;
		}
	}
	if(!(found)){
		 printf("La priorite que vous avez entree n\'existe pas.\n");
	}
	
}}

//declaration de la fonction filtrer_par_date_creation

 /*void filtrer_par_date_creation(struct tache tab[]){
	int j,m,an,found=0;
		if (size==0){
	  		printf("\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	printf("\tentrer le jour (jj) recherchee: ");
	scanf("%d",&j);
	printf("\tentrer le mois (mm) recherchee: ");
	scanf("%d",&m);
	printf("\tentrer l\'annee (aaaa) recherchee: ");
	scanf("%d",&an);
	for(int i=0;i<size;i++){
		if(tab[i].dateCreation.jour == j && tab[i].dateCreation.mois == m && tab[i].dateCreation.annee == an){
			afficher_tache(tab,i);
			found=1;
		}}
	if(!(found)){
		printf("aucune tache exist avec cette date de creation .\n");
	}
	
}}*/


//declaration de la methode supprimer
void supprimer(struct tache tab[] ,int n ,int indice){
	
		if (size==0){
	  		printf("\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	  	printf("\n \tentrer l\'indice de la tache que voullez vous suprimer: " );
	    scanf("%d", &indice);
	       if(indice>size){
		       printf("\tvous avez depassez le nombre des taches");
	       }else{
		       for (int i = indice-1; i<n; i++){
		    	tab[i]=tab[i+1];
		
	    	}
	    	size--;
		printf("\t**La tache %d a ete supprimee**\n",indice);
	
	}}
}

int main(){	
	struct tache tab[1000]; // Un tableau pour stocker jusqu'à n tache 
   do{
	printf("\t\t ************ menu ************\t\t  \n");
    printf("\t\t\t1 : ajouter\n\n");
	printf("\t\t\t2 : afficher\n\n");
	printf("\t\t\t3 : modifier\n\n");
	printf("\t\t\t4 : filtrer\n\n");
	printf("\t\t\t5 : supprimer\n\n");
	printf("\t\t\t6 : quitter\n\n");
	printf("\t\tchoisir un nombre de 1 a 4 : ");
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
		    
		       int f;
			  do{
				printf("\t*****menu filtrage*****\n");
				printf("\t 1:filtrer_par_priorite\n");
				printf("\t 2:filtrer_par_date_creation\n");
				printf("\t 3:quitter\n");
				printf("\tentrer votre choix: ");
				scanf("%d",&f);
				switch(f){
					case 1:
						filtrer_par_priorite(tab);
					break;
					case 2:
						filtrer_par_date_creation(tab);
					break;
					case 3:
					break;
					default : printf("\tchoix non reconu!!");
	
				}
				
			  }
			  while(f!=3);
			break;
		case 5:
			supprimer(tab,n,indice);
			break;
		case 6:
			break;
  default : printf("\tveuillez choisir un nombre parmie les nombres exist dans le menu!!");

	
}}
 while (choix != 6);
return 0;
}


