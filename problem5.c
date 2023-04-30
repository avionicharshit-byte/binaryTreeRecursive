#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int sum(struct node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return node->data + sum(node->left) + sum(node->right);
    }
}

void printTreesUtil(int arr[], int start, int end) {
    if (start > end) {
        printf("NULL ");
        return;
    }

    for (int i = start; i <= end; i++) {
        struct node* root = newNode(arr[i]);

        int leftSum = 0;
        for (int j = start; j < i; j++) {
            leftSum += arr[j];
        }

        int rightSum = 0;
        for (int j = i + 1; j <= end; j++) {
            rightSum += arr[j];
        }

        if (rightSum > leftSum) {
            printf("( ");
            printTreesUtil(arr, start, i - 1);
            printf("%d ", root->data);
            printTreesUtil(arr, i + 1, end);
            printf(") ");
        }

        free(root);
    }
}

void printTrees(int arr[], int n) {
    printTreesUtil(arr, 0, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTrees(arr, n);
    return 0;
}
