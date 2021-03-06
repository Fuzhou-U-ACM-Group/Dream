/*
 * 建出圆方树，选任意圆点作为根，环的根指的是环上深度最小的点。
 * 圆圆边边权不变，圆方边边权是圆点到它所在环的根的最短距离。
 * 如果询问两点的 lca 是圆点， ans = dep[a] + dep[b] - dep[lca] 
 * 如果是方点， ans = dep[a] + dep[b] - dep[A] - dep[B] + dis(A, B) 
 */ 
