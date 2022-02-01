#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData getData(BTreeNode* bt);
void setData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void(*VisitFuncPtr)(BTData data);

void preorder_traversal(BTreeNode* bt, VisitFuncPtr action);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef BTData BSTData;

void createBST(BTreeNode** pRoot);
BSTData BSTGetNodeData(BTreeNode* bst);
BTreeNode* BST_insert_node(BTreeNode** pRoot, BSTData data);
BTreeNode* BST_delete_node(BTreeNode** pRoot, BSTData target);

BTreeNode* RotateLL(BTreeNode* bst);
BTreeNode* RotateRR(BTreeNode* bst);
BTreeNode* RotateLR(BTreeNode* bst);
BTreeNode* RotateRL(BTreeNode* bst);
int getHeight(BTreeNode* bst);
int getHeightDiff(BTreeNode* bst);
BTreeNode* Rebalance(BTreeNode** pRoot);

void get_right_child(BTreeNode* bst, BSTData target);
void get_left_child(BTreeNode* bst, BSTData target);
void balance_factor(BTreeNode* bst, BSTData target);
void ShowIntData(int data);
void printBST(BTreeNode* bst);

int main()
{
    BTreeNode* avlRoot;

    createBST(&avlRoot);

    //1000개의 data avltree에 대입하기
    /*srand(time(NULL));

    for (int i = 0; i < MAXN; i++) {
        BST_insert_node(&avlRoot, rand() % 10000);
    }*/

    BST_insert_node(&avlRoot, 5);
    BST_insert_node(&avlRoot, 3);
    BST_insert_node(&avlRoot, 10);
    BST_insert_node(&avlRoot, 2);
    BST_insert_node(&avlRoot, 4);
    BST_insert_node(&avlRoot, 7);
    BST_insert_node(&avlRoot, 11);
    BST_insert_node(&avlRoot, 1);
    BST_insert_node(&avlRoot, 6);
    BST_insert_node(&avlRoot, 9);
    BST_insert_node(&avlRoot, 12);
    BST_insert_node(&avlRoot, 8);

    BST_delete_node(&avlRoot, 10);
    Rebalance(&(avlRoot->right));

    printf("왼쪽 subtree를 활용한 결과\n");
    preorder_traversal(avlRoot, ShowIntData);

    /*printf("오른쪽 subtree를 활용한 결과\n");
    preorder_traversal(avlRoot, ShowIntData);*/

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

void preorder_traversal(BTreeNode* bt, VisitFuncPtr action)
{
    if (bt == NULL) {
        return;
    }
    printf("%d ", bt->data);
    preorder_traversal(bt->left, action);
    preorder_traversal(bt->right, action);
}

BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
    BTreeNode* delNode = (BTreeNode*)malloc(sizeof(BTreeNode));

    if (bt != NULL) {
        delNode = bt->left;
        bt->left = NULL;
    }
    return delNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
    BTreeNode* delNode = (BTreeNode*)malloc(sizeof(BTreeNode));

    if (bt != NULL) {
        delNode = bt->right;
        bt->right = NULL;
    }
    return delNode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    main->right = sub;
}

void createBST(BTreeNode** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
    return getData(bst);
}

BTreeNode* BST_insert_node(BTreeNode** pRoot, BSTData data)
{
    if (*pRoot == NULL) {
        *pRoot = MakeBTreeNode();
        setData(*pRoot, data);
    }

    else if (getData(*pRoot) > data) {
        BST_insert_node(&((*pRoot)->left), data);
        *pRoot = Rebalance(pRoot);
    }

    else if (getData(*pRoot) < data) {
        BST_insert_node(&((*pRoot)->right), data);
        *pRoot = Rebalance(pRoot);
    }

    else {
        return NULL;
    }

    return *pRoot;

}

