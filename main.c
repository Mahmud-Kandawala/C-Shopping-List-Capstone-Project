#include <stdio.h>   // Include Standard Input Output header for IO operations.
#include <stdlib.h>  // Include Standard Library for functions like malloc.
#include <string.h>  // Include String header for string manipulation functions.
#define MAX 20       // Define a constant MAX with a value of 20.

// Declaration of a structure named 'head' representing a node in a doubly linked list.
struct head{
    struct head *next; // Pointer to the next node in the list.
    struct head *prev; // Pointer to the previous node in the list.
    struct prod *add;  // Pointer to a structure 'prod' containing product details.
};

// Declaration of a structure named 'prod' for storing product details.
struct prod{
    char p[15]; // Array of characters to store the product name (maximum of 15 characters).
    float c;    // Float variable to store the cost of the product.
};

// Declaration of a structure named 'tree' for nodes in a binary search tree.
struct tree{
    struct tree *left;  // Pointer to the left child in the tree.
    struct tree *right; // Pointer to the right child in the tree.
    struct prod *link;  // Pointer to a 'prod' structure linked with this tree node.
};

//variable declaration
int top=-1;                 // Integer variable 'top' initialized to -1, used as a stack pointer.
char lseen[100];            // Character array 'lseen' of size 100 to store the name of the last seen product.
struct head *strt=NULL;     // Pointer to the first 'head' node in the doubly linked list, initialized to NULL.
struct tree *root=NULL;     // Pointer to the root node of the binary search tree, initialized to NULL.

//          method declaration
void Push(char *, float); // Prototype for the Push function to add products to the cart.
void Display();           // Prototype for the Display function to show cart contents.
void Search(char *, char); // Prototype for the Search function to find and possibly delete a product.
void Pop();               // Prototype for the Pop function to remove the last product from the cart.
void Qdelete();           // Prototype for the Qdelete function to delete the first product from the cart.


void Display(){
    if(top==-1){  // Check if the cart is empty (top == -1).
        printf("\nSorry your cart is empty, please try putting something in the list first");
        return;   // Return from the function if the cart is empty.
    }
    float total=0.0;  // Initialize a float variable 'total' to store the total cost.
    struct head *q=strt;  // Create a pointer 'q' of type 'head' and set it to point to the start of the list.
    printf("\n\t\t\tYour Shopping List:");  // Print a message indicating the start of the shopping list.
    printf("\n\t\tITEM NAME\t\t    COST");  // Print column headers for item name and cost.
    for(int i=0;i<=top;i++){  // Loop from 0 to 'top' to iterate through the cart items.
        total=total+q->add->c;  // Add the cost of the current product to 'total'.
        printf("\n%24s%24.2f",q->add->p,q->add->c);  // Print the product name and cost.
        q=q->next;  // Move to the next product in the list.
    }
    printf("\nTotal # of items = %d\t\tTotal price = $%0.2f",(top+1),total);  // Print the total number of items and total price.

return;  // Return from the function.
}


void Qdelete(){
    if(top==-1){  // Check if the cart is empty.
        printf("\nYour cart is already empty, try putting some item in the cart first.");
        return;  // Return from the function if the cart is empty.
    }
    if(top==0){  // Check if there is only one item in the cart.
        strt=NULL;  // Set the start of the list to NULL.
        printf("\nYour cart is now empty, try putting some items into it");
        top--;  // Decrement 'top'.
        return;  // Return from the function.
    }
    struct head *r=strt;  // Create a pointer 'r' of type 'head' and set it to the start of the list.
    strt=r->next;  // Move the start of the list to the next node.
    strt->prev=NULL;  // Set the 'prev' of the new start node to NULL.
    top--;  // Decrement 'top'.

return;  // Return from the function.
}


void Pop(){
    if(top==-1){  // Check if the cart is empty.
        printf("\nYour cart is already empty, try putting some item in the cart first.");
        return;  // Return from the function if the cart is empty.
    }
    if(top==0){  // Check if there is only one item in the cart.
        strt=NULL;  // Set the start of the list to NULL.
        printf("\nYour cart is now empty, try putting some items into it");
        top--;  // Decrement 'top'.
        return;  // Return from the function.
    }
    struct head *r=strt;  // Create a pointer 'r' of type 'head' and set it to the start of the list.
    top--;  // Decrement 'top'.
    for(int i=0;i<top;i++){  // Loop until reaching the second-last item in the list.
        r=r->next;  // Move to the next node in the list.
    }
    r->next=NULL;  // Set the 'next' of the last node to NULL, effectively removing the last item.

return;  // Return from the function.
}


