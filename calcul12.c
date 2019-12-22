
#include <stdio.h>
#include <math.h>

int estnegatif=0;

int logtab(int tab[], int c){
    int i;
    for(i=0;i<c;i++){
      printf("%d",tab[i]);
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

   if (j>i)
     estnegatif=1;
   if (i==j)
     {   
       if (estplusgrandentier(tableau1,tableau2,i)==1)
	 imax=1;
       else
	 {
	 jmax=1;
	 estnegatif=1;
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
   return pos;
}

int multiplication (int tableaures[], int tableau1[], int tableau2[], int i, int j ){
  int pos=0;
  int valeur,nI;
  long n;
  long base=1;
  int mini;
  int tailleres=0;
 
  int longueur = maximum(i,j);
  
  if (longueur==i)
    mini=j;
  else
    mini=i;

  
  while(pos<mini)
    {
    // connaitre le nombre d'addition du plus grand nombre par colonne du mini
    if ( mini==i && tableau1[pos]!=0)
      valeur=tableau1[pos]; 	
    else if ( mini==j && tableau2[pos]!=0)
      valeur=tableau2[pos];
    else
      valeur=0;

    n =valeur*(base);
   
    
    //    printf("%d %d %d %d\n",valeur, pos, base, n );
    // on addition sur lui meme le plus grand nombre N fois.
    for(nI=1;nI<=n;nI++){

      if (mini==i)
	{
	  tailleres= addition(tableaures,tableaures,tableau2,tailleres,longueur);
	  //logtab(tableaures,tailleres);
	}
      else
	{
	  tailleres= addition(tableaures,tableaures,tableau1,tailleres,longueur);
	  //logtab(tableaures,tailleres);
	}
    }
    base=base*10;
    pos++;
  }
  //logtab(tableaures,tailleres);
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
	    //printf("tab1 %d\n", tableau1[pos]);
	    //printf("tab2 %d\n", tableau2[pos]);
	    
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
  int valeur,res,nI;
  long n;
  long base=1;
  int mini;
  int tailleresultat=i;
  int tailleres=0;

  int tableaudeun[1]={1};
  int tableauresultat[100]={0};

  /*logtab(tableau1,i);
  logtab(tableau2,j);

  logtab(tableauresultat,i);

  res= estplusgrandentier(tableauresultat, tableau1, tailleresultat);
  printf("%d\n", res);
  */

  if (i < j ) 
    {
      tailleres = addition(tableaures, tableaures,tableauresultat,1,1) ;
      return tailleres;
    }

  if (i==j)
    {
      res = estplusgrandentier(tableau1, tableau2, i ) ;
      printf("%d\n", res);
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
	     tailleres=soustraction(tableaures,tableaures,tableaudeun,tailleres,j);
	   }
       }
     else
       res=1;
     //  logtab(tableauresultat,tailleresultat);
     //  printf("%d\n", res);
    
    }
 
  logtab(tableauresultat,tailleresultat);
  logtab(tableaures,tailleres);
 
  return tailleres;
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

  /*logtab(tableau1,i);
  logtab(tableau2,j);

  logtab(tableauresultat,i);

  res= estplusgrandentier(tableauresultat, tableau1, tailleresultat);
  printf("%d\n", res);
  */

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
      printf("%d\n", res);
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
      
      if(res==1){
	// initialise tableaures a la valeur du tableau 1
	while(pos<i){
	  tableaures[pos]=tableau1[pos];
	  pos++;
      }
	tailleres=i;
	
	res=estplusgrandentier(tableaures, tableau2, i);
	while ( res==1) {
	  res=estplusgrandentier(tableaures, tableau2, i);
	  if(res==1){
	   
	    tailleres =soustraction(tableaures, tableaures,tableau2,tailleres,j);
	    logtab(tableaures,tailleres);
	  }
	  else
	    if(res==0){
	      // tailleres = soustraction(tableaures, tableaures,tableau2,tailleres,j);
	      return tailleres;
	    }
	

	  
	}

      }
      
    }
  
  if(i>j){





  }
 
  /*
  */

  /*
  res=estplusgrandentier(tableau1, tableau2, i);
      while ( res==2 ) 
    {
      res=estplusgrandentier(tableau1, tableau2, i);
      if(res==2)
       {
	 tailleresultat = soustraction(tableauresultat,tableaures,tableau2,tailleres, j);
      	 tailleres =soustraction(tableaures, tableaures,tableaudeun,tailleres,1) ;
	 res=estplusgrandentier(tableau1, tableau2, i);
	  if (res==1)
	   {
	     tailleres=soustraction(tableaures,tableaures,tableaudeun,tailleres,j);
	   }
       }
     else
       res=1;
     //  logtab(tableauresultat,tailleresultat);
     //  printf("%d\n", res);
    
    }

 
  logtab(tableauresultat,tailleresultat);
  logtab(tableaures,tailleres);
  */
  return tailleres;
}









