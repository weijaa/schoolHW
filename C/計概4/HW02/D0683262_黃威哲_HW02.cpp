#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int num;
	struct tree *right;
	struct tree *lift;
	struct tree *next;
}tree;

void preorderTraversal(tree *root){//«e¦° 
	if(root != NULL){
 		printf("%d ",root->num);
 		preorderTraversal(root->lift);
 		preorderTraversal(root->right);
 	}
 }
void inorderTraversal(tree *root){//ÄÁºü 
	if(root != NULL){
 		inorderTraversal(root->lift);
 		printf("%d ",root->num);
 		inorderTraversal(root->right);
 	}
}
void postorderTraversal(tree *root){//«áÄò 
	if(root != NULL){
 		postorderTraversal(root->lift);
 		postorderTraversal(root->right);
 		printf("%d ",root->num);
 	}
}
/*int level(tree *root)
{
    if (root==NULL)
        return 0;
    else
    {
        int llevel = levevl(node->lift);
        int rlevel = level(node->right);
 
        if (llevel > rlevel)
            return(llevel+1);
        else return(rlevel+1);
    }*
}*/
 
void levelorderTraversal(tree *root){
	tree *head,*current,*level;
	head = root;
	current = head;
	level = head;
	while(1){
		if(level->lift != NULL){
			current->next = level->lift;
			current = current->next;
		}
		if(level->right != NULL){
			current->next = level->right;
			current =current->next;
		}
		level = level->next;
		if(level == NULL){
			break;
		}
	}
	current = head;
	while(current != NULL){
		printf("%d ",current->num);
		current = current->next;
	}
}

tree* newNode(int num){
	tree *x;
	x= (tree*)malloc(sizeof(tree));
	x->num = num;
	x->lift = NULL;
	x->right = NULL;
	x->next = NULL;
	return x;
}
int main(){
	tree *root=NULL,*current;
	int num,fru;
	while(1){
		scanf("%d",&num);
		if(num == 0){
			break;
		}
		else{
			if(root == NULL){
				root = newNode(num);
			}
			else{
				current = root;
				while(1){
					if(num < current->num){
						if(current->lift == NULL){
							current->lift = newNode(num);
							break;
						}
						else{
							current = current->lift;
						} 
					}
					else{
						if(current->right == NULL){
							current->right = newNode(num);
							break;
						}
						else{
							current = current->right;
						}
					}
				}
			}
		}
	}
	while(1){
		scanf("%d",&fru);
		if(fru==0){
			break;
		}
		else{
			current = root;
			while(current != NULL){
				if(current->num == fru){
					printf("Y\n");
					break;
				}
				else if (current->num > fru){
					if(current->lift == NULL){
						printf("N\n");
					}
					current = current->lift;
				}
				else if(current->num < fru){
					if(current->right == NULL){
						printf("N\n");
					}
					current = current->right;
				}	
			}
		}
	}
	preorderTraversal(root);
	printf("\n");
	inorderTraversal(root);
	printf("\n");
	postorderTraversal(root);
	printf("\n");
	levelorderTraversal(root);
	printf("\n");
	return 0;
}

