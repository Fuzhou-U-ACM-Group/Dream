P fy(P o, db r, P p) { // 点反演
	db d = (o - p).len();
	db r0 = r * r / d;
	return (p - o) * r0 / d + o;
}
C fy1(P o, db r, C c) { // 不过反演中心的圆反演后还是圆
	P p1, p2; isCL(c, L(o, c.o), p1, p2);
	p1 = fy(o, r, p1);
	p2 = fy(o, r, p2);
	return C((p1 + p2) / 2, (p1 - p2).len() / 2);
}
L fy0(P o, db r, C c) { // 过反演中心的圆反演后是直线
	P p = c.o + c.o - o;
	P p1 = fy(o, r, p);
	P p2 = p1 + (o - p1).rot90();
	return L(p1, p2);
}
C fy(P o, db r, L l) { // 不过反演中心的直线反演后是圆
	P p = fy(o, r, proj(l, o));
	return C((p + o) / 2, (p - o).len() / 2);
}
