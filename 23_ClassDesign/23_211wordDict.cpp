#include "../21_Huawei/21_header.h"

// 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
// 实现词典类 WordDictionary ：
// WordDictionary() 初始化词典对象

// leecode211
// 示例：
// 输入：
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// 输出：
// [null,null,null,null,false,true,true,true]

// 解释：
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // 返回 False
// wordDictionary.search("bad"); // 返回 True
// wordDictionary.search(".ad"); // 返回 True
// wordDictionary.search("b.."); // 返回 True

class WordDictionary1 {
public:
    vector<string> dic;
    WordDictionary1() {

    }
    
    void addWord(string word) {
        dic.push_back(word);
    }

    bool equal(string& ele, string& word) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != '.' && word[i] != ele[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool search(string word) {
        for (auto &ele : dic) {
            bool find = true;
            if (ele.size() != word.size()) continue;

            if (equal(ele, word)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
public:
    vector<WordDictionary*> children;
    bool isend;

    WordDictionary(): children(26), isend(false) {
    }

    void addWord(string word) {
        // root is self
        WordDictionary* node = this;
        int idx;
        for (char ch : word) {
            idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new WordDictionary();
            }
            node = node->children[idx];
        }
        node->isend = true;
    }
    
    bool dfs(string &word, int index, WordDictionary* node) {
        if (index == word.size()) {
            return node->isend;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            int idx = ch - 'a';
            WordDictionary* child = node->children[idx];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        }else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                WordDictionary* child = node->children[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(string word) {
        return dfs(word, 0, this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */