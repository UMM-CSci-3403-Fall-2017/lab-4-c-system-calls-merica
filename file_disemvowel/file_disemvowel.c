#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




#define BUF_SIZE 1024
bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */

    if(c == 'a' || c == 'e' || c =='i' || c  == 'o' || c  == 'u' || c  == 'A' || c  == 'E' || c  == 'I' || c  == 'O' || c  == 'U'){
      return true;
}
    return false;
 
}




 int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
  int i=0;
  int non_vowels = 0;
  int z = 0;
  int j =0;
   //loops over the array  to find non-vowels and keeps track of the amount of vowels
  for (i = 0; i < num_chars; i++) {
    if(is_vowel(in_buf[i])){
    
    } else {
       non_vowels++;
    }
  }
  //copies over non-vowels from the old array to the new one.
  for (j = 0; j < num_chars; j++) {
    
    if(is_vowel(in_buf[j])){
    
    
    } else {
 

      out_buf[z] = in_buf[j];
  
      z++;
}
    
 
}
  return non_vowels;
}
void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */
  //alloating the buff size
  //char* in_buf = (char*)calloc(BUF_SIZE, sizeof(char));
  //char* out_buf = (char*)calloc(BUF_SIZE+1, sizeof(char));
  char in_buf[BUF_SIZE];
char out_buf[BUF_SIZE+1];
  int non_vowels =0;
  int number_of_chars = 0;
  //loop condition reads the number of characters sucessfuly read in a file.
  //fread() returns 0 where there are no more characters to read.
  while((number_of_chars = fread(in_buf, 1, BUF_SIZE, inputFile)) != 0) {


    non_vowels=copy_non_vowels(number_of_chars, in_buf, out_buf );
    //Inserting the null terminator at the end of the string
       out_buf[non_vowels] = '\0';
       //writing out to the output file.
       fwrite(out_buf, sizeof(char), non_vowels, outputFile);
    

  }

  // closing files
 fclose(outputFile);
fclose(inputFile);
//freeing memory
//free(in_buf);
//free(out_buf);


}




int main(int argc, char *argv[]) {
  FILE *inputFile;
  FILE *outputFile;

 
     
       
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.
  if(argc == 3) {
      inputFile = fopen(argv[1], "r");
      outputFile = fopen(argv[2], "w");
    } else if (argc == 2) {
      inputFile = fopen(argv[1], "r");
      outputFile = stdout;
    } else if (argc == 1) {
      inputFile = stdin;
      outputFile = stdout;
  } else if (argc == 0) {
    printf("%s\n", "Invalid number of args");
  }



    
      disemvowel(inputFile, outputFile);







    return 0;

}
