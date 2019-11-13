pair<int*, int> sta[N * 5]; int top;

void add(int &a) { sta[++top] = mp(&a, a); }
void dfs(int u) {
	int ttop = top;

	add(var); modify var;

	// .. dfs

	while(top > ttop) *sta[top].fi = sta[top].se, --top;
}
