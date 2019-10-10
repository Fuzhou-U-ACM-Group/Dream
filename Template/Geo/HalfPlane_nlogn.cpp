struct P {
	int quad() const { return sign(y) > 0 || (sign(y) == 0 && sign(x) >= 0); }
};
struct L {
	// ax + by + c >= 0, (a != 0 || b != 0)
	L(db a, db b, db c) { 
		if(sign(a)==0) {
			this->a=P(0,-c/b);this->b=P(sign(b),-c/b);
		} else if(sign(b)==0) {
			this->a=P(-c/a,0);this->b=P(-c/a,-sign(a));
		} else {
			if(sign(c)!=0) {
				int x=sign(c)*sign(det(P(-c/a,0), P(0,-c/b)));
				if(x==1) this->a=P(-c/a,0),this->b=P(0,-c/b);
				else this->a=P(0,-c/b),this->b=P(-c/a,0);
			} else {
				this->a=P(0,0);this->b=P(sign(b),sign(b)*(-a/b));
			}
		}
	}
	bool includer(const P &p) const { return sign(det(b - a, p - a)) > 0; }
	bool include(const P &p) const { return sign(det(b - a, p - a)) >= 0; }
	// 向内（右手方向）推
	L push(db len) {
		P det = (b - a).rot90().norm() * len;
		return L(a + det, b + det);
	}
};
bool sameDir(L l0, L l1) {
	P a = l0.a - l0.b, b = l1.a - l1.b;
	return sign(det(a, b)) == 0 && sign(dot(a, b)) == 1;
}
bool operator < (const P &a,  const P &b) {
	if(a.quad() != b.quad()) return a.quad() < b.quad();
	return sign(det(a, b)) > 0;
}
bool operator < (const L &l0, const L &l1) {
	if(sameDir(l0, l1)) return l1.includer(l0.a);
	return (l0.b - l0.a) < (l1.b - l1.a);
}
bool check(L u, L v, L w) { return w.include(isLL(u, v)); }
deque<L> halfPlane(vector<L> l) {
	sort(all(l)); deque<L> q;
	rep(i, 0, sz(l)) {
		if(i && sameDir(l[i], l[i - 1])) continue;
		while(sz(q) > 1 && !check(q[sz(q) - 2], q.back(), l[i])) q.pop_back();
		while(sz(q) > 1 && !check(q[1], q[0], l[i])) q.pop_front();
		q.pb(l[i]);
	}
	while(sz(q) > 2 && !check(q[sz(q) - 2], q.back(), q[0])) q.pop_back();
	while(sz(q) > 2 && !check(q[1], q[0], q.back())) q.pop_front();
	return q;
}