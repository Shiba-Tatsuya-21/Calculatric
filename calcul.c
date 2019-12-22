#include <stdio.h>
#include <math.h>

int estnegatif=0;
char signeresultatfinal='0';


int multiplication (int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int lig_res=0;
  int pos_res=0;
  int pos_j=0;
  int pos_i=0;
  int pos=0;

  int valeur,res, nI;
  long n;
  long base=1;
  int numerateur=0;
  int retenue=0;
  int tailleres=0;
  int tableauresultat[1000][1000];

  while (pos_j < j)
    {
      retenue=0;
      numerateur=tableau2[pos_j];
      pos_i=0;
      while (pos_i < i)
	{
	  valeur = tableau1[pos_i] * numerateur +retenue;
	  res=valeur%10;
	  retenue = (valeur-res)/10; 
	  tableauresultat[pos_j][pos_i+pos_j]=res;
  	  pos_i++;
	}

      if (retenue>0)
	{
	  tableauresultat[pos_j][pos_i+pos_j]=retenue;
	  pos_i++;
	}

      pos_j++;
    }

  // logtab2dim(tableauresultat, pos_j, pos_i+pos_j-1);

  pos=0;
  while (pos <= pos_j)
    {
    tailleres=addition(tableaures,tableaures, tableauresultat[pos],tailleres,pos_i+pos_j-1) ;
    pos++;
    }

  // resize(tableaures,tailleres);
  // invtab(tableaures,tailleres);
  // logtab(tableaures,tailleres);

return tailleres;
}


int logtab2dim(int tab[1000][1000],int ligne, int col){
    int i=0;
    int j=0;

    for(i=0;i<ligne;i++)
      {	j=0;
	printf("ligne %d: ", i);
	for( j=0;j<col;j++)
	  {
	    printf("%d",tab[i][j]);
	  }
	printf("\n");
      }
  }

int resize(int tableau[], int TailleDuTableau)
{
  
  while (TailleDuTableau >= 0 && tableau[TailleDuTableau - 1] == 0 )
    {
      if ( TailleDuTableau == 0 )
	return 1;
      --TailleDuTableau;
    }
  
  return TailleDuTableau ;
}

int logtab(int tab[], int c){
    int i;
    for(i=0;i<c;i++){
      printf("%d",tab[i]);
    }
    printf("\n");
  }

int logtabchar(int tab[], int c){
    int i;
    for(i=0;i<c;i++){
      printf("%c",tab[i]+'0');
    }
    printf("\n");
  }

 
int invtab(int tab[],int taille){

  int i;
  int inv;
 
  for(i=0;i<taille/2;i++){
    inv=tab[i];
    tab[i]=tab[taille-(i+1)];
    tab[taille-(i+1)]=inv;
  }
 }

int estnumeric(char nb){
    return (nb=='0' || nb=='1' || nb=='2' ||nb=='3' || nb=='4' || nb=='5' || nb=='6' || nb=='7' || nb=='8' || nb=='9');
  }


int maximum( int long1, int long2 ){
    int n;
    if (long1>long2)
      n=long1;
    else 
      n=long2;

    //  printf("maximum:%d\n", n);
    return n;
  }

int addition(int tableaures[], int tableau1[], int tableau2[], int i, int j ){

    int pos=0; 
    int valeur1=0;
    int valeur2=0;
    int res;
    int retenue=0;
    int longueur=maximum(i,j);

    while(pos < longueur)
      {
	if (pos<i)
	  valeur1=tableau1[pos];	
	else
	  valeur1=0;


	if (pos<j)
	  valeur2=tableau2[pos];	
	else
	  valeur2=0;
	
	res =valeur1+valeur2+retenue;

	retenue=0;

	if (res>9)
	  {
	    tableaures[pos]=res-10;
	    retenue=1;	  
	  }    
	else
	  {
	    tableaures[pos]=res;
	    retenue=0;
	  }  
	pos++; 
      }
    
    if (retenue==1)
      {
	tableaures[pos]=1;
	pos++;
      }
    return pos;
  }


