#include <stdio.h>
int static ans4;
int static ans1;
int static ans2;
int static correctcode=1110;
unsigned int static deposit;
unsigned int static revenue;
char static stockA = 32, stockB = 32, stockC = 32, stockD = 32, stockE = 32;
unsigned int static stockamountA =5, stockamountB = 1,  stockamountC = 2, stockamountD = 1, stockamountE = 9;
char selecteditem = '=';



void menu(int prices[], int deposit, char stockA, char stockB, char stockC, char stockD, char stockE) {
  printf("*---------------------------*\n");
  printf("|      Vending Machine      |\n");
  printf("*---------------------------*\n");
  printf("|   A    B    C    D    E   |\n");
  
  printf("|  $");
  if(prices[0]>9)
  printf("%d", prices[0]);
  else printf(" %d",prices[0]);
  printf("  $");
  if(prices[1]>9)
  printf("%d", prices[1]);
  else printf(" %d",prices[1]);
  printf("  $");
  if(prices[2]>9)
  printf("%d", prices[2]);
  else printf(" %d",prices[2]);
  printf("  $");
  if(prices[3]>9)
  printf("%d", prices[3]);
  else printf(" %d",prices[3]);
  printf("  $");
  if(prices[4]>9)
  printf("%d", prices[4]);
  else printf(" %d",prices[4]);
  printf("  |\n");
  printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", stockA, stockB, stockC, stockD, stockE);
  printf("*---------------------------*\n");
  printf("|                    [$");
  if(deposit>9)
  printf("%d", deposit);
  else printf(" %d",deposit);
  printf("]  |\n");
  printf("|                           |\n");
  printf("|           [=%c=]           |\n", selecteditem);
  printf("*---------------------------*\n\n");

}


void ques0() {
  printf("What would you like to do?\n1. Read product information\n2. Insert coin\n3. Press product button\n4. Press return button\n9. Open service menu (code required)\n0. Quit\nYour choice:");
}

void menu1(char products[][21], int prices[]) {
  printf("(1) The displayed products are:\nA. "); 
  printf("%s ", products[0]);
  printf("($%d)\nB. ", prices[0]);
  printf("%s ", products[1]);
  printf("($%d)\nC. ", prices[1]);
  printf("%s ", products[2]);
  printf("($%d)\nD. ", prices[2]);
  printf("%s ", products[3]);
  printf("($%d)\nE. ", prices[3]);
  printf("%s ", products[4]);
  printf("($%d)\n", prices[4]);
}

void ques0loop() {
  for(;;) {
    ques0();
    scanf("%d", &ans1);
    if(ans1 == 1 || ans1==2 || ans1==3 || ans1==4 || ans1==9 || ans1==0) {
      break;
    }
    printf("Invalid choice!\n\n");
  }
}

void menu2(int prices[]) {
  for(;;) {
    printf("(2) Which coin would you like to insert?\n1. $1\n2. $2\n3. $5\n4. $10\n0. Go back\nYour choice:");
    int coinchoice;
    scanf("%d", &coinchoice);
    if(coinchoice==1) {
      printf("You have inserted $1.\n\n");
      deposit=deposit+1;
    }
    else if(coinchoice==2) {
      printf("You have inserted $2.\n\n");
      deposit=deposit+2;
    }
    else if(coinchoice==3) {
      printf("You have inserted $5.\n\n");
      deposit=deposit+5;
    }
    else if(coinchoice==4) {
      printf("You have inserted $10.\n\n");
      deposit=deposit+10;
    }
    else if(coinchoice==0) {
      printf("Going back!\n\n");
      break;
    }
    else {printf("Invalid choice!\n\n");}

    if(deposit>=prices[0]) {
      stockA = 'O';
    }
    if(deposit>=prices[1]) {
      stockB = 'O';
    }
    if(deposit>=prices[2]) {
      stockC = 'O';
    }
    if(deposit>=prices[3]) {
      stockD = 'O';
    }
    if(deposit>=prices[4]) {
      stockE = 'O';
    }

    if(coinchoice==1||coinchoice==2||coinchoice==3||coinchoice==4) {
      menu(prices, deposit, stockA, stockB, stockC, stockD, stockE);
    }
  }     
}

