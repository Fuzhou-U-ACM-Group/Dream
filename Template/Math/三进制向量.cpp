struct vec3{
	static const int N = ::N;
	bitset<N> a[3];
	vec3() { a[0].set(); a[1].reset(); a[2].reset(); }
	inline void ini() { a[0].set(); a[1].reset(); a[2].reset(); }
	inline void set(int p, int x) { x = (x % 3 + 3) % 3; rep(i, 0, 3) if (i == x) a[i].set(p); else a[i].reset(p); }
 	inline int operator [] (int x) { rep(i, 0, 3) if (a[i][x]) return i; }
	int getval() { return (a[1].count() + a[2].count() * 2) % 3; }
	inline vec3 operator * (const vec3 &c) const {
		vec3 r;
		r.a[0] = a[0] | c.a[0];
		r.a[1] = (a[1] & c.a[1]) | (a[2] & c.a[2]);
		r.a[2].set(); r.a[2] ^= r.a[0] ^ r.a[1];
		return r;
	}
	inline vec3 operator + (const vec3 &c) const {
		vec3 r;
		r.a[1] = (a[0] & c.a[1]) | (a[1] & c.a[0]) | (a[2] & c.a[2]);
		r.a[2] = (a[0] & c.a[2]) | (a[2] & c.a[0]) | (a[1] & c.a[1]);
		r.a[0] ^= r.a[1] ^ r.a[2];
		return r;
	}
	inline vec3 operator - (const vec3 &c) const {
		return (*this) + (c * -1);
	}
	inline vec3 operator * (int x) const {
		vec3 r = *this;
		x = (x % 3 + 3) % 3;
		if (x == 0) { r.ini(); }
		if (x == 2) { swap(r.a[1], r.a[2]); }
		return r;
	}
	inline vec3 operator + (int x) const{
		vec3 r = *this;
		x = (x % 3 + 3) % 3;
		if (x == 1) { swap(r.a[0], r.a[2]); swap(r.a[1], r.a[2]); }
		if (x == 2) { swap(r.a[0], r.a[2]); swap(r.a[0], r.a[1]); }
		return r;
	}
};