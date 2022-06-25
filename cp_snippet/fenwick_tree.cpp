vector<int> tree;

void upd(int ind, int x) {
	for (; ind<tree.size(); ind+=(ind&-ind)) {
		tree[ind]+=x;
	}
}

int fensum(int ind) {
	int ret=0;
	for (; ind>0; ind&=ind-1) {
		ret+=tree[ind];
	}
	return ret;
}

int segsum(int sta, int end) {
	return fensum(end)-fensum(sta-1);
}