int soustraction(int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int pos=0;
  int valeur1=0;
  int valeur2=0;
  int res,imax,jmax;
  int retenue=0;
  
  int longueur=maximum(i,j);
  
  estnegatif=0;
  
  if (j>i)
    estnegatif=1;
  
  if (i==j)
    {   
       res=estplusgrandentier(tableau1,tableau2,i);
       if (res==1)
	 imax=1;
       if (res==2)
	 {
	   jmax=1;
	   estnegatif=1;
	 }      
       if (res==0)
	 {
	   imax=1;
	   estnegatif=0;
	 }
    }
  
   while(pos < longueur){
     
     if (pos<i)
       valeur1=tableau1[pos];	
     else
       valeur1=0;
     
     if (pos<j)
       valeur2=tableau2[pos];	
     else
       valeur2=0;

     if (i>j || imax==1)
       {
	 if(valeur1<valeur2){ 
	   tableaures[pos]=10+valeur1-valeur2-retenue;
	   retenue=1;
	 }
	 else if(valeur1>valeur2){
	   tableaures[pos]=valeur1-valeur2-retenue;
	   retenue=0;
	 }
	 else if(valeur1==valeur2 && retenue==1) {
	    tableaures[pos]=10+valeur1-valeur2-retenue;
	   retenue=1; 
	 }
       }
     if (i<j || jmax==1)
       {
	 if(valeur2<valeur1 ){ 
	   tableaures[pos]=valeur2-valeur1-retenue+10;
	   retenue=1;
	 }
	 else if(valeur2>valeur1){
	   tableaures[pos]=valeur2-valeur1-retenue;
	   retenue=0;
	 }
	 else if(valeur1==valeur2 && retenue==1){
	   tableaures[pos]=10+valeur2-valeur1-retenue;
	   retenue=1; 
	 }
       }     
    pos++;
   }
    if(retenue==1){
     tableaures[pos]=1;
     pos++;
     }
    return resize(tableaures,pos);
}




int multiplication_old (int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int pos=0;
  int valeur,nI;
  long n;
  long base=1;
  int tailleres=0;
 
  if (i>=j)
    {
      while(pos<j){
	
	valeur=tableau2[pos];
	n =valeur*(base);
	
	for(nI=1;nI<=n;nI++){
	  tailleres= addition(tableaures,tableaures,tableau1,tailleres,i);
	}
	base=base*10;
	logtab(tableaures,tailleres);
	pos++;
      }
    }
  else
    {
      while(pos<i){
	
	valeur=tableau1[pos];
	n =valeur*(base);
	
	for(nI=1;nI<=n;nI++){
	  tailleres= addition(tableaures,tableaures,tableau2,tailleres,j);
	}
	base=base*10;
	logtab(tableaures,tailleres);
	pos++;
    }

  
    }
return tailleres;
}



int estplusgrandentier(int tableau1[],int tableau2[],int i)
  // funtion retourne plus grand entier lorsque les deux tableaux ont la meme longueur
  {
    int res=1;
    int pos=i-1;
    while (pos>=0)
      {
	
	if ( tableau1[pos] != tableau2[pos] )
	  {
	    if (tableau1[pos]>tableau2[pos])
	      return 1;
	    else
	      return 2;
	  }
	else
	  {
	    res=0;
	  }
	
	pos--;
      }
    return res;
  }




