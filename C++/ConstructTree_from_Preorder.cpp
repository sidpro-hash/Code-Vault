// Create a stack of capacity equal to size
    Stack* stack = createStack( size );
 
    // The first element of pre[] is always root
    Node* root = newNode( pre[0] );
 
    // Push root
    push( stack, root );
 
    int i;
    Node* temp;
 
    // Iterate through rest of the size-1 items of given preorder array
    for ( i = 1; i < size; ++i )
    {
        temp = NULL;
 
        /* Keep on popping while the next value is greater than
        stack's top value. */
        while ( !isEmpty( stack ) && pre[i] > peek( stack )->data )
            temp = pop( stack );
 
        // Make this greater value as the right child
                // and push it to the stack
        if ( temp != NULL)
        {
            temp->right = newNode( pre[i] );
            push( stack, temp->right );
        }
 
        // If the next value is less than the stack's top
                // value, make this value as the left child of the
                // stack's top node. Push the new node to stack
        else
        {
            peek( stack )->left = newNode( pre[i] );
            push( stack, peek( stack )->left );
        }
    }
 
    return root;