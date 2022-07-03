#include<bits/stdc++.h>
using namespace std;
class Huffman{
	public:
	char data;
	int freq;
	Huffman* left;	
	Huffman* right;
	Huffman(char d,int f){
		data=d;
		freq=f;
		left=right=NULL;
	}
};
class compare{
	public:
	bool operator()(Huffman* a,Huffman* b){
		return a->freq>b->freq;
	}
};
Huffman* generateTree(priority_queue<Huffman*,vector<Huffman*>,compare> pq){
	while(pq.size()!=1){
		Huffman* left=pq.top();
		pq.pop();
		Huffman* right=pq.top();
		pq.pop();
		Huffman* node=new Huffman('$',left->freq+right->freq);
		node->left=left;
		node->right=right;
		pq.push(node);
	}
	return pq.top();
}
void print(Huffman* root,int arr[],int top){
	if(root->left){
		arr[top]=0;
		print(root->left,arr,top+1);
	}
	if(root->right){
		arr[top]=1;
		print(root->right,arr,top+1);
	}
	if(!root->left&&!root->right){
		cout<<root->data<<" ";
		for(int i=0;i<top;i++){
			cout<<arr[i];
		}
		cout<<"\n";
	}
}
void Huff(char data[],int freq[],int n){
	priority_queue<Huffman*,vector<Huffman*>,compare> pq;
	for(int i=0;i<n;i++){
		Huffman* node=new Huffman(data[i],freq[i]);
		pq.push(node);
	}
	Huffman* root=generateTree(pq);
	int arr[100],top=0;
	print(root,arr,top);
}
int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
 
    Huff(data, freq, size);
    return 0;
}