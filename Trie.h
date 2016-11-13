//
//  Trie.h
//  Scratchpad
//
//  Created by Teddy Engel on 13/11/2016.
//  Copyright © 2016 Teddy Engel. All rights reserved.
//

#include <unordered_map>

class TrieNode
{
public:
    TrieNode();

    bool addString(const std::string& newString);
    void listStrings(const std::string prefix) const;
    void listStrings() const;
    int countPartials(const std::string& partialString) const;

private:
    bool hasChildWithLetter(char letter) const;
    TrieNode& getChildWithLetter(char letter);
    bool addChildWithLetter(char letter, const std::string subString);

    int _childrenCount;
    bool _endOfWord;
    std::unordered_map<char, std::unique_ptr<TrieNode>> _children;
};

using Trie = TrieNode;
