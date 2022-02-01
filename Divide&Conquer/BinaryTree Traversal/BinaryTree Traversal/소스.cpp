#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
}BTreeNode;

BTreeNode* bstRoot;

BTreeNode* MakeBTreeNode(void);
BTData getData(BTreeNode* bt);
void setData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void(*VisitFuncPtr)(BTData data);

void inorder_traversal(BTreeNode* bt, VisitFuncPtr action);
void preorder_traversal(BTreeNode* bt, VisitFuncPtr action);
void postorder_traversal(BTreeNode* bt, VisitFuncPtr action);

typedef BTData BSTData;

void createBST(BTreeNode** pRoot);
BSTData BSTGetNodeData(BTreeNode* bst);
void BST_insert_node(BTreeNode** pRoot, BSTData data);
void ShowIntData(int data);

int main()
{
    createBST(&bstRoot);

    BST_insert_node(&bstRoot, 60);
    BST_insert_node(&bstRoot, 41);
    BST_insert_node(&bstRoot, 74);
    BST_insert_node(&bstRoot, 16);
    BST_insert_node(&bstRoot, 53);
    BST_insert_node(&bstRoot, 25);
    BST_insert_node(&bstRoot, 46);
    BST_insert_node(&bstRoot, 55);
    BST_insert_node(&bstRoot, 42);
    BST_insert_node(&bstRoot, 65);
    BST_insert_node(&bstRoot, 63);
    BST_insert_node(&bstRoot, 70);
    BST_insert_node(&bstRoot, 62);
    BST_insert_node(&bstRoot, 64);
    printf("Preorder: ");
    preorder_traversal(bstRoot, ShowIntData);
    printf("\n");
    printf("Inorder: ");
    inorder_traversal(bstRoot, ShowIntData);
    printf("\n");
    printf("Postorder: ");
    postorder_traversal(bstRoot, ShowIntData);
    printf("\n");

    return 0;
}

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData getData(BTreeNode* bt)
{
    return bt->data;
}

void setData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL) {
        free(main->left);
    }
    main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->right != NULL) {
        free(main->right);
    }
    main->right = sub;
}

void inorder_traversal(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL) {
        return;
    }
    inorder_traversal(bt->left, action);
    printf("%d ", bt->data);
    inorder_traversal(bt->right, action);
}

void preorder_traversal(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL) {
        return;
    }
    printf("%d ", bt->data);
    preorder_traversal(bt->left, action);
    preorder_traversal(bt->right, action);
}

void postorder_traversal(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL) {
        return;
    }
    postorder_traversal(bt->left, action);
    postorder_traversal(bt->right, action);
    printf("%d ", bt->data);
}

void createBST(BTreeNode** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
    return getData(bst);
}

void BST_insert_node(BTreeNode** pRoot, BSTData data)
{
    BTreeNode* pNode = NULL;
    BTreeNode* cNode = *pRoot;
    BTreeNode* newNode = NULL;

    while (cNode != NULL) {
        if (data == getData(cNode)) {
            return;
        }

        pNode = cNode;

        if (getData(cNode) > data) {
            cNode = GetLeftSubTree(cNode);
        }
        else {
            cNode = GetRightSubTree(cNode);
        }
    }

    newNode = MakeBTreeNode();
    setData(newNode, data);

    if (pNode != NULL) {
        if (getData(pNode) > data) {
            MakeLeftSubTree(pNode, newNode);
        }
        else {
            MakeRightSubTree(pNode, newNode);
        }
    }
    else {
        *pRoot = newNode;
    }
}

void ShowIntData(int data)
{
    printf("%d ", data);
}