int division (int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int pos=0;
  int valeur,res,nI,pos_i,pos_res;
  long n;
  long base=1;
  int mini;
  int tailleresultat=i;
  int tailleres=0;

  int tableaudeun[1]={1};
  int tableauresultat[100];
  int tableaudenum[100];
  int tableaudezero[1]={0};

  if (i < j ) 
    {
      tailleres = addition(tableaures, tableaures,tableaudezero,1,1) ;
      return tailleres;
    }

  if (i==j)
    {
      res = estplusgrandentier(tableau1, tableau2, i ) ;
      if( res==2)
	{
	  tailleres = addition(tableaures, tableaures,tableaudezero,1,1) ;
	  return tailleres;
	} 
    }     
  

 
  nI=1;
   
  // initialise le numerateur(tableau1) a la longueur du tableau2 'j'
  pos=0;
  invtab(tableau1, i);

  while (pos<j)  
    {
      tableauresultat[pos]=tableau1[pos];
      pos++;
    }
  invtab(tableau1, i);
  invtab(tableauresultat, pos);
  
  printf("tableau1 long tab2:\n");
  logtab(tableauresultat, j);

  // nombre de chiffre du résultat à traiter
  pos_i = 1 + (i - j);

  // si le numérateur est plus petit que le denominateur(on ajoute un chiffre).
  res=estplusgrandentier(tableauresultat,tableau2,j);
  if (res==2)
    {
      pos=0;
      invtab(tableau1, i);
      while (pos<j+1)  
	{
	  tableauresultat[pos]=tableau1[pos];
	  pos++;
	}
      invtab(tableau1, i);
      invtab(tableauresultat, pos);
      printf("tableau1 v 2:\n");
      logtab(tableauresultat, pos);      
      pos_i=pos_i-1;
    }



  // indice du tableau de resultat
  pos_res=0;

  while (nI <=pos_i)
    {
      
      // initialise tabledenum avec le tableau2 (1 fois)
      tailleres= addition(tableaudenum,tableaudezero, tableau2,1, j); 
      
      res= estplusgrandentier(tableauresultat,tableaudenum,j);

      while (res==1)
	{
	  
	  if (res==1)
	    {
	      //tableaures[pos_res]= tableaures[pos_res] + 1;
	      tailleres = addition(tableaures, tableaures, tableaudeun,1,1);
	      tailleres = addition(tableaudenum,tableaudenum, tableau2,tailleres, j);
	    }
	  else if (res==2)
	    {
	      // tableaures[pos_res]= tableaures[pos_res] - 1;
	      tailleres = soustraction (tableaures, tableaures, tableaudeun, 1,1);
	      tailleres = soustraction(tableaudenum,tableaudenum, tableau2,tailleres, j);
	    }
	  res= estplusgrandentier(tableauresultat,tableaudenum,j);
	}
      printf("tabl resultat:\n");
      logtab(tableaudenum, j);
      
      // calcul du nouveau resultat 
      tailleres = soustraction(tableauresultat, tableauresultat, tableaudenum, j, tailleres);
      tailleres = resize(tableauresultat,tailleres);
      
      //logtab(tableaures, pos_res);
      if (tailleres<j)
	{
	  while (tailleres < j)
	    {
	      tableauresultat[j+nI]=tableau1[j+nI];
	      pos_res++;
	      nI++;
	      tableaures[pos_res]=0;
	    }
	}
      else
	{
	  nI++;
	  pos_res++;
	}  
    }
  
  invtab(tableaures,pos_res);
  
  //    logtab(tableaures, pos_res);
  tailleres=resize(tableaures,pos_res);
  
return resize(tableaures,tailleres);

}













int division_old (int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int pos=0;
  int valeur,res,nI;
  long n;
  long base=1;
  int mini;
  int tailleresultat=i;
  int tailleres=0;

  int tableaudeun[1]={1};
  int tableauresultat[100]={0};

  if (i < j ) 
    {
      tailleres = addition(tableaures, tableaures,tableauresultat,1,1) ;
      return tailleres;
    }

  if (i==j)
    {
      res = estplusgrandentier(tableau1, tableau2, i ) ;
      if( res==2)
	{
	  tailleres = addition(tableaures, tableaures,tableauresultat,1,1) ;
	  return tailleres;
	} 
    }     

 
  res=estplusgrandentier(tableauresultat, tableau1, tailleresultat);
  
   while ( res==2 ) 
    {
     res=estplusgrandentier(tableauresultat, tableau1, tailleresultat);
     if(res==2)
       {
	 tailleresultat = addition(tableauresultat,tableauresultat,tableau2,tailleresultat, j);
	 tailleres = addition(tableaures, tableaures,tableaudeun,tailleres,1) ;
	 res=estplusgrandentier(tableauresultat, tableau1, tailleresultat);
	 if (res==1)
	   {
	     tailleres=soustraction(tableaures,tableaures,tableaudeun,tailleres,1);
	   }
       }
     else
       res=1;
   
    }
  return resize(tableaures,tailleres);
}
  




