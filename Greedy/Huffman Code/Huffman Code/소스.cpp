#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int num;
	char alph;
	Node* left = NULL;
	Node* right = NULL;
};

struct cmp
{
	bool operator()(const pair<int, Node*> &a, const pair<int, Node*> &b) const
	{
		return a.first < b.first;
	}
};

map<char, int> m;
multiset<pair<int, Node*>, cmp> freq;
map<char, string> huffman_codes;

Node* build_Huffmantree(string s)
{
	//string에 있는 알파벳 빈도수 추가
	for (int i = 0; i < (int)s.size(); i++) {
		if (m.count(s[i]) > 0) m[s[i]]++;
		else m[s[i]] = 1;
	}

	//map의 원소들을 multiset에 넣기
	map<char, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		Node* newNode = new Node;
		newNode->alph = iter->first;
		newNode->num = iter->second;
		freq.insert(make_pair(iter->second, newNode));
	}

	while ((int)freq.size() > 1) {
		Node* n1 = freq.begin()->second;
		freq.erase(freq.begin());
		Node* n2 = freq.begin()->second;
		freq.erase(freq.begin());

		Node* newNode = new Node;

		if (n1->num == n2->num && n2->alph == '*') swap(n1, n2);
		newNode->num = n1->num + n2->num;
		newNode->alph = '*';
		newNode->left = n1;
		newNode->right = n2;
		freq.insert(make_pair(newNode->num, newNode));
	}

	return freq.begin()->second;
}

void set_Huffmancode(Node* node, string code)
{
	if (node->left == NULL && node->right == NULL) huffman_codes[node->alph] = code;
	if (node->left != NULL) set_Huffmancode(node->left, code + "0");
	if (node->right != NULL) set_Huffmancode(node->right, code + "1");

	return;
}

int main()
{
	string code;
	cout << "문장을 입력하시오: ";
	getline(cin, code);

	Node* newNode;
	newNode = build_Huffmantree(code);
	set_Huffmancode(newNode, "");

	for (int i = 0; i < (int)code.size(); i++) {
		cout << huffman_codes[code[i]];
	}

	return 0;
}