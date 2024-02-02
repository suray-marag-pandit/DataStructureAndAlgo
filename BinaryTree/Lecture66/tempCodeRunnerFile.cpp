        if (inorder[i] == target)
            return i;
    }
    return -1;
}

node *inPostBuild(int inorder[], int postorder[], int &index, int instart, int inend, int size)
{
    if (index < 0 || instart > inend)
    {
        return NULL;
    }

    int temp = postorder[index--];
    node *root = new node(temp);
    int position = pos(inorder, temp, size);

    root->right = inPostBuild(inorder, postorder, index, position + 1, inend, size);
    root->left = inPostBuild(inorder, postorder, index, instart, position - 1, size);

    return root;
}

int main()
{

    node *root = NULL;