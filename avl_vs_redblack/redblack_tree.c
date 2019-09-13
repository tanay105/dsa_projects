#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  enum nodeColor 
  {
        RED,
        BLACK
  };

  struct rbNode
  {
        int data, color;
        struct rbNode *link[2];
  };

  struct rbNode *root = NULL;
  
  struct rbNode * createNode(int);
  void insertion (int); 
  void deletion(int);
  void searchElement(int);
  void inorderTraversal(struct rbNode *);
  
  int main() 
  {
  		// Analysis 1																		//for checking the function working
  		
        /*int ch, data;
        printf("Hello and welcome to the Red-black tree implementation\n");
        while (1) 
		{
				printf("\nTo perform the following operations please enter the respective number:-\n");
                printf("1. Insertion\n2.Searching\n3. Traverse\n4. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) 
				{
                        case 1:
                                printf("Enter the data to insert:");
                                scanf("%d", &data);
                                clock_t start=clock();
                                insertion(data);
                                clock_t end=clock(); 
                                printf("\n");
                				double dif=((double)(end-start));
        						printf("\n\ntime is : %f",dif);
        						break;
    
                        case 2:
                                printf("Enter the search element:");
                                scanf("%d", &data);
                                searchElement(data); 
                                break;
                        case 3:
                                inorderTraversal(root);
                                printf("\n");
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("You have entered wrong option!!\n");
                                break;
                }
                
        }*/
        
        // Analysis 2																//for checking the time of insertion or deletion
        
        int i;
        clock_t start=clock();
        for(i=0;i<10000000;i++)
        {
        	insertion(i+1);
        }
        clock_t end=clock();    
        double dif=((double)(end-start));
        printf("\n\ntime is : %f",dif);
        
        // Analysis 3																//for checking the time for searching
        
        /*int i,data;
        
        for(i=0;i<10000000;i++)
        {
        	insertion(i+1);
        }
        //printf("Enter the search element:");
        //scanf("%d", &data);
        clock_t start=clock();
        for(i=0;i<10000000;i++)
        {
        	searchElement(i+1);
        }
        clock_t end=clock();    
        double dif=((double)(end-start));
        printf("\n\ntime is : %f",dif);*/
        return 0;
  }

  struct rbNode * createNode(int data) 
  {
        struct rbNode *newnode;
        newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
        newnode->data = data;
        newnode->color = RED;
        newnode->link[0] = newnode->link[1] = NULL;
        return newnode;
  }

  void insertion (int data) 
  {
        struct rbNode *stack[100], *ptr, *newnode, *xPtr, *yPtr;
        int dir[100], ht = 0, index;
        newnode = createNode(data);
        ptr = root;
        if (root==NULL) 
		{
                root = createNode(data);
                return;
        }
        stack[ht] = root;
        dir[ht] = 0;
        ht++;
        while (ptr != NULL) 					/* find the place to insert the new node */
		{
                if (ptr->data == data) 
				{
                        printf("Duplicates Not Allowed!!\n");
                        return;
                }
                if((data - ptr->data) > 0)
                	index=1;
                else
                	index=0;
                stack[ht] = ptr;
                ptr = ptr->link[index];
                dir[ht++] = index;
        }
        /* insert the new node */
        stack[ht - 1]->link[index] = newnode;
        while ((ht >= 3) && (stack[ht - 1]->color == RED)) 
		{
                if (dir[ht - 2] == 0) 
				{
                        yPtr = stack[ht - 2]->link[1];
                        if (yPtr != NULL && yPtr->color == RED) 
						{
                                stack[ht - 2]->color = RED;
                                stack[ht - 1]->color = yPtr->color = BLACK;
                                ht = ht -2;
                        } 
						else 
						{
                                if (dir[ht - 1] == 0) 										//left left case;
								{
                                        yPtr = stack[ht - 1];
                                } 
								else
								{
                                        xPtr = stack[ht - 1];								//left right case
                                        yPtr = xPtr->link[1];
                                        xPtr->link[1] = yPtr->link[0];
                                        yPtr->link[0] = xPtr;
                                        stack[ht - 2]->link[0] = yPtr;
                                }
                                xPtr = stack[ht - 2];										//performing the rotations
                                xPtr->color = RED;
                                yPtr->color = BLACK;
                                xPtr->link[0] = yPtr->link[1];
                                yPtr->link[1] = xPtr;
                                if (xPtr == root) 
								{
                                        root = yPtr;
                                } 
								else 														//assigning parent to its grandparent
								{
                                        stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                                }
                                break;
                        }
                } 
				else 
				{
                        yPtr = stack[ht - 2]->link[0];
                        if ((yPtr != NULL) && (yPtr->color == RED)) 
						{
                                stack[ht - 2]->color = RED;
                                stack[ht - 1]->color = yPtr->color = BLACK;
                                ht = ht - 2;
                        } 
						else 
						{
                                if (dir[ht - 1] == 1) 										//right right case
								{
                                        yPtr = stack[ht - 1];
                                } 
								else 														//right left case
								{
                                        xPtr = stack[ht - 1];
                                        yPtr = xPtr->link[0];
                                        xPtr->link[0] = yPtr->link[1];
                                        yPtr->link[1] = xPtr;
                                        stack[ht - 2]->link[1] = yPtr;
                                }
                                xPtr = stack[ht - 2];
                                yPtr->color = BLACK;
                                xPtr->color = RED;
                                xPtr->link[1] = yPtr->link[0];
                                yPtr->link[0] = xPtr;
                                if (xPtr == root) 
								{
                                        root = yPtr;
                                } 
								else 
								{
                                        stack[ht - 3]->link[dir[ht - 3]] = yPtr;
                                }
                                break;
                        }
                }
        }
        root->color = BLACK;
  }

  

  void searchElement(int data)
  {
        struct rbNode *temp = root;
        int diff;

        while (temp != NULL) 
		{
                diff = data - temp->data;
                if (diff > 0) 
				{
                        temp = temp->link[1];
                } else if (diff < 0) 
				{
                        temp = temp->link[0];
                } else 
				{
                        //printf("Search Element Found!!\n");
                        return;
                }
        }
        printf("Given Data Not Found in RB Tree!!\n");
        return;
  }

  void inorderTraversal(struct rbNode *node) 
  {
        if (node) 
		{
                inorderTraversal(node->link[0]);
                printf("%d  ", node->data);
                inorderTraversal(node->link[1]);
        }
        return;
  }

  

