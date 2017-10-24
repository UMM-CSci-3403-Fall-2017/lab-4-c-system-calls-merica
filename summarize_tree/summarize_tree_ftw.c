
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ftw.h>
#define MAX_FTW_DEPTH 16
static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag) {


if(typeflag == FTW_F) {
 num_regular++;
 
} else if(typeflag == FTW_D) {
num_dirs++;
 
}
 return 0;

}



int main(int argc, char** argv) {
    // Check arguments and set things up
  num_dirs=0;
  num_regular=0;

    ftw(argv[1], callback, MAX_FTW_DEPTH);
printf("%s\n", "The number of directories were: ");
printf("%d", num_dirs);
 printf("%s\n", "");
 printf("%s\n", "The number of regular files were: ");
printf("%d", num_regular);
  printf("%s\n", "");
    // Print out the results
}


