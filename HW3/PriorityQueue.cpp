#include <math.h>
#include "PriorityQueue.hpp"

template <class DATA> NodeBQ<DATA> *
	PriorityQueue<DATA> :: join ( NodeBQ<DATA> * p , NodeBQ<DATA> * q ){
	
	NodeBQ<DATA> * temp;
	if(p->priority < q->priority){
		temp = q->left;
		q->left = p;
		p->right = temp;
		return q;
	} else{
		temp = p->left;
		p->left = q;
		q-> right = temp;
		return p;
	}
	
}	
template <class DATA>  void PriorityQueue<DATA>:: 
merge(vector<NodeBQ<DATA> *> &  a, vector<NodeBQ<DATA> *> & b,int max){
	NodeBQ<DATA> * carry = NULL;
	
	/*
	int max = ( ((log(a->count)/log(2)) > ( log(b->count) / log(2)) ) ? 
		(log(a->count)/log(2)) : (log(b->count)/log(2)) );
	*/

	for(int i =0; i < max ; i++){
		switch(1*(a[i]!=NULL) + 2*(b[i] != NULL) + 4*(carry!=NULL)) {
		case 2: a[i] = b[i]; 
				break;
		case 3: carry = join (a[i],b[i]);
				a[i]=NULL; 
				break;
		case 4: a[i]=carry;
				carry=NULL; 
				break;
		case 5: carry = join(a[i],carry);
				a[i]=NULL;
				break;
		case 6: carry = join(b[i], carry);
				break;
		case 7: NodeBQ<DATA> * temp = join (b[i],a[i]);
				a[i]=carry;
				carry=temp;
		}
	}

}

template <class DATA> bool  PriorityQueue<DATA>::fetchPQ ( DATA & data ) {
	
	NodeBQ<DATA> * temp;
	vector< NodeBQ<DATA> * > b;
	int i, imax;
	double max = -1;
	if(count==0) return false;
	//a = this->roots;
	for(i = 0 ; i < (int)this->roots.size();i++)
		if(this->roots[i]!=NULL && this->roots[i]->priority>max)
			max = roots[imax=i]->priority;
	if(imax>0){
		b =  vector< NodeBQ<DATA> * >(imax+1);
		b[imax] = NULL;
		temp = this->roots[imax]->left;
		for(i = imax-1;i>=0;i--){
			b[i]=temp;
			temp=temp->right;
			b[i]->right=NULL;

		}
	}
	data= this->roots[imax]->element;
	//free(this->roots[imax]->element);
	//free(this->roots[imax]);
	this->roots[imax]=NULL;
	if(imax>0){
		merge(this-> roots, b, (imax < roots.size()) ? (imax+1):roots.size());
		//free(b);
	}
	count--;	
	
}

template <class DATA> bool  PriorityQueue<DATA>:: insertPQ ( DATA & data , double priority ) {
	if(count>=(pow (double(2), (double)roots.size())-1))
		roots.resize(roots.size()+1);
	NodeBQ<DATA> * carry = new NodeBQ<DATA>(data,priority);
	for(int i = 0; i<roots.size();i++){
		if(this->roots[i]==NULL){
			this->roots[i]= carry;
			break;
		}
		carry = join( carry, roots[i]);
		roots[i]=NULL;
	}
	count ++;
	return true;
	
}

template <class DATA> bool  PriorityQueue<DATA>:: getDataPQ ( unsigned index , DATA & data ) {
	if(this->roots[index]==NULL)
		return false;
	else{
		data = this->roots[index]->element;
	}
	return true;

}

template <class DATA> void  PriorityQueue<DATA>::
printPQ ( ostream & out ) const {
	if(count ==0) return;
	for(int i = 0; i < roots.size(); i++){
		cout<< i << ": ";
		if(roots[i]!=NULL){
			cout <<roots[i]->element<<endl;
			if(roots[i]->left!=NULL)
				printNode(roots[i]->left);
		}
		else
			cout << endl;
	}
	
}

template<class DATA>  void PriorityQueue<DATA>::printNode(NodeBQ<DATA> * a)  const {
	cout << "   "<<  a->element<<endl;
	if(a-> left!=NULL)
		printNode(a->left);
	if(a->right!=NULL)
		printNode(a->right);
	return;
}