void Push(char *item, float value){
    if(top==MAX){  // Check if the cart is full.
        printf("\nYour shopping cart is full, try to delete some item from your list");
        return;  // Return from the function if the cart is full.
    }
    struct head *q=(struct head *)malloc(sizeof(struct head));  // Dynamically allocate memory for a new 'head' node.
    struct tree *t=(struct tree *)malloc(sizeof(struct tree));  // Dynamically allocate memory for a new 'tree' node.
    struct prod *w=(struct prod *)malloc(sizeof(struct prod));  // Dynamically allocate memory for a new 'prod' structure.
    // Initialize the newly allocated nodes and structures
    q->next=NULL;  // Set the 'next' of the new 'head' node to NULL.
    q->add=w;  // Link the 'prod' structure with the 'head' node.
    w->c=value;  // Set the cost in the 'prod' structure.
    strcpy(w->p,item);  // Copy the item name into the 'prod' structure.
    t->link=w;  // Link the 'prod' structure with the 'tree' node.
    t->left=NULL;  // Set the left child of the 'tree' node to NULL.
    t->right=NULL;  // Set the right child of the 'tree' node to NULL.
    // Insertion logic for the first item in the cart
    if(top==-1){
        strt=q;  // Set the start of the list to the new 'head' node.
        q->prev=NULL;  // Set the 'prev' of the new 'head' node to NULL.
        q->next=NULL;  // Set the 'next' of the new 'head' node to NULL.
        q->add=w;  // Link the 'prod' structure with the 'head' node.
        top++;  // Increment 'top'.
        strcpy(w->p,item);  // Copy the item name into the 'prod' structure.
        w->c=value;  // Set the cost in the 'prod' structure.
        root=t;  // Set the root of the tree to the new 'tree' node.
        t->link=w;  // Link the 'prod' structure with the 'tree' node.
        t->left=NULL;  // Set the left child of the 'tree' node to NULL.
        t->right=NULL;  // Set the right child of the 'tree' node to NULL.
        return;  // Return from the function.
    }
    // Insertion logic for subsequent items in the cart
    struct head *r=strt;  // Create a pointer 'r' of type 'head' and set it to the start of the list.
    for(int i=0;i<top;i++){  // Loop to find the last node in the list.
        r=r->next;  // Move to the next node in the list.
    }
    q->prev=r;  // Set the 'prev' of the new 'head' node to the last node in the list.
    r->next=q;  // Link the last node in the list to the new 'head' node.
    top++;  // Increment 'top'.
    // Insertion

 //pushing value in tree
struct tree *temp = root; // Start with the root of the tree
while(temp != NULL){ // Traverse the tree until a suitable spot is found
    if(strcmp(temp->link->p, item) < 0){ // Compare the current item with the item in the node
        if(temp->left == NULL){ // If the left child is NULL, insert the node here
            temp->left = t; // Set the left child of the current node to the new node
            break; // Exit the loop as the insertion is done
        }
        else
            temp = temp->left; // Move to the left child for further searching
    }
    else{ // If the item is greater than or equal to the current item
        if(temp->right == NULL){ // If the right child is NULL, insert the node here
            temp->right = t; // Set the right child of the current node to the new node
            break; // Exit the loop as the insertion is done
        }
        else
            temp = temp->right; // Move to the right child for further searching
    }
}
return; // End of this section of the Push function
}