int main(int argc, char*argv[]) {

  int tab1[100];
  int tab2[100];
  int tab3[100];

  int tab12[1000];
  int tabres[1000];

  char nb,o1,o2,m1,m2,m3;

  char signe_negatif='-';
  o1='0';
  o2='0';
  m1='0';
  m2='0';
  m3='0';

  int res1,res2,res3,i,j,k,long1,long2,long3,longmax;
  i=0;
  j=0;
  k=0;

  while (nb!='\n'){
    
    scanf("%c",&nb);
    
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

  
  
  logtab(tab1,i);
 
  printf("%c\n",o1);
  logtab(tab2,j);




 
  if (o1=='+' && m1=='0' && m2=='0')
    {
      invtab(tab1,i);
      invtab(tab2,j);

      longmax=addition(tab12, tab1, tab2, i, j );
    }

  if(o1=='-' && m1=='0' && m2=='0' ){

    invtab(tab1,i);
    invtab(tab2,j);
    longmax=soustraction(tab12, tab1, tab2, i, j );
  }


  if(o1=='-' && m1=='0' && m2=='-' ){

    invtab(tab1,i);
    invtab(tab2,j);
    longmax=addition(tab12, tab1, tab2, i, j );
  } 

  if(o1=='*'){
    invtab(tab1,i);
    invtab(tab2,j);
    longmax=multiplication(tab12,tab1,tab2,i,j);
  }
    
  if (o1=='/' && m1=='0' && m2=='0')
    {
      invtab(tab1,i);
      invtab(tab2,j);

      longmax=division(tab12, tab1, tab2, i, j );
    }

  if (o1=='%' && m1=='0' && m2=='0')
    {
      invtab(tab1,i);
      invtab(tab2,j);

      longmax=modulo(tab12, tab1, tab2, i, j );
    }


 //  logtab(tab12,longmax);
  invtab(tab12,longmax);
 
  printf("=");
  if (estnegatif)
    {
    printf("%c",signe_negatif);
    logtab(tab12,longmax);
    }

  // printf("---------------------\n");


  logtab(tab12,longmax);  
  printf("%c\n",o2);
  logtab(tab3,k);
 






  
  if (o2=='+' && m2=='0' && m3=='0' )
    {
      invtab(tab12,longmax);
      invtab(tab3,k);
      longmax=addition(tabres,tab12,tab3,longmax,k);
    }
 if (o2=='-' && m2=='0' && m3=='0' )
    {
      invtab(tab12,longmax);
      invtab(tab3,k);
      longmax=soustraction(tabres,tab12,tab3,longmax,k);
    }

  
 if(o2=='-' && m3=='-' ){

   invtab(tab12,longmax);
      invtab(tab3,k);
      longmax=addition(tabres,tab12,tab3,longmax,k);
  } 






  invtab(tabres,longmax);
  printf("=");
  logtab(tabres,longmax);
  





  

  
/*
printf("%c\n",o1);
printf("%c\n",o2);
printf("%c\n",m1);
printf("%c\n",m2);
printf("%c\n",m3);
*/
  
return 0;
}
