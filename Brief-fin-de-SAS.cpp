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
	char statue[15];
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
		printf("-----------------------------ajouter des t%cches---------------------------------------\n",131);
	
	printf("\n\tentrer le nombre de tache a ajouter : ");
	scanf("%d",&n);
     tab[n] ; 

      n=size+n;    
    	for(int i=size;i<n;i++){
    	tab[i].dateCreation = tempActuelle();
		printf("\n################### La tache %d ####################\n",i+1)	;
		printf("\n\n\tentrer le titre  : ");
	    scanf(" %[^\n]s",tab[i].titre);
	    
	    printf("\n\n\tentrer la descrirtion : ");
	    scanf(" %[^\n]s",tab[i].description);
	    
	    printf("\n\n\tentrer le jour : ");
	    scanf("%d",&tab[i].date_echeance.jour);
	    
	    printf("\n\n\tentrer le mois : ");
	    scanf("%d",&tab[i].date_echeance.mois);
	    
	    printf("\n\n\tentrer l\'annee : ");
	    scanf("%d",&tab[i].date_echeance.annee);
	    verificationTemps(tab);
	    
	    printf("\n\n\tentrer la priorite (high or low) : ");
	    scanf(" %[^\n]s",tab[i].priorite);
	    
	    printf("\n\n\tentrer la statue (a_faire, en_cours, termine) : ");
	    scanf(" %[^\n]s",tab[i].statue);
	    size=i+1; 
						 }
	    
	}
	