void Search(char *item, char d){ // Function to search for an item in the tree; 'd' is the action to perform (display or delete)
    struct tree *temp = root, *a = NULL, *hold; // Temporary pointers for tree traversal; 'a' will hold the parent node
    int flag; // Flag to indicate whether the node is a left (0) or right (1) child
    struct head *temp2 = strt, *storage; // Pointers for linked list traversal
    char product[100]; // Buffer to store the product name
    strcpy(product, item); // Copy the item name to 'product'

    // Search the tree for the item
    while(temp != NULL && strcmp(temp->link->p, product) != 0){
        a = temp; // Keep track of the parent node
        if(strcmp(temp->link->p, product) < 0){
            temp = temp->left; // Move to the left child
            flag = 0; // Set flag to indicate left child
        }
        else{
            temp = temp->right; // Move to the right child
            flag = 1; // Set flag to indicate right child
        }
    }

    // If 'd' is 's', display the item's information
    if(d == 's'){
        if(temp != NULL)
            printf("\nProduct Name: %s\t Cost: %0.2f", temp->link->p, temp->link->c);
        else
            printf("\nSorry your item doesn't exist in cart, try another search.\n");
    }
    // If 'd' is 'd', delete the item from the cart
    else if(d == 'd'){
        // Deleting item from stack (linked list)
        while(temp2 != NULL && strcmp(temp2->add->p, product) != 0)
            temp2 = temp2->next; // Traverse the linked list
        if(top == 0 && temp2 != NULL){ // If there's only one item in the cart
            strt = NULL; // Set the start of the list to NULL
            top--; // Decrement the top index
        }
        else if(temp2 != NULL && temp2->next != NULL){ // If the item is in the middle of the list
            storage = temp2->next; // Hold the next node
            storage->prev = temp2->prev; // Update the previous pointer of the next node
            storage = temp2->prev; // Hold the previous node
            storage->next = temp2->next; // Update the next pointer of the previous node
            top--; // Decrement the top index
            printf("\nYour item has been deleted from cart");
        }
        else if(temp2 != NULL && temp2->next == NULL){ // If the item is the last in the list
            storage = temp2->prev; // Hold the previous node
            storage->next = NULL; // Set the next pointer of the previous node to NULL
        }
        // Deleting element from tree
        if(temp != NULL){
            // Case 1: Node with no children
            if(temp->left == NULL && temp->right == NULL){
                if(flag == 0)
                    a->left = NULL; // If temp is a left child, set parent's left to NULL
                else if(flag == 1)
                    a->right = NULL; // If temp is a right child, set parent's right to NULL
                if(strcmp(root->link->p, product) == 0)
                    root = a; // Update root if necessary
            }
            // Case 2: Node with only left child
            else if(temp->left != NULL && temp->right == NULL){
                if(flag == 0)
                    a->left = temp->left; // Set parent's left to temp's left child
                else if(flag == 1)
                    a->right = temp->left; // Set parent's right to temp's left child
                if(strcmp(root->link->p, product) == 0)
                    root = temp->left; // Update root if necessary
            }
            // Case 3: Node with only right child
            else if(temp->left == NULL && temp->right != NULL){
                if(flag == 0)
                    a->left = temp->right; // Set parent's left to temp's right child
                else if(flag == 1)
                    a->right = temp->right; // Set parent's right to temp's right child
                if(strcmp(root->link->p, product) == 0)
                    root = temp->right; // Update root if necessary
            }
            // Case 4: Node with two children
            else if(temp->left != NULL && temp->right != NULL){
                if(temp->right->left == NULL){
                    if(flag == 0)
                        a->left = temp->right; // Set parent's left to temp's right child
                    else if(flag == 1)
                        a->right = temp->right; // Set parent's right to temp's right child
                    temp->right->left = temp->left; // Set right child's left to temp's left child
                    if(strcmp(root->link->p, product) == 0)
                        root = temp->right; // Update root if necessary
                }
                else{
                    temp = temp->right;
                    hold = temp;
                    // Finding inorder successor
                    while(temp->left->left != NULL){
                        temp = temp->left;
                    }
                    if(a != NULL){
                        if(flag == 0){
                            temp->left->left = a->left->left;
                            a->left = temp->left;
                        }
                        else if(flag == 1){
                            temp->left->left = a->right->left;
                            a->right = temp->left;
                        }
                    }
                    else if(strcmp(root->link->p, product) == 0){
                        temp->left->left = root->left;
                        root = temp->left;
                    }
                    temp->left->right = hold;
                    temp->left = temp->left->right;
                }
            }
        }
        else
            printf("\nSorry your item doesn't exist in cart, try another search.\n");
    }
return;
}


int main(){
    // Variable initialization
    char *item = (char *)malloc(sizeof(char)); // Dynamically allocate memory for item
    float price; // Variable to store price
    char choice; // Variable to store user's choice
    int i = 1; // Loop counter

    // Display menu
    printf("\n\t\t          Mahmud Kandawala C Project");
    printf("\n\t\t\tPLEASE ENTER EVERYTHING IN CAPS\nChoose An Option:\nA.Add Product\nD.Delete Product\nP.Pop Out Last Seen\nS.Search Product\nC.See Cart\nQ.Quit");

    // Main loop for menu-driven options
    while(choice != 'Q'){
        i++;
        // Clear screen every 10 iterations
        if(i % 10 == 0){
            system("cls"); // Clear screen
            // Reprint the menu
            printf("\n\t\t\tPLEASE ENTER EVERYTHING IN CAPS\nChoose An Option:\nA.Add Product\nD.Delete Product\nP.Pop Out Last Seen\nS.Search Product\nC.See Cart\nQ.Quit");
        }
        printf("\nEnter Your Choice: ");
        choice = getche(); // Get user choice

        // Switch-case for handling different choices
        switch(choice){
        case 'A': // Add product
            printf("\nEnter Product Name & Cost: ");
            scanf("%s %f", item, &price); // Input product name and cost
            Push(item, price); // Call Push function
            strcpy(lseen, item); // Update last seen item
            break;
        case 'D': // Delete product
            printf("\n1.Delete From Last\n2.Delete From First\n3.Delete A Particular Product\n");
            choice = getche(); // Get specific delete choice
            // Handle different delete options
            if(choice == '1')
                Pop(); // Pop the last item
            else if(choice == '2')
                Qdelete(); // Delete the first item
            else if(choice == '3'){
                printf("\nEnter Product Name: ");
                scanf("%s", item); // Input product name
                Search(item, 'd'); // Delete specific item
            }
            break;
        case 'P': // Pop out last seen
            printf("\n%s is popped out", &lseen); // Display last seen item
            Search(lseen, 'd'); // Delete last seen item
            break;
        case 'S': // Search product
            printf("\nEnter Product Name: ");
            scanf("%s", item); // Input product name
            strcpy(lseen, item); // Update last seen item
            Search(item, 's'); // Search for specific item
            break;
        case 'C': // See cart
            Display(); // Display cart contents
            break;
        case 'Q': // Quit
            printf("\n\t\tThanks for using the program!\n");
            break;
        default: // Wrong input
            printf("\nWrong input...try again!\n");
        }
    }
    getch(); // Wait for a keypress

return 0; // End of main function
}