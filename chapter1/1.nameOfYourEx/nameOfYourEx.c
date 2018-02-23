// I have tried renaming this source file to program1.txt and program1 but the gcc compiler did not recognize the file format extension.
// is it mandatory to have the file format extension as .c in linux or is it just a convention.
#include <stdio.h>
void main(){
char ex[20];
puts("Enter the name of your ex:");

scanf("%19s", ex);
printf("Say good-bye to your ex: %s\n", ex);

}
