#include <bits/stdc++.h>

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

std::string s;

int main() {
	std::cin >> s;

	std::string s2 = s + "00"; std::string s4 = s + "0000"; 
	int n = s.size();
	reverse(s.begin(), s.end());
	reverse(s.begin(), s2.end());
	reverse(s.begin(), s4.end());
	int d = 0;
	for (int i = 0; i < n; i ++) {
		s2[i] = ((s2[i] - '0') + d) % 2;
		
		d = ((s[i] - '0') + (s2[i] - '0')) / 2;
		s2[i] = (((s[i] - '0') + (s2[i] - '0')) % 2) + '0'; 
	}
}