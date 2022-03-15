#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){

    //error message for segmentation fault
    if (argc==1) {
        printf("./grepFile: missing operand\nTry './grepFile --help' for more information.\n");
        return EXIT_SUCCESS;
    }

    //usage
    if (argc==2 && strcmp(argv[1],"--h")==0 || strcmp(argv[1], "--help")==0)
    {
        printf("Usage: <program name> <file> <word>\n");
        printf("Example: ./grepFile TestFile.txt lorem\n");
        return EXIT_SUCCESS;
    }

    //grep implementation
    else if(argc==3){
        FILE *fptr;
        FILE *fptrout;
        char token[]=" .,'\":;?!\n";
        int char_counter=0, row_counter=1, word_counter=0;
        
        fptr=fopen(argv[1], "r");
        fptrout=fopen("outputfile.txt", "w");

        //empty file check
        if (fptr==NULL||fptrout==NULL) {
            printf("Cannot open the file");
            EXIT_FAILURE;
        }

        //length of file
        for (char c=fgetc(fptr); c!=EOF; c=fgetc(fptr))
            char_counter++;
        char line[char_counter];
        fclose(fptr);
        
        //number of searched word 
        fptr=fopen(argv[1], "r");
        while (fgets(line, sizeof(line), fptr)!=NULL) {
            char *particular_word=strtok(line,token);
            while (particular_word!=NULL){
                if (strcmp(argv[2],particular_word)==0)
                    word_counter++;
                particular_word=strtok(NULL, token);
            }
        }
        fclose(fptr);

        //output file content
        fptr=fopen(argv[1], "r");
        while (fgets(line, sizeof(line), fptr)!=NULL) {
            if (strstr(line, argv[2])!=NULL)
                fprintf(fptrout,"Line '%d' has '%s' in it.\n",row_counter,argv[2]);
            row_counter++;
        }

        fclose(fptrout);
        fclose(fptr);
        printf("The word (%s) exists \"%d\" time/times in the text.\n",argv[2],word_counter);
        return EXIT_SUCCESS;
    }

    //error message
    else{
        printf("./grepFile: missing operand\nTry './grepFile --help' for more information.\n");
        return EXIT_FAILURE;
    } 
}
