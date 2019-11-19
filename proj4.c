#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
void step2(string name1,string name2);
int main(int argc, char *argv[]){

}//main
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
    while((file1!=EOF)&&(file2!=EOF)){
        index++;
        if(file1!=file2){
            //write difference into other file
            write("differencesFoundInFile1.txt");
        }
        //delete after
        if(file1=='\n'&&file2=='\n'){
            index=0;
            line++;
        }
        file1 = getc(input1); 
        file2 = getc(input2);
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
