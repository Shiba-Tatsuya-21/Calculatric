


#include <stdio.h>

int main(int argc, char*argv[]) {

  int tab1[100];
  int tab2[100];
  int tab3[100];

  int tab12[1000];
  int tabres[1000];

  char nb,o1,o2,m1,m2,m3;
  o1='0';
  o2='0';

  int res1,res2,res3,i,j,k,long1,long2,long3,longmax;

  i=0;
  j=0;
  k=0;
  

int logtab(int tab[], int c){
    int i;
    for(i=0;i<c;i++){
      printf("%d",tab[i]);
    }
    printf("\n");
  }

 
 void invtab(int tab[],int taille){

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

    printf("maximum:%d\n", n);
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
	valeur1=0;
	valeur2=0;

	if (pos<=i-1)
	  valeur1=tableau1[pos];	

	if (pos<=j-1)
	  valeur2=tableau2[pos];

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
 
  if (o1=='+')
    {
      invtab(tab1,i);
      invtab(tab2,j);

      longmax=addition(tab12, tab1, tab2, i, j );
    }

  logtab(tab12,longmax);
  invtab(tab12,longmax);
 
  printf("=");
  logtab(tab12,longmax);
  printf("---------------------\n");


  logtab(tab12,longmax);  
  printf("%c\n",o2);
  logtab(tab3,k);
 
  
  if (o2=='+')
    {
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
