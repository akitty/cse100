
/* * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 *	Disjoint Subsets union-find 	Winter 2011
 *
 *      Walt Burkhard
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */ 


DisjointSubsets :: DisjointSubsets ( unsigned numberElements ) {
	numberOfElements = numberElements;
	parent.resize(numberElements);
	rank.resize(numberElements);
	for(int i =0;i<numberElements;i++){
		parent[i]=i;
		rank[i]=1;
	}
}

unsigned DisjointSubsets:: findDS ( unsigned a ) {
	unsigned rootA=a;
	while(parent[rootA]!=rootA){
		rootA = parent[rootA];
	}
	parent[a]=rootA;
	return rootA;
}

bool DisjointSubsets:: unionDS (unsigned a, unsigned b){
	unsigned rootA=a, rootB=b;
	while(parent[rootA]!=rootA){//find root of a
		rootA=parent[rootA];
	}
	while(parent[rootB]!=rootB){//find root of b
		rootB=parent[rootB];
	}
	if(rank[rootA]<rank[rootB]){//if size of a's tree is less than b's
		//a points to b
		parent[rootA]=rootB;
		rank[rootB]+=rank[rootA];
	}
	else{
		parent[rootB]=rootA;
		rank[rootA]+=rank[rootB];
	}

}

