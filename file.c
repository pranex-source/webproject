#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
void main()
{
  int ch,t,e,m,s,ss,total,roll,r,key=0,k;
  float avg;
  char name[20],result[20],grade[20],c;
  FILE *p;
  do
  {
  clrscr();
  printf("1. Insert Data\n2. Display Data\n3. Search Data\n4. Pass Students Details\n5. Fail Students Details\n6.FirstClass Students Details\n7. Second Class Students Details\n8. Third Class Students Details\n9. Exit\n ");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
      p=fopen("sslc","a");
      printf("Enter your name\n");
      scanf("%s",&name);
      printf("Enter your rollno\n");
      scanf("%d",&roll);
      printf("Enter your5 subject mark\n");
      a:printf("Tamil Mark:");
      scanf("%d",&t);
      if(t>100 ||t<0)
      {
	printf("Your Tamil Mark is Invalid!\t Please enter valid Mark\n");
	goto a;
      }
      b:printf("English Mark:");
      scanf("%d",&e);
      if(e>100 ||e<0)
      {
	printf("Your English mark is Invalid!\t Please enter valid Mark\n");
	goto b;
      }
      c:printf("Maths Mark:");
      scanf("%d",&m);
      if(m>100 ||m<0)
      {
	printf("Your Maths Mark is Invalid!\t Please enter valid Mark\n");
	goto c;
      }
      d:printf("Science Mark:");
      scanf("%d",&s);
      if(s>100 ||s<0)
      {
	printf("Your Science Mark is Invalid!\t Please enter valid Mark\n");
	goto d;
      }
      e:printf("Social Mark:");
      scanf("%d",&ss);
      if(ss>100 ||ss<0)
      {
	printf("Your Social Mark is Invalid!\t Please enter valid Mark\n");
	goto e;
      }
      fflush(stdin);
      printf("Do you want to store the data in a file\n(Y/N)");
      scanf("%c",&c);
      if(c=='y'||c=='Y')
       {
	total=t+e+m+s+ss;
	avg=total/5.0;
	if(t>34 &&e>34 &&m>34 &&s>34 &&ss>34)
	{
	  strcpy(result,"pass");
	  if(avg>80)
	  strcpy(grade,"Distinction");
	  else

	    if(avg>70)
	      strcpy(grade,"FirstClass");
	    else
	      if(avg>60)
		strcpy(grade,"SecondClass");
	      else
		if(avg>50)
		  strcpy(grade,"ThirdClass");
		else
		  strcpy(grade,"FourthClass");
	  }

	else
	{
	  strcpy(result,"Fail");
	   strcpy(grade,"NoClass");
	}

	fprintf(p,"%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	printf("One Record Inserted Successfully\n");
    }
	else
	  printf("Your data is not stored!!\n");
	  getch();
	fclose(p);
	break;
    case 2:
      p=fopen("sslc","r");
      if(p==NULL)
	printf("No Records Found in a File!!");
      else
      {
	printf("Name\tRollNo\tTam\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	while(!feof(p))
	{
	  fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
      //if(!feof(p))
      //{
	  printf("%s\t",name);
	  printf("%d\t",roll);
	  printf("%d\t",t);
	  printf("%d\t",e);
	  printf("%d\t",m);
	  printf("%d\t",s);
	  printf("%d\t",ss);
	  printf("%d\t",total);
	  printf("%f\t",avg);
	  printf("%s\t",result);
	  printf("%s\n",grade);
	}
     }
    // }
      fclose(p);
      getch();
      break;
    case 3:
      printf("Enter the RollNo\n");
      scanf("%d",&r);
      p=fopen("sslc","r");
      if(p==NULL)
	printf("Records are not Found!!\n");
      else
      {
	while(!feof(p))
	{
	  fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
	  if(r==roll)
	  {
	    printf("Name\tRollNo\tTamil\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	    printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	    key=1;
	    break;
	  }
	}
	if(key==0)
	  printf("%d rollno is not exist in this file\n",r);
      }
      fclose(p);
      getch();
      break;
    case 4:
      printf("Pass Students Details\n");
      p=fopen("sslc","r");
      key=0;
      if(p==NULL)
	printf("NO Records Found!!");
      else
      {
	printf("Name\tRollNo\tTamil\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	while(!feof(p))
	{
	  fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
	  k=strcmpi(result,"pass");
	  if(k==0)
	  {
	    printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	    key=1;
	  }
	}
	if(key==0)
	  printf("\nPass Students are not there!!!");
      }

      fclose(p);
      getch();
      break;
    case 5:
      printf("Fail Students Details\n");
      p=fopen("sslc","r");
      key=0;
      if(p==NULL)
	printf("No Records Found in a File\n");
       else
       {
	 printf("Name\tRollNo\tTamil\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	 while(!feof(p))
	 {
	   fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
	   k=strcmpi(result,"Fail");
	   if(k==0)
	   {
	     printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	     key=1;
	   }
	 }
	 if(key==0)
	   printf("\nFail Students are not there!!!\n");
       }
       fclose(p);
       getch();
       break;
     case 6:
       printf("'First Class' Students Details\n");
       p=fopen("sslc","r");
       key=0;
       if(p==NULL)
	 printf("No Records Found in a File\n");
       else
       {
	 printf("Name\tRollNo\tTamil\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	 while(!feof(p))
	 {
	   fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
	   k=strcmpi(grade,"FirstClass");
	   if(k==0)
	   {
	     printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	     key=1;
	   }
	 }
	 if(key==0)
	   printf("\nFirst Class Students are not available in a File!!");
       }
       fclose(p);
       getch();
       break;
     case 7:
       printf("'Second Class' Students Details\n");
       p=fopen("sslc","r");
       key=0;
       if(p==NULL)
	 printf("No Records Found in a File!!\n");
       else
       {
	 printf("Name\tRollNo\tTamil\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	 while(!feof(p))
	 {
	   fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
	   k=strcmpi(grade,"SecondClass");
	   if(k==0)
	   {
	     printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	     key=1;
	   }
	 }
	 if(key==0)
	   printf("\nSecond Class Student Details Not available in a file\n");
       }
       fclose(p);
       getch();
       break;

     case 8:
       printf("'Third Class' Students Details\n");
       p=fopen("sslc","r");
       key=0;
       if(p==NULL)
	  printf("No Records Found in a File!!");
       else
       {
	 printf("Name\tRollNo\tTamil\tEnglish\tMaths\tScience\tSocial\tTotal\tAverage\tResult\tGrade\n");
	 while(!feof(p))
	 {
	   fscanf(p,"%s%d%d%d%d%d%d%d%f%s%s\n",&name,&roll,&t,&e,&m,&s,&ss,&total,&avg,&result,&grade);
	   k=strcmpi(grade,"ThirdClass");
	   if(k==0)
	   {
	      printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%s\t%s\n",name,roll,t,e,m,s,ss,total,avg,result,grade);
	      key=1;
	   }
	 }
	 if(key==0)
	   printf("\nThird Class Students Are not There!!");
       }

       fclose(p);
      getch();
    }
  }
  while(ch!=9);
}