template <class DATA> Table<DATA> :: Table ( unsigned size ) 
{
		currentSize=0;
		tableSize=size;
		sProbes = 0;
		pbCount = 0;
		passbit.resize(size);
		full.resize(size);
		bucket.resize(size);
		//cout << "size = " << size << endl;
		//cout << "passbit size = " << passbit.capacity() << endl;
}

template <class DATA> void Table<DATA>::empty()
	{
		//cout<<"emptying..."<<endl;
		currentSize=0;
		sProbes=0;
		pbCount=0;
		passbit.clear();
		full.clear();
		bucket.clear();
		passbit.resize(tableSize);
		full.resize(tableSize);
		bucket.resize(tableSize);
		//cout<<"bucket is empty="<<bucket.empty()<<endl;
	}

template<class DATA> bool Table<DATA>::insert ( DATA & data )
	{
		
		//check table is not full
		if (currentSize==tableSize){
			cout<<"tableisfull"<<endl;	
			return false;
		}

		unsigned int hash = (unsigned) data;
		//cout << hash << endl;
		int start;
		int step = hash %(tableSize-2)+1;
		start = hash % tableSize;
		int probe=start; //count double hashing insert location
		int doubleH = start; //double hashing insert 
		//check bucket is not full
		int cost;
		int cost2;
		int locationNew;
		int doubleCost=1;
		while(full[doubleH])
		{
			if(bucket[doubleH]==data) //check data already in table
				return false;

			doubleCost++;
			doubleH-=step;
			if(doubleH < 0)
				doubleH+=tableSize;
		}

		//cout<<"doublehashingcost=" <<doubleCost<<endl;
		int lowestCost=0;
		int lowestCostIndex=0;
		int hash2,start2,step2;
		int startbucket;
		int probeFinal;
		lowestCost = doubleCost;

		for(int i =0;i<doubleCost-1;i++)
		{	
			probe=start;
			//cout<<"i="<<i<<endl;
			for(int j = 0; j<i ; j++){
				//cout<<"move #"<<j;
				probe-=step;
				if(probe<0) probe+=tableSize;
			}
			probeFinal=probe;
			//cout<<endl<<"at probe = "<<probe<<endl;
			
			int costToMove=1+i;
			//find empty bucket for collision
			hash2 =(int)bucket[probe];
			step2 =	hash2 %(tableSize-2)+1;
			while(full[probe]){
				probe-=step2;
				if(probe<0) probe+=tableSize;
				costToMove++;
			}
			//cout<<"moved collision to: "<<probe<<endl;
			//done finding cost
			//cout<<"cost to move = "<<costToMove<<endl;
			
			if(costToMove<doubleCost)
				if(costToMove<lowestCost)
				{
				
				lowestCost = costToMove;
				lowestCostIndex = probeFinal;
				//cout<<"lowestCost:"<<lowestCost<<" and lowestCostIndex:"<<lowestCostIndex<<endl;
				}
			
		}
		//cout<<"lowestCost:"<<lowestCost<<" and lowestCostIndex:"<<lowestCostIndex<<endl;

		//time to insert if brent cost is less that double cost
		if(lowestCost<doubleCost)
		{
			doubleH=start;
			//doublehash insert at location lowestCostindex
			//set passbits for double hashing
			while(doubleH!=lowestCostIndex)
			{	if(!passbit[doubleH]){
				passbit[doubleH]=true;
				pbCount++;
				}
				doubleH-=step;
				if(doubleH < 0)
					doubleH+=tableSize;
			}
			//move the colliding item
			hash2 =(int)bucket[lowestCostIndex];
			step2 =	hash2 %(tableSize-2)+1;
			probe=doubleH;//find out where to insert collision
			while(full[probe])
			{	if(!passbit[probe]){
				passbit[probe]=true;
				pbCount++;
				}
				probe-=step2;
				if(probe<0)
					probe+=tableSize;
			}
			//store collision insert at its next free probe
			bucket[probe]=bucket[lowestCostIndex];
			full[probe]=true;
			//cout<<"full["<<probe<<"] = true"<<endl;
			//insert data into the lowestcostindex
			bucket[lowestCostIndex]=data;
			sProbes+=lowestCost;
			currentSize++;
			//cout<<"brent inserting:"<< (int)data<<" at:";
			//cout<<probe<<endl;
			return true;
		}



		
		else{
			doubleH = start;
			while(full[doubleH])
			{
				if(!passbit[doubleH]){
				passbit[doubleH]=true;
				pbCount++;
				}
				doubleH-=step;
				if(doubleH < 0)
					doubleH+=tableSize;
			}
		}
		//cout<<"double hash inserting:"<< (int)data<<" at:";
		//cout<<doubleH<<endl;
//cout<<"full["<<probe<<"] = true"<<endl;
		bucket[doubleH]=data;
		full[doubleH]=true;
		currentSize++;
		sProbes+=doubleCost;
		return true;
		
	}