//declaration de la fonction afficher
void afficher(struct tache tab[],int n ){
	//affichage des information de chaque personne
		printf("-----------------------------affichage des t%cches---------------------------------------\n",131);
	
	  
	  if (size==0){
	  		printf("\n\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	    	
	  for(int i=0;i<size;i++){ 
	    printf("\n\t ************************ information sur la tache: %d ***********************\t\n",i+1);
		printf(" \n\tTitre : %s\n \n\tDate de creation jj/mm/aaaa : %d/%d/%d\n \n\tDescriprtion : %s\n \n\tDate_echeance jj/mm/aaaa : %d/%d/%d\n \n\tPriorite : %s\n \n\tStatue : %s\n  ",tab[i].titre,tab[i].dateCreation.jour,tab[i].dateCreation.mois,tab[i].dateCreation.annee,tab[i].description,
		tab[i].date_echeance.jour,tab[i].date_echeance.mois,tab[i].date_echeance.annee,tab[i].priorite,tab[i].statue);
	   //size=i+1;
	}
	 }
}

//declaration de la fonction modifier
void modifier(struct tache tab[] ,int n ,int indice){
		printf("-----------------------------modifier une t%cche---------------------------------------\n",131);
	
	int c;
	if (size==0){
	  		printf("\n\til y\'a aucune tache a modifier il faut ajouter des taches au premier\n.");
	  }else{
	  	    printf("\n\tentrer l\'indice de la tache que voullez vous modifier: \n" );
	        scanf("%d", &indice);	         
	          if(indice>size){
	        	printf("\n\tvous avez depassez le nombre des taches");
	         }else{
			
	          do{
	printf("\n\n********************** menu de modification ************************ \t  \n");
    printf("\n\t\t1 : titre\n");
	printf("\n\t\t2 : description\n");
	printf("\n\t\t3 : date d'echeance\n");
	printf("\n\t\t4 : priorite\n");
	printf("\n\t\t5 : statue\n");
	printf("\n\t\t6 : tout les parametres\n");
	printf("\n\t\t7 : quitter\n");
	printf("\n\tchoisir le parametre a modifier de 1 a 6 : ");
	scanf("%d",&c);

	         switch(c){
	         	 case 1:
			        printf("\n\tentrer le nouveau titre de la tache %d : ",indice);
	                scanf("%s",tab[indice-1].titre);
		    	break;
		        case 2:
			        printf("\n\tentrer la nouvelle description de la tache %d : ",indice);
	                 scanf(" %[^\n]s",&tab[indice-1].description);
			    break;
		        case 3:
		        	int k;
		        	 do{
		        	 	//modification da la date
		        	printf("\n****************** menu de modification de la date **************** \t  \n");
                    printf("\n\t\t1 : jour\n");
	                printf("\n\t\t2 : mois\n");
					printf("\n\t\t3 : annee\n");
					printf("\n\t\t4 : date\n");
					printf("\n\t\t5 : quitter\n");
					printf("\n\tchoisir le parametre a modifier de 1 a 5 : ");
					scanf("%d",&k);
					switch(k){
					case 1:
			        	printf("\nentrer le nouveau jour de la tache %d : ",indice);
	                	scanf("%d",&tab[indice-1].date_echeance.jour);
		    		break;
		        	case 2:
			        	printf("\nentrer le nouveau mois de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.mois);
			    	break;
			    	case 3:
			        	printf("\nentrer la nouvelle annee de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.annee);
	                 	
			    	break;
			    	case 4:
			    		printf("\nentrer le nouveau jour de la tache %d : ",indice);
	                	scanf("%d",&tab[indice-1].date_echeance.jour);
	                	printf("+++++ le jour est modifiee +++++\n");
	                	printf("entrer le nouveau mois de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.mois);
	                 	printf("+++++ le mois est modifiee +++++\n");
	                 	printf("\nentrer la nouvelle annee de la tache %d : ",indice);
	                 	scanf("%d",&tab[indice-1].date_echeance.annee);
	                 	verificationTemps(tab);
	                 	printf("+++++ l\'annee est modifiee +++++\n");
	                break;
					case 5:
					break;
					default : printf("\nveuillez choisir 1 , 2 , 3 ,4 ou 5");
					break; 	
					}}
					while(k!=5);
			       
			    break;
	         	case 4:
			        printf("\n\tentrer la nouvelle priorite de la tache %d : ",indice);
	                scanf(" %[^\n]s",tab[indice-1].priorite);
		     	break;
		     	case 5:
			        printf("\n\tentrer la nouvelle statue de la tache %d : ",indice);
	                scanf(" %[^\n]s",tab[indice-1].statue);
		     	break;
		        case 6:
		          printf("\n\tentrer le nouveau titre de la tache %d : ",indice);
	              scanf(" %[^\n]s",tab[indice-1].titre);
	    
	              printf("\n\tentrer la nouvelle description de la tache %d : ",indice);
	              scanf(" %[^/]s",&tab[indice-1].description);
	    
	              	printf("\n\tentrer le nouveau jour de la tache %d : ",indice);
	            	scanf("%d",&tab[indice-1].date_echeance.jour);
	                printf("\n\tentrer le nouveau mois de la tache %d : ",indice);
	                scanf("%d",&tab[indice-1].date_echeance.mois);
	                printf("\n\tentrer la nouvelle annee de la tache %d : ",indice);
	                scanf("%d",&tab[indice-1].date_echeance.annee);
	                verificationTemps(tab);	     
	              	printf("\n\tentrer la nouvelle priorite de la tache %d : ",indice);
	              	scanf(" %[^\n]s",tab[indice-1].priorite);
	              	printf("\n\tentrer la nouvelle statue de la tache %d : ",indice);
	              	scanf(" %[^\n]s",tab[indice-1].statue);
			    break;
			    case 7:
			    	break;
		            default : printf("\nveuillez choisir 1 , 2 , 3 ,4 ou 5");
			 } }
			 while(c!=7);}
			 }}

//fonction afficher une tache
 void afficher_tache(struct tache tab[],int i){
 		printf("-----------------------------affichage d\'une t%cche-----------------------------------\n",131);
	
 	printf("\t \n******************* information sur la tache: %d *******************\t\n",i+1);
		printf(" \tTitre : %s\n \tDate de creation jj/mm/aaaa : %d/%d/%d\n \tDescriprtion : %s\n \tDate_echeance : \n \tJour / Mois / Annee : \t%d / %d / %d\n \tPriorite : %s\n \tStatue : %s\n  ",tab[i].titre,tab[i].dateCreation.jour,tab[i].dateCreation.mois,tab[i].dateCreation.annee,tab[i].description,
		tab[i].date_echeance.jour,tab[i].date_echeance.mois,tab[i].date_echeance.annee,tab[i].priorite,tab[i].statue);
 }
      
//declaration de la fonction filtrer_par_priorite
void filtrer_par_priorite(struct tache tab[]){
		printf("-----------------------------filtrage par priorit%c---------------------------------------\n",130);
	
	if (size==0){
	  		printf("\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	char fp[15];
	printf("\tentrer le type de priorite (low/high) recherchee: ");
	scanf(" %[^\n]s",fp);
	int found=0;
	for(int i=0;i<size;i++){
		if(strcmp(tab[i].priorite,fp)==0){
			afficher_tache(tab,i);	   
			found=1;
		}
	}
	if(!(found)){
		 printf("aucune tache avec cette prioritee.\n");
	}
	
}}

//declaration de la fonction filtrer_par_statue
void filtrer_par_statue(struct tache tab[]){
		printf("----------------------------- filtrage par statue ---------------------------------------\n");
	if (size==0){
	  		printf("\n\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{	
	char fs[15];
	printf("\n\tentrer le type de statue (a_faire, en_cours, termine) recherchee: ");
	scanf(" %[^\n]s",fs);
	int found=0;
	for(int i=0;i<size;i++){
		if(strcmp(tab[i].statue,fs)==0){
			afficher_tache(tab,i);	   
			found=1;
		}
	}
	if(!(found)){
		 printf("\n\taucune tache avec cette statue.\n");
	}
	
}}

//declaration de la fonction filtrer_par_date_creation

 void filtrer_par_date_creation(struct tache tab[]){
 	printf("-----------------------------filtrage par date de cr%cation-----------------------------------\n",130);
	
	int j,m,an,found=0;
		if (size==0){
	  		printf("\n\til y\'a aucune tache a afficher il faut ajouter des taches au premier\n.");
	  }else{
	printf("\n\tentrer le jour (jj) recherchee: ");
	scanf("%d",&j);
	printf("\n\tentrer le mois (mm) recherchee: ");
	scanf("%d",&m);
	printf("\n\tentrer l\'annee (aaaa) recherchee: ");
	scanf("%d",&an);
	for(int i=0;i<size;i++){
		if(tab[i].dateCreation.jour == j && tab[i].dateCreation.mois == m && tab[i].dateCreation.annee == an){
			afficher_tache(tab,i);
			found=1;
		}}
	if(!(found)){
		printf("\n\taucune tache exist avec cette date de creation .\n");
	}
	
}}




//declaration de la methode supprimer_par_indice
void supprimer_par_indice(struct tache tab[] ,int n ,int indice){
	printf("-----------------------------supprimer par indice---------------------------------------\n",130);
	
		if (size==0){
	  		printf("\n\til y\'a aucune tache a supprimer il faut ajouter des taches au premier\n.");
	  }else{
	  	printf("\n \tentrer l\'indice de la tache que voullez vous suprimer: " );
	    scanf("%d", &indice);
	       if(indice>size){
		       printf("\n\tvous avez depassez le nombre des taches");
	       }else{
		       for (int i = indice-1; i<n; i++){
		    	tab[i]=tab[i+1];
		
	    	}
	    	size--;
		printf("\n\t**La tache %d a ete supprimee**\n",indice);
	
	}}
}

//declaration de la methode supprimer_par_statue
void supprimer_par_statue(struct tache tab[] ,int n){
	printf("-----------------------------supprimer par statue---------------------------------------\n",130);
	
		if (size==0){
	  		printf("\n\til y\'a aucune tache a supprimer il faut ajouter des taches au premier\n.");
	  }else{	
	   	char fs[15];
		printf("\n\tentrer le type de statue (a_faire, en_cours, termine) recherchee: ");
		scanf(" %[^\n]s",fs);
		int found=0;
		for(int i=0;i<size;i++){
		if(strcmp(tab[i].statue,fs)==0){
			tab[i]=tab[i+1];	   
			found=1;
				size--;
		}
	}
			printf("\n\t**Les taches avec priorite %s ont ete supprimee**\n",fs);
	if(!(found)){
		 printf("\n\taucune tache avec cette statue.\n");
	}	
	}}
	
	
//declaration de la fonction filtrer_par_date_creation

 void supprimer_par_date_creation(struct tache tab[]){
 	printf("-----------------------------supprimer par date de cr%ation-----------------------------------\n",130);
	
      	int j,m,an,found=0;
		if (size==0){
	  		printf("\n\til y\'a aucune tache a supprimer, il faut ajouter des taches au premier\n.");
	  }else{
	printf("\n\tentrer le jour (jj) recherchee: ");
	scanf("%d",&j);
	printf("\n\tentrer le mois (mm) recherchee: ");
	scanf("%d",&m);
	printf("\n\tentrer l\'annee (aaaa) recherchee: ");
	scanf("%d",&an);
	for(int i=0;i<size;i++){
		if(tab[i].dateCreation.jour == j && tab[i].dateCreation.mois == m && tab[i].dateCreation.annee == an){
			tab[i]=tab[i+1];
			found=1;
				size--;
		}printf("\n\t**Les taches avec cette date de creation %d/%d/%d ont ete supprimee**\n",j,m,an);
		}
		
	if(!(found)){
		printf("\n\taucune tache exist avec cette date de creation .\n");
	}
	
}
 }


int main(){	
	struct tache tab[1000]; // Un tableau pour stocker jusqu'à n tache 
   do{
	printf("********************************** Menu ********************************\t\t  \n");
    printf("\t\t\t1 : ajouter\n\n");
	printf("\t\t\t2 : afficher\n\n");
	printf("\t\t\t3 : modifier\n\n");
	printf("\t\t\t4 : filtrer\n\n");
	printf("\t\t\t5 : supprimer\n\n");
	printf("\t\t\t6 : quitter\n\n");
	printf("\t\tchoisir un nombre de 1 a 6 : ");
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
				printf("\n\n\*********************menu filtrage*******************\n");
				printf("\n\t 1:filtrer_par_priorite\n");
				printf("\n\t 2:filtrer_par_date_creation\n");
				printf("\n\t 3:filtrer_par_statue\n");
				printf("\n\t 4:quitter\n");
				printf("\n\tentrer votre choix: ");
				scanf("%d",&f);
				switch(f){
					case 1:
						filtrer_par_priorite(tab);
					break;
					case 2:
						filtrer_par_date_creation(tab);
					break;
					case 3:
						filtrer_par_statue(tab);
					break;
					case 4:
						break;
					default : printf("\tchoix non reconu!!");
	
				}
				
			  }
			  while(f!=4);
			break;
		case 5:
			int s;
			  do{
				printf("\\n\n\t*********************menu supprission*********************\n");
				printf("\t 1:supprimer_par_indice\n");
				printf("\t 2:supprimer_par_date_creation\n");
				printf("\t 3:supprimer_par_statue\n");
				printf("\t 4:quitter\n");
				printf("\tentrer votre choix: ");
				scanf("%d",&s);
				switch(s){
					case 1:
						supprimer_par_indice(tab,n,indice);
					break;
					case 2:
						supprimer_par_date_creation(tab);
					break;
					case 3:
						supprimer_par_statue(tab,n);
					break;
					case 4:
						break;
					default : printf("\tchoix non reconu!!");
	
				}	
			  }
			  while(s!=4);			
			break;
		case 6:
			break;
  default : printf("\tveuillez choisir un nombre parmie les nombres exist dans le menu!!");

	
}}
 while (choix != 6);
return 0;
}