int modulo (int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int pos=0;
  int valeur,res,nI;
  long n;
  long base=1;
  int mini;
  int tailleresultat=i;
  int tailleres=0;

  int tableaudeun[1]={1};
  int tableauresultat[100]={0};

  if (i < j ) 
    {
      tailleres = i;
  
      while(pos<i){
	tableaures[pos]=tableau1[pos];
	pos++;
      }
    return tailleres;
    }

  if (i==j)
    {
      res = estplusgrandentier(tableau1, tableau2, i ) ;

      if(res==0){
	tailleres=1;
      tableaures[0]=0;
      return tailleres;
      }
   
      if( res==2)
	{
	  tailleres = i;
	  
	  while(pos<i){
	    tableaures[pos]=tableau1[pos];
	    pos++;
	  }
	  return tailleres;
	}
      
      if(res==1)
	{
	  tailleres=i; 
	  res=estplusgrandentier(tableau1, tableauresultat, tailleres);
	  
	  while (res==1) {
	    res=estplusgrandentier(tableau1, tableauresultat,tailleres);
	    
	    if (res==1)
	      tailleres =addition(tableauresultat, tableauresultat,tableau2,tailleres,j);
	    
	    if(res==2)
	      tailleres=soustraction(tableauresultat,tableauresultat,tableau2,tailleres,j);
	    
	  }   
	  tailleres=soustraction(tableaures,tableau1,tableauresultat,i,tailleres);
	}
    }
  
  if(i>j)
    {
      tailleres=i; 
      res=estplusgrandentier(tableau1, tableauresultat, tailleres);

      while (res==1) {
	res=estplusgrandentier(tableau1, tableauresultat,tailleres);

	if (res==1)
	  tailleres =addition(tableauresultat, tableauresultat,tableau2,tailleres,j);

	if(res==2)
	  tailleres=soustraction(tableauresultat,tableauresultat,tableau2,tailleres,j);
       	
      }   
      tailleres=soustraction(tableaures,tableau1,tableauresultat,i,tailleres);
   }
   

  return tailleres;
}