template<class DATA> bool Table<DATA>:: insertD ( DATA & data )
	{
		//return false;
		//check table is not full
		if (currentSize==tableSize){
			//cout<<"tableisfull"<<endl;	
			return false;
		}
		unsigned int hash = unsigned (data);
		//cout << hash << endl;
		int start;
		int step = hash %(tableSize-2)+1;
		//cout <<"step is=" << step<<endl;
		start = hash % tableSize;

		//check bucket is not full
		while(full[start])
		{
			if(bucket[start]==data){
				//cout << "duplicate data" << endl;
				return false;}
			//cout << "bucket" << start <<" is full"<<endl;
			if(!passbit[start])
			{	passbit[start]=true;
				pbCount++;}
			//move to next bucket in double hashing
			start = (start-step);
			//cout << "new bucket = " << start<<endl;
			if(start < 0)
				start = tableSize+start;
			//cout << "new bucket corrected = " << start<<endl;
			sProbes++;
		}
		
		
		bucket[start]=data;
		full[start]=true;
		sProbes++;
		currentSize++;
		//cout << "double insert at " << start<<endl;
		return true;
	}

template<class DATA> bool Table<DATA>::fetch ( DATA & data ) const
	{	//cout<<"fetching"<<endl;
		if(tableSize==0)return false;

		unsigned int start = (unsigned )data;
		int step =start %(tableSize-2)+1;
		start = start % tableSize;
		//cout<<"recrd"<<data<<":start="<<start<<endl;
		if(!full[start]){
			//cout<<"initial bucket empty"<<endl;
			return false;
		}
		while(bucket[start]!=data)
		{
			if(!passbit[start]){
				//cout<<"passbit is false.. exiting"<<endl;
				return false;
			}
			start = start -step;
			if(start<0)
				start = tableSize-start;
		}
		//cout<<"found at:"<<start<<endl;
		data = bucket[start];
		return true;
	}
	/*
	 * The getData method obtains data regarding a particular table bucket.
	 * If bucket i is not empty, then the parameter data is set to the
	 *  DATA value present and passbit is set to the passbit value of
	 *   the bucket. Finally true is returned. If bucket
	 *   i is empty, no parameters are set and false is returned.
	 */
template<class DATA> bool Table<DATA>::getData ( unsigned i , DATA & data , bool & passbitB ) const
	{
		if(full[i])
		{
			data 	= bucket[i];
			passbitB	= passbit[i];
			return true;
	
		}
		else return false;
	}
template <class DATA> Perform Table<DATA>::perform ( ) const
	{	//cout << "perform"<<endl;
		//cout<<"sprobes="<<sProbes<<"    currentSize="<<currentSize<<"  pbcount="<<pbCount<<endl;
		Perform perform;
		perform.successful= (double)sProbes/(double)currentSize;
		perform.unsuccessful[0]=1/(1-((double)pbCount/(double)tableSize));
		
		int count=0;
		int cbucket;
		for(int start =0;start<tableSize;start++) //iterate buckets
		{
			cbucket = start;
			for(int step=1;step<=tableSize-2;step++)
			{
				cbucket = start;
				//cout<<"cbucket ="<<cbucket<<endl;
				count++;
				while(passbit[cbucket])
				{
					count++;
					cbucket = cbucket - step;
					if(cbucket<0){
						cbucket = tableSize+cbucket;
						//cout<<"reached false PB"<<endl;
					}
					
				}
			}
		
		}

		perform.unsuccessful[1]=(double)count/(tableSize*(tableSize-2));
		return perform;
	}


