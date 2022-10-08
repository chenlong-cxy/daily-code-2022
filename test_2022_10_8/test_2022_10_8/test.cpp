//µ¥´Ê×ª»»
class Solution {
public:
	vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> us(wordList.begin(), wrodList.end());
		if (us.find(endWord) == us.end())
			return vector<string>();
		vector<string> ret = { beginWord };

	}
};