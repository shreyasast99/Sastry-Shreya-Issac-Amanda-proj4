#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
void step2(string name1,string name2);
int main(int argc, char *argv[]){

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
void step2(string name1,string name2){
    int index=0;
    int line=0;
    FILE *input1=fopen(name1,"r");//opened the files
    FILE *input2=fopen(name2,"r");
    //error message
    if(input1==NULL||input2==NULL){
        printf("There was an error reading a file.\n");
    }
    char file1=getc(input1);
    char file2=getc(input2);
    char arr1[]=new char[findSize(name1)];
    char arr2[]=new char[findSize(name2)];
    int count1=0;
    int count2=0;
    while((file1!=EOF)){
        arr1[count1]=file1;//gets each char from the file and adds to array;
        file1=getc(input1);//gets next char
    }
    while(file2!=EOF){
        arr2[count2]=file2;//gets each char from the file and adds to array;
        file2=getc(input2);//gets next char
    }
    size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
    size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
    if(size1>size2){
        for(int i=0;i<size1;i++){
            if(arr1[i]!=arr2[i]){

            }
        }
    }
    fclose(input1);
    fclose(input2);
    free(input1);
    free(input2);
}

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
