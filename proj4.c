/*

*/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
void step2(int argc,const char *name1,const char *name2);
long int findSize(const char *file_name);

int main(int argc, char *argv[]){
    char *name1=argv[1];
    char *name2=argv[2];
    double macro;
    double milli;
    struct timeval start, end;
    //step 2
    gettimeofday(&start,NULL);
    step2(argc,name1,name2);
    gettimeofday(&end,NULL);

    macro= ((end.tv_usec - start.tv_usec)/1000);
    milli=macro*0.001;
    //milli= ((seconds * 1000)+ end.tv_usec)-(start.tv_usec);
    printf("Step 2 took %lf macroseconds",macro);
    printf("Step 2 took %lf milliseconds",milli);

    return 0;
}//main

long int findSize(const char *file_name)
{
    struct stat st; /*declare stat variable*/
     
    /*get the size using stat()*/
     
    if(stat(file_name,&st)==0)
        return (st.st_size);
    else
        return -1;
}
void step2(int argc,const char *name1,const char *name2){
    char *differencesInFile2;
    FILE *input1=fopen(name1,"r");//opened the files
    FILE *input2=fopen(name2,"r");
    //error message
    if((input1==NULL||input2==NULL)&&(argc==3)){
        printf("There was an error reading a file.\n");
	exit(0);
    }
    if(argc!=3){
      printf("Usage: proj4.out <file1> <file2>\n");
      exit(0);
    }
    char char1=getc(input1);
    char char2=getc(input2);
    char *arr1= (char *) malloc(findSize(name1)*sizeof(char));
    char *arr2=(char *) malloc(findSize(name2)*sizeof(char));
    int count1=0;
    int count2=0;
    while((char1!=EOF)){
        arr1[count1]=char1;//gets each char from the file and adds to array;
        char1=getc(input1);//gets next char
        count1++;
    }
    while(char2!=EOF){
        arr2[count2]=char2;//gets each char from the file and adds to array;
        char2=getc(input2);//gets next char
        count2++;
    }
    //size of both arrays
    int size1 = count1;
    int size2 = count2;
    /*
    printf("size: %d\n",size1);
    for(int i=0;i<size1;i++){
      printf("arr1: %c\n",arr1[i]);
    }
    */
    int sizeOfNewArr=0;
    //if size1 is bigger
    if(size1>=size2){
        differencesInFile2=(char *) malloc(size1*sizeof(char));        
        //char differencesInFile2[]=new char[size1];
        for(int i=0;i<size2;i++){
            if(arr1[i]!=arr2[i]){
                //put in new array
                differencesInFile2[sizeOfNewArr]=arr2[i];  
                //printf("diff: %c\n",differencesInFile2[i]);
                sizeOfNewArr++;
            }
        }
        printf("diffSize: %d\n",sizeOfNewArr);
        printf("size2: %d\n",size2);
        //TESTING
        for(int i=0;i<sizeOfNewArr;i++){
           //printf("diff contents: %c\n",differencesInFile2[i]);
           // printf("diff: %c\n",differencesInFile2[i]);
        }
    }
    
    //if size2 is bigger
    if(size1<size2){   
        differencesInFile2=(char *) malloc(size2*sizeof(char));
        //char differencesInFile2[]=new char[size2];
        for(int i=0;i<size1;i++){
            if(arr1[i]!=arr2[i]){
                //put in new array
                differencesInFile2[sizeOfNewArr]=arr2[i];
                sizeOfNewArr++;
                //printf("diff: %c\n",differencesInFile2[i]);
            }
        }
        for(int j=sizeOfNewArr;j<size2;j++){
            differencesInFile2[sizeOfNewArr]=arr2[sizeOfNewArr];
            sizeOfNewArr++;
        }
    }
    //writing in the differences into new file
    FILE *fp=fopen("differencesFoundInFile2.txt","w");//new file
    fwrite(differencesInFile2,1,sizeOfNewArr,fp);
    fclose(input1);
    fclose(input2);
    free(arr1);
    free(arr2);
    free(differencesInFile2);
}
/*
void checktime(){
  unsigned long long count;
  struct timeval end;
  struct timeval tv;
  gettimeofday(&tv,NULL);
  if(tv.tv_sec >= end.tv_sec && tv.tv_usec >=end.tv_usec){
    printf("%s count=%lld\n", count);
    exit(0);
  }
}
*/

/*
void step1(){
    while(running==1){
        char num[80];
        scanf("%[^\n]",num);//takes in entire line of input
        char char1;
        if((char1=getchar())==EOF){
            sleep(60);
            printf("The sum is %f\n",tot);
            printf("Program ended after sleeping for 60 seconds. \n");
            printf("\n");
            running=0; 
        }
        else{
            tot+=atof(num);
        }
    }
    
}
*/
