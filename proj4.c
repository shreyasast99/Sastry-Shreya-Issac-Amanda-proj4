/*

*/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
void step2(int argc,const char *name1,const char *name2);
long int findSize(const char *file_name);
void step1(int argc,const char *name1,const char *name2);
int main(int argc, char *argv[]){
    char *name1=argv[1];
    char *name2=argv[2];
    double macro;
    double milli;
    double macro1;
    double milli1;
    struct timeval start1,end1;
    //step 2
    gettimeofday(&start1,NULL);
    step1(argc,name1,name2);
    gettimeofday(&end1,NULL);

    macro1= (end1.tv_usec - start1.tv_usec);
    milli1=macro1*0.001;
    
    printf("Step 1 took %lf milliseconds\n",milli1);
    
    struct timeval start, end;
    //step 2
    gettimeofday(&start,NULL);
    step2(argc,name1,name2);
    gettimeofday(&end,NULL);

    macro= (end.tv_usec - start.tv_usec);
    milli=macro*0.001;
    
    printf("Step 2 took %lf milliseconds\n",milli);
    
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

void step1(int argc,const char *name1,const char *name2){
    // char *charVal1=(char*)malloc(sizeof(char));
    //char *charVal2=(char*)malloc(sizeof(char));
    FILE *input1=fopen(name1,"r");//opened the files
    FILE *input2=fopen(name2,"r");
    FILE *fp=fopen("differencesFoundInFile1.txt","w");//new file
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
    int count1=0;
    while((char1!=EOF)){
        if(char1!=char2){
            fputc(char1,fp);
        }
        char1=getc(input1);//gets next char
        char2=getc(input2);//get next char
        count1++;
    }


    /*
    FILE *fp=fopen("differencesFoundInFile1.txt","w");//new file
    while(fread(charVal1,1,1,input1)>0){
        if((fread(charVal2,1,1,input2)<=0)||(charVal1[0]!=charVal2[0])){
            fwrite(charVal1,1,1,fp);
        }
    }
    */
}
