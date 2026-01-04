#include <bits/stdc++.h>

using namespace std;

struct trie {
private:
	trie* child[26];
	int end_count;

	bool contains(string& s, int index, bool as_prefix) {
		assert (index >= 0 and index < s.size());
		int letter_index = s[index] - 'a';
		if (child[letter_index] == nullptr) 
			return false;
		if (index + 1 == s.size())
			return (as_prefix ? true: end_count > 0);
		return child[letter_index] -> contains(s, index + 1, as_prefix);
	}

public:
	trie() {
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
		end_count = 0;
	}

	bool contains(string& s, bool as_prefix) {
		return contains(s, 0, as_prefix);
	}

	void add_string(string& s, int index) {
		assert (index >= 0 and index < s.size());
		int letter_index = s[index] - 'a';
		if (child[letter_index] == nullptr) 
			child[letter_index] = new trie;
		if (index + 1 != s.size())
			child[letter_index] -> add_string(s, index + 1);
		else
			end_count++;
	}

	void add_string(string s) {
		add_string(s, 0);
	}
};

int main() {
	trie t;

	string s1 = "abfcer";
	string s2 = "pfer";
	t.add_string(s1);
	t.add_string(s2);

	string s3 = "abf";
	cout << t.contains(s3, false) << '\n';
	cout << t.contains(s3, true) << '\n';
	
	return 0;
}