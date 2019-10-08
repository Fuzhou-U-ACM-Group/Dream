// time : O(n^3)
// id : 0 .. n-1
const int N = 1005;
vi g[N];
int m, u, v, n, match[N], q[N], L, R;
int pred[N], b[N], s, t, newb;
bool inq[N], inb[N], inp[N];

void push(int u) { q[R++] = u; inq[u] = 1;}

int pop() { return q[L++]; }

int LCA(int u,int v) {
	rep(i, 0, n) inp[i]=0;
	while(1) {
		u = b[u];
		inp[u] = 1;
		if (u == s) break;
		u = pred[match[u]];
	}
	while(1) {
		v = b[v];
		if (inp[v]) break;
		v = pred[match[v]];
	}
	return v;
}

void ResetTrace(int u) {
	int v;
	while(b[u] != newb) {
		v = match[u];
		inb[b[u]] = inb[b[v]] = 1;
		u = pred[v];
		if(b[u] != newb) pred[u] = v;
	}
}

void Blossom(int u,int v) {
	newb = LCA(u,v);
	rep(i, 0, n) inb[i] = 0;
	ResetTrace(u);
	ResetTrace(v);
	if(b[u] != newb) pred[u] = v;
	if(b[v] != newb) pred[v] = u;
	rep(i, 0, n) if (inb[b[i]]) {
		b[i] = newb;
		if (!inq[i]) push(i);
	}
}

bool Find(int u) {
	bool found = 0;
	rep(i, 0, n) pred[i] = -1, b[i] = i, inq[i] = 0;
	s = u, t=-1;
	L = R = 0;
	push(s);
	while(L < R) {
		int u = pop();
		per(i, 0, sz(g[u])) { 
			int v = g[u][i];
			if (b[u] != b[v] && match[u] != v)
				if(v == s || (match[v] >= 0 && pred[match[v]] >= 0))
					Blossom(u, v);
				else if(pred[v] == -1) {
					pred[v]=u;
					if (match[v] >= 0) push(match[v]);
					else return t = v, 1;
				}
		}
	}
	return found;
}
void AugmentPath() {
	int u = t, v, w;
	while(u >= 0) {
		v = pred[u];
		w = match[v];
		match[v] = u;
		match[u] = v;
		u = w;
	}
}

void Match() {
	rep(i, 0, n) match[i] = -1;
	// random_shuffle maybe faster 
	rep(i, 0, n) if (match[i] == -1) if (Find(i)) AugmentPath();
}

