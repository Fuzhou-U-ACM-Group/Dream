// O(n) 分解为字典序非严格降的 lyndon word 分解唯一
vector<int> duval(char s[]){
  vector<int> ret;
  int n = strlen(s) + 1; // zero used here
  int start = 0, mid = 1, cur = 0;
  ret.push_back(0);
  for (int i = 0; i < n; ++i){
    if (s[i] == s[cur]){
      if (++cur == mid) cur = start;
    } else if (s[i] > s[cur]){
      mid = i + 1;
      cur = start;
    } else if (s[i] < s[cur]){
      int temp = mid - start;
      while (start + temp <= i){
        start += temp;
        ret.push_back(start);
      }
      i = cur = start;
      mid = start + 1;
    }
  }
  return ret;
}

/*
cbaabc
0 1 2 6
*/

// 生成字符集为 m , 长度不超过 n 的所有 lyndon word ，字符集从 a 开始
void lyndon_generate(int n, int m) {
  char z = 'a' + m - 1, s[1000];
  s[0] = 'a' - 1;
  for (int i = 1, x = 1; ; ++i) {
    s[x - 1]++; s[x] = 0;
    puts(s);
    if (strlen(s)==1 && s[0]=='a'+m-1) return; 
    for (int j = x; j < n; ++j) s[j] = s[j - x];
    for (x = n; s[x - 1] == z; --x);
  }
}

/*
3 2
a
aab
ab
abb
b
*/
