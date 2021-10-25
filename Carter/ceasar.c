#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>



int main(int argc, string argv[])
{
    
for(int num = 0; num < 1;)
{
  if(isalnum(argv[1]))
  {
    int key = (int) argv[1];
    num++;
  }
  else
  {
    printf("Usage \n");
    return 1;
    
  }
}

int key = (int) argv[1];
string text =  get_string("Text:");
int length = strlen(text);

//string encrypt = 

  for(int i = 0; i < length; i++)
  {
    char encrypt = (int) text[i] + key;
    int wrap = encrypt - 26;
    
    if(isalpha(text[i]) != 0)
      {
        if(isupper(text[i]) )
    {
      if(encrypt > 90)
      {
        printf("%c", wrap);
      }
      else
      {
        printf("%c", encrypt);
      }
    }
    
      if(islower(text[i]) )
    {
      if(encrypt > 122)
      {
        printf("%c", wrap);
      }
      else
      {
        printf("%c", encrypt);
      }
    }
    
  }  
    else 
    {
      printf("%c",text[i]);
    } 
    
    
  }
   
  printf("\n");
}
  