void menu3(int prices[]) {
  for(;;) {
    printf("(3) Which product button would you like to press?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
    int productno;
    scanf("%d", &productno);
    if(productno==1 && stockamountA!=0 && deposit>=prices[0]) {
      printf("You have pressed button A.\n");
      stockamountA--;
      if (stockamountA==0) {
        stockA = 'X';
      }
      selecteditem = 'A';
      deposit=deposit-prices[0];
      revenue=revenue+prices[0];
      break;
    }
    else if(productno==2 && stockamountB!=0 && deposit>=prices[1]) {
      printf("You have pressed button B.\n");
      stockamountB--;
      if (stockamountB==0) {
        stockB = 'X';
      }
      selecteditem = 'B';
      deposit=deposit-prices[1];
      revenue=revenue+prices[1];
      break;
    }
    else if(productno==3 && stockamountC!=0 && deposit>=prices[2]) {
      printf("You have pressed button C.\n");
      stockamountC--;
      if (stockamountC==0) {
        stockC = 'X';
      }
      selecteditem = 'C';
      deposit=deposit-prices[2];
      revenue=revenue+prices[2];
      break;
    }
    else if(productno==4 && stockamountD!=0 && deposit>=prices[3]) {
      printf("You have pressed button D.\n");
      stockamountD--;
      if (stockamountD==0) {
        stockD = 'X';
      }
      selecteditem = 'D';
      deposit=deposit-prices[3];
      revenue=revenue+prices[3];
      break;
    }
    else if(productno==5 && stockamountE!=0 && deposit>=prices[4]) {
      printf("You have pressed button E.\n");
      stockamountE--;
      if (stockamountE==0) {
        stockE = 'X';
      }
      selecteditem = 'E';
      deposit=deposit-prices[4];
      revenue=revenue+prices[4]; 
      break;
    }
    else if(productno==0) {
        printf("Going back!\n");
        break;
    }
    else if(!(productno==1 || productno==2 || productno==3 || productno==4 || productno==5 || productno==0)) {
      printf("Invalid choice!\n\n");
    }

    if(productno==1 && (stockamountA==0 || deposit<prices[0])) {
      printf("You have pressed button A.\n");break;
    }
    if(productno==2 && (stockamountB==0 || deposit<prices[1])) {
      printf("You have pressed button B.\n");break;
    }
    if(productno==3 && (stockamountC==0 || deposit<prices[2])) {
      printf("You have pressed button C.\n");break;
    }
    if(productno==4 && (stockamountD==0 || deposit<prices[3])) {
      printf("You have pressed button D.\n");break;
    }
    if(productno==5 && (stockamountE==0 || deposit<prices[4])) {
      printf("You have pressed button E.\n");break;
    }

  }

  if(stockamountA!=0 && deposit<prices[0]) {
    stockA = 32;
  }
  if(stockamountB!=0 && deposit<prices[1]) {
    stockB = 32;
  }
  if(stockamountC!=0 && deposit<prices[2]) {
    stockC = 32;
  }
  if(stockamountD!=0 && deposit<prices[3]) {
    stockD = 32;
  }
  if(stockamountE!=0 && deposit<prices[4]) {
    stockE = 32;
  }

  printf("\n");

  menu(prices, deposit, stockA, stockB, stockC, stockD, stockE);
  selecteditem = '='; 

}     

void menu4() {
  printf("(4) Return button is pressed.\n$%d has been returned.", deposit);
  deposit=0;
  if(stockA=='O') {
    stockA=' ';
  }
  if(stockB=='O') {
  stockB=' ';
  }
  if(stockC=='O') {
    stockC=' ';
  }
  if(stockD=='O') {
    stockD=' ';
  }
  if(stockE=='O') {
    stockE=' ';
  }
}

void changeproduct(char products[][21], int prices[], int ans4) {
  printf("Enter new product name:");
  for(int i=0; i<20;i++)
  products[ans4-1][i] = '\0';
  scanf("%s", products[ans4-1]);
  printf("Enter new product price:"); 
  scanf("%d", &prices[ans4-1]);
  if(ans4==1) {
  stockamountA=10;
  printf("The new product A has been filled to full.");
  }
  if(ans4==2) {
  stockamountB=10;
  printf("The new product B has been filled to full.");
  }
  if(ans4==3) {
  stockamountC=10;
  printf("The new product C has been filled to full.");
  }
  if(ans4==4) {
  stockamountD=10;
  printf("The new product D has been filled to full.");
  }
  if(ans4==5) {
  stockamountE=10;
  printf("The new product E has been filled to full.");
  }
  
}


void menu9(int ans2, char products[][21], int price[], int ans4) {
  int enteredcode;
  printf("(9) Opening service menu. Access code is required.\nEnter access code:"); 
  scanf("%d", &enteredcode);
  if(enteredcode==correctcode) {
      printf("Correct code!");
      for(;;) {
      printf("\n\n(9) What would you like to do?\n1. Inspect machine status\n2. Withdraw all money\n3. Refill product\n4. Change product\n0. Go back\nYour choice:");
      scanf("%d", &ans2);
      if(ans2==1) {
        printf("\n(9-1) Machine status\nAmount of revenue: $%d\nAmount of inserted coins: $%d\nProduct information:\nA. ", revenue, deposit);
        printf("%s ($%d) ", products[0], price[0]);
        if(stockamountA!=0) 
        printf("(%d left)\nB. ", stockamountA);
        else printf("(sold out)\nB. ");
        printf("%s ($%d) ", products[1], price[1]);
        if(stockamountB!=0) 
        printf("(%d left)\nC. ", stockamountB);
        else printf("(sold out)\nC. ");
        printf("%s ($%d) ", products[2], price[2]);
        if(stockamountC!=0) 
        printf("(%d left)\nD. ", stockamountC);
        else printf("(sold out)\nD. ");
        printf("%s ($%d) ", products[3], price[3]);
        if(stockamountD!=0) 
        printf("(%d left)\nE. ", stockamountD);
        else printf("(sold out)\nE. ");
        printf("%s ($%d) ", products[4], price[4]);
        if(stockamountE!=0) 
        printf("(%d left)\n", stockamountE);
      }
      else if(ans2==2) {
        printf("\n(9-2) Inserted coins are being withdrawn.\n$%d is withdrawn.", (deposit+revenue));
        deposit=0;
        revenue=0;
      }
      else if(ans2==3) {
          int ans3;
          printf("\n(9-3) Which product would you like to refill?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
          scanf("%d", &ans3);
          if(ans3==1) {
            stockamountA=10;
            printf("You have refilled product A to full.");
          }
          else if(ans3==2) {
            stockamountB=10;
            printf("You have refilled product B to full.");
          }
          else if(ans3==3) {
            stockamountC=10;
            printf("You have refilled product C to full.");
          }
          else if(ans3==4) {
            stockamountD=10;
            printf("You have refilled product D to full.");
          }
          else if(ans3==5) {
            stockamountE=10;
            printf("You have refilled product E to full.");
          }
          else if(ans3==0) {
            printf("Going back!");
          }
          else{printf("Invalid choice!");}
        }
      else if(ans2==4) {
        for(;;) {
          printf("\n(9-4) Which product would you like to change?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
          scanf("%d", &ans4);
          if(ans4==1) {
              printf("You are changing product A.\n\n");
              changeproduct(products, price, ans4);break;
            }
          else if(ans4==2) {
              printf("You are changing product B.\n\n");
              changeproduct(products, price, ans4);break;
            }
          else if(ans4==3) {
              printf("You are changing product C.\n\n");
              changeproduct(products, price, ans4);break;
            }
          else if(ans4==4) {
              printf("You are changing product D.\n\n");
              changeproduct(products, price, ans4);break;
            }
          else if(ans4==5) {
              printf("You are changing product E.\n\n");
              changeproduct(products, price, ans4);break;
            }
          else if(ans4==0) {
              printf("Going back!");break;
            }
          else{printf("Invalid choice!");break;}
            
          }
        }

      else if(ans2==0) {
        printf("Going back!\n");
        break;
      }
      else{printf("Invalid choice!");}

      if(stockamountA!=0 && deposit<price[0]) {
        stockA = 32;
      }
      if(stockamountB!=0 && deposit<price[1]) {
        stockB = 32;
      }
      if(stockamountC!=0 && deposit<price[2]) {
        stockC = 32;
      }
      if(stockamountD!=0 && deposit<price[3]) {
        stockD = 32;
      }
      if(stockamountE!=0 && deposit<price[4]) {
        stockE = 32;
      }
      if (stockamountA==0) {
      stockA = 'X';
      }
      if (stockamountB==0) {
      stockB = 'X';
      }
      if (stockamountC==0) {
      stockC = 'X';
      }
      if (stockamountD==0) {
      stockD = 'X';
      }
      if (stockamountE==0) {
      stockE = 'X';
      }  

    }  
  }
  else printf("Incorrect code!");
}

int main(void) {
  char product[5][21] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
  int prices[5] = {10,6,5,8,7};
  menu(prices, deposit, stockA, stockB, stockC, stockD, stockE);
  for(;;) {
    ques0loop();
    if(ans1==1) {
      printf("\n");
      menu1(product, prices);
      printf("\n");
    }
    if(ans1==2) {
      printf("\n");
      menu2(prices);
      menu(prices, deposit, stockA, stockB, stockC, stockD, stockE);

    }
    if(ans1==3) {
      printf("\n");
      menu3(prices);
      
    }
    
    if(ans1==4) {
      printf("\n");
      menu4();
      printf("\n\n");
      menu(prices, deposit, stockA, stockB, stockC, stockD, stockE);
    }

    if(ans1==9) {
      printf("\n");
      menu9(ans2, product, prices, ans4);
      printf("\n");
      menu(prices, deposit, stockA, stockB, stockC, stockD, stockE);
    }

    if(ans1==0) {
      break;
    }

  }

  return 0;
}

