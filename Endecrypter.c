#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int endecrypter(char **args){
    int i = 0;
    while (args[i] != NULL) {
        i++;
    }

    if (i != 3)
    {
        printf("YOU HAVE TO GIVE 2 ARGUMENTS! FIRST ONE FILE NAME, SECOND ONE OPERATION!\n");
    }
    else
    {

    FILE *num;
    num = fopen(args[1], "r");
    if(num == NULL){
        printf("File couldn't found\n");
    }
    else
    {
    
    int Num_bytes;
    for(Num_bytes = 0; fgetc(num) != EOF; ++Num_bytes);
    fclose(num);

    if(strcmp(args[2],"en") == 0){
    
    char ch;
    FILE *file_main, *temp;

    file_main = fopen(args[1], "r");
    temp = fopen("clone.txt", "w");

    if(file_main == NULL){
        printf("File couldn't found\n");
    }
    else{
    while(1){
        ch = fgetc(file_main);
        if(ch==EOF){
            break;
        }
        else
        {   
            ch = ch + 127;
            fputc(ch,temp);            
        }
        
    }

  

    fclose(file_main);
    fclose(temp);

    file_main = fopen(args[1], "w");
    temp = fopen("clone.txt", "r");
    while (1){
        ch = fgetc(temp);
        if(ch==EOF)
            break;
        else
        {
            fputc(ch, file_main);
        }
        
    }
    fclose(file_main);
    fclose(temp);
    printf(".....File is encrypted.....\n");
    }
    
    if (strcmp(args[2], "de") == 0)
    {
    char ch;
	FILE *file_main, *temp;
	
	file_main = fopen(args[1], "w");
	temp = fopen("clone.txt", "r");

    if(file_main == NULL){
        printf("File couldn't found.\n");
    }
    else{

    if(temp == NULL){
        printf("File couldn't found.\n");
    }
    else{
	
	while(1)
	{
		ch = fgetc(temp);
		if(ch==EOF)
			break;
		else
		{
            ch = ch - 127;
			fputc(ch, file_main);

		}
	}
    


	fclose(file_main);
	fclose(temp);
    printf(".....File is decrypted.....\n");
    }
    if(strcmp(args[2], "de") != 0 && strcmp(args[2], "en") != 0){
        printf("You have to give 'en' for encrypt, 'de' for decrypt as a second argument!\n");
    }
    else
    {

   printf("Size of file is %d bytes\n", Num_bytes);

   return 0; 
}
}
}
}
}
}
}