int main(int argc, char*argv[]) {

  int tab1[100];
  int tab2[100];
  int tab3[100];

  int tab12[1000];
  int tab23[1000]; 
  int tabres[1000];

  char nb,o1,o2,m1,m2,m3;

  char signe_negatif='-';
  o1='0';
  o2='0';
  m1='0';
  m2='0';
  m3='0';

  int pos, res1,res2,res3,i,j,k,long1,long2,long3,longmax;
  i=0;
  j=0;
  k=0;



  while (nb!='\n'){
    
    scanf("%c",&nb);
    if (nb!=' ')
      {  
    if(nb=='-' && i==0 )
      m1='-';
    else if(nb=='-' && i>0 && j==0 && (o1=='+' || o1=='-' || o1=='*' || o1=='/' || o1=='%') )
      m2='-';   
    else if(nb=='-' && i>0 && j>0 && k==0 && (o2=='+' || o2=='-' || o2=='*' || o2=='/' || o2=='%'))
      m3='-';
    else
      {
	if (estnumeric(nb) && o1=='0')
	  {
	    res1=nb-48;
	    tab1[i]=res1; 
	    i=i+1;
	  }
	else  if( nb=='+' && o1=='0')
	  o1='+';
	else  if( nb=='-' && o1=='0')
	  o1='-';
	else  if( nb=='*' && o1=='0')
	  o1='*';
	else  if( nb=='/' && o1=='0')
	  o1='/';
	else  if( nb=='%' && o1=='0')
	  o1='%';
  
	else if (estnumeric(nb) && (o1!='0') && o2=='0'){
	  res2=nb-48;
	  tab2[j]=res2;
	  j=j+1;
	}
	else  if( nb=='+' && o1!='0' && o2=='0')
	  o2='+';
	else  if( nb=='-' && o1!='0' && o2=='0')
	  o2='-';
	else  if( nb=='*' && o1!='0' && o2=='0')
	  o2='*';
	else  if( nb=='/' && o1!='0' && o2=='0')
	  o2='/';
	else  if( nb=='%' && o1!='0' && o2=='0')
	  o2='%';
	else if(estnumeric(nb) &&  o1!='0' && o2!='0'){
	  res3=nb-48;
	  tab3[k]=res3;
	  k=k+1;
	}
      }
      }
  }

  int tab12prio=0;
  int tab23prio=0;
  char tab12signe='0';
  char tab23signe='0';

  
  /*  printf("m1:%c\n",m1);
  logtab(tab1,i);
  
  
  printf("o1:%c\n",o1);
  printf("m2:%c\n",m2);
  logtab(tab2,j);
  
  printf("o2:%c\n",o2);
  logtab(tab3,k);
  
  printf("m3:%c\n",m3);
  */

  invtab(tab1,i);
  invtab(tab2,j);
  invtab(tab3,k);
  

  if (o1=='*' || o1=='/' || o1=='%')
    tab12prio=1;

  if (o2=='*' || o2=='/' || o2=='%')
    tab23prio=1;

  if (tab12prio==1)
    {
      if (o1=='*')
	longmax=multiplication(tab12,tab1,tab2,i,j);
      if (o1=='/')
	longmax=division(tab12,tab1,tab2,i,j);
      if (o1=='%')
	longmax=modulo(tab12,tab1,tab2,i,j);
      
      if ( (m1=='-' && m2=='0') || (m1=='0' && m2=='-') )
	tab12signe='-';
     
      if (o2=='0')
	{
	  pos=0;
	  while(pos<longmax){
	    tabres[pos]=tab12[pos];
	    pos++;
	  }
	}
      
      
      if (o2=='*')
	longmax=multiplication(tabres,tab12,tab3,longmax,k);
      if (o2=='/')
	longmax=division(tabres,tab12,tab3,longmax,k);
      if (o2=='%')
	longmax=modulo(tabres,tab12,tab3,longmax,k);
      
      if((tab12signe=='-' && m3=='0') || ( tab12signe=='0' && m3=='-'))
	tab12signe=='-';
      
      
      
      if (o2=='+')
	{
	  if (tab12signe=='-' && m3=='0' ) 
	    {
	      longmax=soustraction(tabres,tab12,tab3,longmax,k);
	      signeresultatfinal='-';
	      if (estnegatif==1)
		signeresultatfinal='0';
	      
	    }
	  else if (tab12signe=='0' && m3=='-' ) 
	    {
	      longmax=soustraction(tabres,tab12,tab3,longmax,k);
	      if (estnegatif==1)
		signeresultatfinal='-';
	    }
	    else if (tab12signe=='-' && m3=='-' ) 
	      {
		longmax=addition(tabres,tab12,tab3,longmax,k);
		signeresultatfinal='-';
	      }
	    else
	      {
		longmax=addition(tabres,tab12,tab3,longmax,k);
	      }
	}
       if (o2=='-')
	{
	  if (tab12signe=='-' && m3=='0' ) 
	    {
	      longmax=addition(tabres,tab12,tab3,longmax,k);
	      signeresultatfinal='-';
	    }
	  else if (tab12signe=='0' && m3=='-' ) 
	    longmax=addition(tabres,tab12,tab3,longmax,k);
	  
	  else if (tab12signe=='-' && m3=='-' ) 
	    {
	      longmax=addition (tabres,tab12,tab3,longmax,k);
	      signeresultatfinal='-';
	    }
	    else
	      {
		longmax=soustraction(tabres,tab12,tab3,longmax,k);
		if (estnegatif==1)
		  signeresultatfinal='0';
    	      }
	}          
    }

 if (tab23prio==1 && tab12prio==0)
     {
       if (o2=='*')
	 longmax=multiplication(tab23,tab2,tab3,j,k);
       if (o2=='/')
	 longmax=division(tab23,tab2,tab3,j,k);
       if (o2=='%')
	 longmax=modulo(tab23,tab2,tab3,j,k);
       
       if ( (m2=='-' && m3=='0') || (m2=='0' && m3=='-') )
	 tab23signe='-';
       
       if (o1=='+')
	 {
	   if (tab23signe=='-' && m1=='0' ) 
	     {
	       longmax=soustraction(tabres,tab1,tab23,i,longmax);
	       if (estnegatif==1)
		 signeresultatfinal='-';
	     }
	   else if (tab23signe=='0' && m1=='-' ) 
	     {
	       longmax=soustraction(tabres,tab1,tab23,i,longmax);
	       signeresultatfinal='-';
	       if (estnegatif==1)
		 signeresultatfinal='0';
	      }
	   else if (tab23signe=='-' && m1=='-' ) 
	     {
	       longmax=addition(tabres,tab23,tab1,longmax,i);
	       signeresultatfinal='-';
	     }
	   else
	     {
	       longmax=addition(tabres,tab23,tab1,longmax,i);
	     }
	 }
       
       else if (o1=='-')
	 {
	   if (tab23signe=='-' && m1=='0' ) 
	     {
	       longmax=addition(tabres,tab1,tab23,i,longmax);
	       signeresultatfinal='0';
	     }
	   else if (tab23signe=='0' && m1=='-' ) 
	     {
	       longmax=addition(tabres,tab1,tab23,i,longmax);
	       signeresultatfinal='-';
	     }
	   else if (tab23signe=='-' && m1=='-' ) 
	     {
	       longmax=soustraction (tabres,tab1,tab23,i,longmax);
	       signeresultatfinal='-';
	       if (estnegatif==1)
		 signeresultatfinal='0';
	     }
	   else
	     {
	       longmax=soustraction(tabres,tab1,tab23,i,longmax);
	       if (estnegatif=='1')
		 signeresultatfinal='-';
	     }
	 }
     }

if (tab23prio==0 && tab12prio==0) 
    {
      if (o1=='+')
	{
	  if (m1=='-'&&m2=='-' ) 
	    {
	      longmax=addition(tab12,tab1,tab2,i,j);
	      signeresultatfinal='-';
	    }
	  else if (m1=='-' && m2=='0' ) 
	    {
	      longmax=soustraction(tab12,tab1,tab2,i,j);
	      signeresultatfinal='-';
	      if (estnegatif==1)
		signeresultatfinal='0';
	    }
	  else if (m1=='0' && m2=='-' ) 
	    {
	      longmax=soustraction(tab12,tab1,tab2,i,j);
	      if (estnegatif==1)
		signeresultatfinal='-';
	    }
	  else
	    {
	      longmax=addition(tab12,tab1,tab2,i,j);
	    }
	}
      if (o1=='-')
	{
	  if (m1=='-' && m2=='-' ) 
	    {
	      longmax=soustraction(tab12,tab1,tab2,i,j);
	      signeresultatfinal='-';
	      if (estnegatif==1)
		signeresultatfinal='0';
	    }
	  else if (m1=='-' && m2=='0' ) 
	    {
	      longmax=addition(tab12,tab1,tab2,i,j);
	      signeresultatfinal='-';
	    }
	  else if (m1=='0' && m2=='-' ) 
	    {
	      longmax=addition (tab12,tab1,tab2,i,j);
	    }
	  else if (m1=='0' && m2=='0' )
	    {
	      longmax=soustraction(tab12,tab1,tab2,i,j);
	      if (estnegatif==1)
		signeresultatfinal='-';
	    }
	}

	tab12signe=signeresultatfinal;

	if (o2=='0')
	  {
	    pos=0;
	    while(pos<longmax){
	      tabres[pos]=tab12[pos];
	      pos++;
	    }
	  }
	if (o2=='+')
	  {
	    if (tab12signe=='-' && m3=='0' ) 
	      {
		longmax=soustraction(tabres,tab12,tab3,longmax,k);
		signeresultatfinal='-';
		if (estnegatif==1)
		  signeresultatfinal='0';
		
	      }
	    else if (tab12signe=='0' && m3=='-' ) 
	      {
		longmax=soustraction(tabres,tab12,tab3,longmax,k);
		if (estnegatif==1)
		  signeresultatfinal='-';
	      }
	    else if (tab12signe=='-' && m3=='-' ) 
	      {
		longmax=addition(tabres,tab12,tab3,longmax,k);
		signeresultatfinal='-';
	      }
	    else
	      {
		longmax=addition(tabres,tab12,tab3,longmax,k);
	      }
	  }

	if (o2=='-')
	  {
	    if (tab12signe=='-' && m3=='0' ) 
	      {
		longmax=addition(tabres,tab12,tab3,longmax,k);
		signeresultatfinal='-';
	      }
	    else if (tab12signe=='0' && m3=='-' ) 
	      longmax=addition(tabres,tab12,tab3,longmax,k);

	    else if (tab12signe=='-' && m3=='-' ) 
	      {
		longmax=addition (tabres,tab12,tab3,longmax,k);
		signeresultatfinal='-';
			      }
	    else
	      {
		longmax=soustraction(tabres,tab12,tab3,longmax,k);
		if (estnegatif==1)
		  signeresultatfinal='-';
    	      }
	  }
	
	
    }


  invtab(tabres,longmax);

  if (signeresultatfinal=='-')
    printf("-");
  // logtab(tabres,longmax);
  logtabchar(tabres,longmax);

  
return 0;
}
