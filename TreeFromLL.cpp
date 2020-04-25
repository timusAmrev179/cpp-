// { Driver Code Starts

/*
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
 



Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains linked list elements.

Output:
Output of each test case will be the level order traversal of the the constructed binary tree.

User Task:
The task is to complete the function convert() which takes head of linked list and root of the tree as the reference. The driver code prints the level order.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= Ki <= 103

Example:
Input:
2
5
1 2 3 4 5
5
5 4 3 2 1
Output:
1 2 3 4 5
5 4 3 2 1

Explanation:
Testcase 1: Given tree is 
                            1
                         /      \
                       2        3
                    /      \
                  4        5
Now, the level order traversal of the above tree is 1 2 3 4 5.
Testcase 2: Given tree is  
                            5
                         /      \
                       4        3
                    /      \
                  2        1
Now, the level order traversal of the above tree is 5 4 3 2 1.


*/

#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1\n";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}
// } Driver Code Ends
/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

TreeNode* insert(vector<int>& list, int index){
	TreeNode* newNode = new TreeNode(list[index]); 
	return newNode;  
}

void convert(Node *head, TreeNode *&root) {
    	if(!head) return; 
	vector<int> list; 
	while(head){
		list.push_back(head->data); 
		head = head->next; 
	}

	queue<TreeNode*> q; 
	root = new TreeNode(list[0]); 
	q.push(root); 
	int i = 0;
/*
	for(int x: list)
		cout<<x<<" "; 
	cout<<endl; 
*/	
  
	while(!q.empty()){ 
		int count = q.size(); 
	
		while(count-- && i<list.size()){
			TreeNode* temp = q.front(); 
			q.pop(); 
			if(2*i+1 < list.size()){
				temp->left = insert(list, 2*i + 1);
				q.push(temp->left); 
				//cout<<list[2*i+1]<<" "; 
			} 
			if(2*i+2 < list.size()){
				temp->right = insert(list, 2*i + 2);
				q.push(temp->right); 
				//cout<<list[2*i+2]<<" ";
			}
			i++;  
			//cout<<endl; 	
		}

				
	}

	
}

