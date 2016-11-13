//
//  Trie.cpp
//  Scratchpad
//
//  Created by Teddy Engel on 13/11/2016.
//  Copyright © 2016 Teddy Engel. All rights reserved.
//

#include "Trie.h"

#include <iostream>
#include <memory>

TrieNode::TrieNode()
: _childrenCount(0)
, _endOfWord(false)
{

}

bool TrieNode::addString(const std::string& newString)
{
    const int newStringSize = newString.size();

    // We check if the string to be added is completely added
    if (newString.size() == 0)
    {
        // If it's not a duplicate of an existing word
        if (!_endOfWord)
        {
            // Sets the node as end of word
            _endOfWord = true;
            return true;
        }
        return false;
    }
    char letter = newString[0];
    std::string subString = newString.substr(1, newStringSize - 1);

    if (hasChildWithLetter(letter))
    {
        if (getChildWithLetter(letter).addString(subString))
        {
            _childrenCount++;
            return true;
        }
    }
    else
        if (addChildWithLetter(letter, subString))
        {
            _childrenCount++;
            return true;
        }
    return false;
}

void TrieNode::listStrings(const std::string prefix) const
{
    if (_endOfWord == true)
        std::cout << prefix << std::endl;
    if (_children.size() == 0)
        return;
    for (auto& entry : _children)
    {
        const char letter = entry.first;
        const TrieNode& trieNode = *entry.second;

        trieNode.listStrings(prefix + letter);
    }
}

void TrieNode::listStrings() const
{
    return listStrings("");
}

int TrieNode::countPartials(const std::string& partialString) const
{
    int count = 0;
    if (partialString.empty())
    {
        if (_endOfWord)
            return _childrenCount + 1;
        return _childrenCount;
    }
    if (_children.size() == 0)
        return count;        
    for (auto& entry : _children)
    {
        const char letter = entry.first;
        const TrieNode& trieNode = *entry.second;
        
        if (letter == partialString[0])
        {
            count += trieNode.countPartials(partialString.substr(1, partialString.size() - 1));
        }
    }
    return count;
}


bool TrieNode::hasChildWithLetter(char letter) const
{
    return _children.count(letter) > 0;
}

TrieNode& TrieNode::getChildWithLetter(char letter) 
{
    return *_children.at(letter);
}

bool TrieNode::addChildWithLetter(char letter, const std::string subString)
{
    _children.emplace(std::make_pair(letter, std::unique_ptr<TrieNode>(new TrieNode)));
    return _children.at(letter)->addString(subString);
}
