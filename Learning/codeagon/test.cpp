map<int, vector<int>> posa, posb;
for (int i = 0; i < n; i++) {
	posa[a[i]].push_back(i);
}
for (int i = 0; i < n; i++) {
	posb[b[i]].push_back(i);
}
int ans = 0;
for (auto [val, one] : posa) {
	const auto& two = posb[val];
	assert(one.size() == two.size());
	for (int i = 0; i < (int)one.size(); i++)
		ans += abs(one[i] - two[i]);
}
return ans;
