Út visszafejtése
stack<pair<int,int>> st;
    st.push(make_pair(maxi,maxj));
    vector<int> route;
    route.reserve(n);
    route.push_back(maxi);
    while(!st.empty()){
		auto p=st.top(); st.pop();
		int i=p.first;
		int j=p.second;
		int k=pi[i][j];
		if(k==0){
			route.push_back(j);
			continue;
		}
		st.push(make_pair(k,j));
		st.push(make_pair(i,k));
    }

	vagy

	P[i][j]=i-ból j-be első csúcs (i után)
	P[i][j]=ha (i->j) -> j