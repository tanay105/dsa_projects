#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node																						//defining the node structure
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

struct node *newNode(int);
struct node* insert(struct node*, int);
struct node *left(struct node *);
struct node *right(struct node *);
void searchElement(struct node* ,int );
int checkBalancing(struct node *);
void inOrder(struct node *);
int max(int , int );
int height(struct node *);

int main()
{
	// Analysis 1
	/*struct node *root = NULL;
	int ch, data;
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
                                root=insert(root,data);
                                clock_t end=clock(); 
                                printf("\n");
                				double dif=((double)(end-start));
        						printf("\n\ntime is : %f",dif);
        						break;
    
                        case 2:
                                printf("Enter the search element:");
                                scanf("%d", &data);
                                searchElement(root,data); 
                                break;
                        case 3:
                                inOrder(root);
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
	
  	struct node *root = NULL;
 	int i;																		
    clock_t start=clock();
    for(i=0;i<10000000;i++)
    {
        root=insert(root,i+1);
    }
    clock_t end=clock();
    double dif=((double)(end-start));
    printf("\n\ntime is : %f",dif);
    
    // Analysis 3	
																				//for checking the time for searching
    /*struct node *root = NULL;
    int i,data;
        
        for(i=0;i<10000000;i++)
        {
        	root=insert(root,i+1);
        }
        printf("enter");
        getchar();
        clock_t start=clock();
        for(i=0;i<10000000;i++)
        {
        	searchElement(root,i+1);
        }
        clock_t end=clock();    
        double dif=((double)(end-start));
        printf("\n\ntime is : %f",dif);*/
    	return 0;
}

struct node *newNode(int data)																//function for creating nodes
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 0;  
    return(node);
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)																			//check if root is null or not
        return(newNode(key));
        
    if (key < node->key)
        node->left  = insert(node->left, key);
    
    else
        node->right = insert(node->right, key);
 
    node->height = max(height(node->left), height(node->right)) + 1;
 	
    int balance = checkBalancing(node);
    
    if (balance > 1 && key < node->left->key)													//Left left case
        return right(node);
 
    if (balance < -1 && key > node->right->key)													//right right case
        return left(node);
 
    if (balance > 1 && key > node->left->key)													// Left Right Case
    {
        node->left =  left(node->left);
        return right(node);
    }
 
    if (balance < -1 && key < node->right->key)													// Right Left Case
    {
        node->right = right(node->right);
        return left(node);
    }
 
    return node;
}
 
struct node *right(struct node *y)
{
    struct node *x = y->left;
    struct node *z = x->right;
    x->right = y;
    y->left = z;
    if(height(y->left), height(y->right))
    {
    	 y->height =height(y->left)+1;
    }
    else
    {
    	y->height =height(y->right)+1;
    }
    if(height(x->left), height(x->right))
    {
    	x->height = height(x->left)+1;
    }
    else
    {
    	x->height =height(x->right)+1;
    }
    return x;
}
 
struct node *left(struct node *x)
{
    struct node *y = x->right;
    struct node *z = y->left;
    y->left = x;
    x->right = z;
    if(height(y->left), height(y->right))
    {
    	 y->height =height(y->left)+1;
    }
    else
    {
    	y->height =height(y->right)+1;
    }
    if(height(x->left), height(x->right))
    {
    	x->height = height(x->left)+1;
    }
    else
    {
    	x->height =height(x->right)+1;
    }
    return y;
}

int checkBalancing(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

void inOrder(struct node *root)												//inoreder traversal for the AVL tree
{
    if(root != NULL)
    {
    	inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void searchElement(struct node* node,int data)
  {
        struct node *temp = node;
        int diff;

        while (temp != NULL) 
		{
                diff = data - temp->key;
                if (diff > 0) 
				{
                        temp = temp->right;
                } 
				else if (diff < 0) 
				{
                        temp = temp->left;
                } 
				else 
				{
                        //printf("Search Element Found!!\n");
                        return;
                }
        }
        printf("Given Data Not Found in RB Tree!!\n");
        return;
  }
  
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
 

