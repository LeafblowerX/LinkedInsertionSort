#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define END_STRING "***\n"
#define MAX_LEN 33
#define ACCEPTED_CHAR "-\"'"
#define ACCEPTED 0
#define REJECTED 1
typedef struct Node{

    char value[MAX_LEN];

    struct Node* next;

} Node;




void toLowerCase(char raw[]){


        for(int i = 0; i < (int) strlen(raw); i++){
          raw[i] = tolower(raw[i]);
        }


 

}
int checkAcceptibility(char str[]){
    
        for(int i = 0; i<strlen(str) -1;i++){
           
                if(isalpha(str[i]) == 0 && strchr(ACCEPTED_CHAR,str[i]) == NULL){
                  
                    return REJECTED;

                }



        }

        return ACCEPTED;



}
//arg is starting node to deletefrom
void removeNodes(Node* NodePtr){
  
      if(NodePtr->next != NULL){
          removeNodes(NodePtr->next);

          }
          free(NodePtr);
          NodePtr = NULL;
          
  
  }





int main(){
    char input[MAX_LEN];
    
        
        Node* head;
        Node* current;
        int init = 0;
   

     printf("Please enter a word: ");
    fgets(input, MAX_LEN, stdin);

      
    toLowerCase(input); //change input to lowercase
     
    while(checkAcceptibility(input) == REJECTED){
           if(strcmp(input, END_STRING) == 0){
                      break;
                      }
        
            printf("Rejected.\nPlease enter a word: ");
            memset(input, 0 , sizeof input);
            fgets(input, MAX_LEN, stdin);
       
    }
    toLowerCase(input); 

    while(strcmp(input, END_STRING) != 0)
    {
        //head is null
        if(init == 0){
            head = (Node*) malloc(sizeof(Node));
            strcpy(head->value,input);
            head->next = NULL;
            current = head;
           
            init = 1;
            continue;
        } else{
           
           
            printf("Please enter a word: ");
            memset(input, 0 , sizeof input);
            fgets(input, MAX_LEN, stdin);
            
            toLowerCase(input);

              while(checkAcceptibility(input) == REJECTED){
                  if(strcmp(input, END_STRING) == 0){
                      break;
                      }
                    printf("Rejected.\nPlease enter a word: ");
                    memset(input, 0 , sizeof input);
                    fgets(input, MAX_LEN, stdin);
                  
            }
                toLowerCase(input); 
             //change input to lowercase
             if(strcmp(input, END_STRING) != 0){
             //printf("Your input: %s \n", input);  
           
             } else{

                 printf("All the entered words in order: \n");
                 printf("%s",head->value);
                 current = head->next;
                while(current != NULL)
                 {
                  
                     
                     printf("%s",current->value);
                     
                      current = current->next;
 
                 }
                  break;
             }
        }
        
            //input comes before previous node's value e.g. B followed by A (input)
            if(strcmp(input, current->value) < 0){
               
                  current = head; //since head is not null at this point

                if(current->next != NULL){
                  while(current->next != NULL){     
                    
                        if(strcmp(input, current->next->value) < 0){
                                //input comes before next node value

                                
                              
                              
                               Node* InsertionPtr = (Node*) malloc(sizeof(Node));

                               strcpy(InsertionPtr->value,input);

                                //if insertionPtr value< LHS node (current) given current starts from head && current->next != null &&  insertionPtr value< RHS node (current->next)
                                 if(strcmp(input, current->value) < 0){


                                    InsertionPtr->next = current; 
                                    head = InsertionPtr;
                                    


                                }else{
                                InsertionPtr->next = current->next;
                                 current->next = InsertionPtr;
                                }
                               
                                    //standardise current to last node for the next iteration
                                    while(current->next != NULL){
                                        current = current->next;
                                       
                                    }
                               
                                break;
                            


                        }else{
                          
                                current = current->next;
                        }


                  }
                }
                else{
                   
                    
                     Node* InsertionPtr = (Node*) malloc(sizeof(Node));
                     strcpy(InsertionPtr->value,input);
                     InsertionPtr->next = current; 
                     head = InsertionPtr;

                     
                }




            }else{
                //input comes after
                //assumes the current node is the last 
              
                Node * NEXT_PTR =(Node *) malloc(sizeof(Node));
              
                strcpy(NEXT_PTR->value, input);
                current->next = NEXT_PTR;
                
                 current = current->next;
                 current->next = NULL;
                 
              


             }


       

    }




  removeNodes(head);
   
  printf("Deallocated Linkedlist");
    return 0;



}