BTreeNode* BST_delete_node(BTreeNode** pRoot, BSTData target)
{
    BTreeNode* pvRoot = MakeBTreeNode();
    BTreeNode* pNode = pvRoot;
    BTreeNode* cNode = *pRoot;
    BTreeNode* dNode;

    ChangeRightSubTree(pvRoot, *pRoot);

    while (cNode != NULL && getData(cNode) != target) {
        pNode = cNode;

        if (getData(cNode) > target) {
            cNode = GetLeftSubTree(cNode);
        }
        else {
            cNode = GetRightSubTree(cNode);
        }
    }

    if (cNode == NULL) {
        printf("target data not exist\n");
        return NULL;
    }
    dNode = cNode;

    if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
        if (GetLeftSubTree(pNode) == dNode) {
            RemoveLeftSubTree(pNode);
        }
        else {
            RemoveRightSubTree(pNode);
        }
    }

    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
        BTreeNode* dcNode;

        if (GetLeftSubTree(dNode) != NULL) {
            dcNode = GetLeftSubTree(dNode);
        }
        else {
            dcNode = GetRightSubTree(dNode);
        }
        if (GetLeftSubTree(pNode) == dNode) {
            ChangeLeftSubTree(pNode, dcNode);
        }
        else {
            ChangeRightSubTree(pNode, dcNode);
        }
    }

    //오른쪽 subtree를 이용하는 경우
    /*else {
        BTreeNode* mNode = GetRightSubTree(dNode);
        BTreeNode* mpNode = dNode;
        int delData;

        while (GetLeftSubTree(mNode) != NULL) {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        delData = getData(dNode);
        setData(dNode, getData(mNode));

        if (GetLeftSubTree(mpNode) == mNode) {
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        }
        else {
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        }
        dNode = mNode;
        setData(dNode, delData);
    }*/

    //왼쪽 subtree를 이용하는 경우
    else {
        BTreeNode* mNode = GetLeftSubTree(dNode);
        BTreeNode* mpNode = dNode;
        int delData;

        while (GetRightSubTree(mNode) != NULL) {
            mpNode = mNode;
            mNode = GetRightSubTree(mNode);
        }
        delData = getData(dNode);
        setData(dNode, getData(mNode));

        if (GetRightSubTree(mpNode) == mNode) {
            ChangeRightSubTree(mpNode, GetLeftSubTree(mNode));
        }
        else {
            ChangeLeftSubTree(mpNode, GetLeftSubTree(mNode));
        }
        dNode = mNode;
        setData(dNode, delData);
    }

    if (GetRightSubTree(pvRoot) != *pRoot) {
        *pRoot = GetRightSubTree(pvRoot);
    }
    free(pvRoot);
    Rebalance(pRoot);
    return dNode;
}

BTreeNode* RotateLL(BTreeNode* bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}

BTreeNode* RotateRR(BTreeNode* bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
    int hDiff = getHeightDiff(*pRoot);

    if (hDiff > 1) {
        if (getHeightDiff(GetLeftSubTree(*pRoot)) > 0) {
            *pRoot = RotateLL(*pRoot);
        }
        else {
            *pRoot = RotateLR(*pRoot);
        }
    }

    if (hDiff < -1) {
        if (getHeightDiff(GetRightSubTree(*pRoot)) < 0) {
            *pRoot = RotateRR(*pRoot);
        }
        else {
            *pRoot = RotateRL(*pRoot);
        }
    }

    return *pRoot;
}


void ShowIntData(int data)
{
    printf("%d ", data);
}

int getHeight(BTreeNode* bst)
{
    int leftH, rightH;
    if (bst == NULL) {
        return 0;
    }

    leftH = getHeight(GetLeftSubTree(bst));
    rightH = getHeight(GetRightSubTree(bst));

    if (leftH > rightH) {
        return leftH + 1;
    }
    else {
        return rightH + 1;
    }
}

int getHeightDiff(BTreeNode* bst)
{
    int lsh, rsh;

    if (bst == NULL) {
        return 0;
    }
    lsh = getHeight(GetLeftSubTree(bst));
    rsh = getHeight(GetRightSubTree(bst));

    return lsh - rsh;
}

void balance_factor(BTreeNode* bst, BSTData target)
{
    if (getData(bst) == target) {
        printf("%d\n", getHeightDiff(bst));
    }
    else if (getData(bst) > target) {
        balance_factor(bst->left, target);
    }
    else {
        balance_factor(bst->right, target);
    }
    return;
}

void get_right_child(BTreeNode* bst, BSTData target)
{
    BTreeNode* cNode = bst;
    BSTData curData;
    int flag = 0;

    while (cNode != NULL) {
        curData = getData(cNode);

        if (target == curData) {
            flag = 1;
            break;
        }
        else if (target < curData) {
            cNode = GetLeftSubTree(cNode);
        }
        else {
            cNode = GetRightSubTree(cNode);
        }
    }

    if (flag) {
        printf("%d\n", getData(GetRightSubTree(cNode)));
    }

    else {
        printf("NULL\n");
    }
}
void get_left_child(BTreeNode* bst, BSTData target)
{
    BTreeNode* cNode = bst;
    BSTData curData;
    int flag = 0;

    while (cNode != NULL) {
        curData = getData(cNode);

        if (target == curData) {
            flag = 1;
            break;
        }
        else if (target < curData) {
            cNode = GetLeftSubTree(cNode);
        }
        else {
            cNode = GetRightSubTree(cNode);
        }
    }

    if (flag) {
        printf("%d\n", getData(GetLeftSubTree(cNode)));
    }

    else {
        printf("NULL\n");
    }
}




