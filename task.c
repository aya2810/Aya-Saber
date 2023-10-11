#include <stdio.h>
#include <string.h>
#include <conio.h>
  int main()
  {
      char username[10];
      char password[10];
      printf("Enter your username: ");
      scanf("%s",&username);
      printf("Enter your password: ");
      scanf("%s",&password);
      if(strcmp(username,"aya")==0){
          if(strcmp(password,"123456")==0){
          printf("Login Success");
          }else{
      printf("password is wrong");
  }
      }else{
      printf("Username is wrong");
  }
      return 0;
  }