node searchByID(node root, char *id)
{
    if (root == NULL)
    {
        printf("No\n");
        return root;
    }
    for (node temp = root; temp != NULL; temp = temp->next)
    {
        if (strcmp(id, temp->stu.id) == 0)
        {
            printf("%s %s %d\n", temp->stu.id, temp->stu.name, temp->stu.grade);
            return temp;
        }
    }
    return NULL;
}