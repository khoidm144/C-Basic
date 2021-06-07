// node freeTree(node root)
// {
//     if (root == NULL)
//     {
//         return root;
//     }
//     freeTree(root->leftChild);
//     freeTree(root->rightChild);
//     free(root);
//     return NULL;
// }


// node findMin(node root)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->leftChild == NULL)
//     {
//         return root;
//     }
//     return findMin(root->leftChild);
// }



// node removeWord(node root, char *name)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     int cmp = strcmp(name, root->english);
//     if (cmp > 0)
//     {
//         root->rightChild = removeWord(root->rightChild, name);
//         return root;
//     }
//     else if (cmp < 0)
//     {
//         root->leftChild = removeWord(root->leftChild, name);
//         return root;
//     }
//     else
//     {
//         if (root->leftChild != NULL && root->rightChild != NULL)
//         {
//             node temp = findMin(root->rightChild);
//             strcpy(root->english, temp->english);
//             strcpy(root->vietnamese, temp->vietnamese);
//             root->rightChild = removeWord(root->rightChild, temp->english);
//         }
//         else
//         {
//             node temp = root;
//             if (root->leftChild == NULL)
//             {
//                 root = root->rightChild;
//             }
//             else
//             {
//                 root = root->leftChild;
//             }
//             free(temp);
//         }
//     }
//     return root;
// }




// case 4:
// {
//     char str[30];
//     printf("Input the English key word you want to remove : ");
//     scanf("%[^\n]%*c", str);
//     root = removeWord(root, str);
//     break;
// }
// case 5:
// {
//     root = freeTree(root);
//     break;
// }