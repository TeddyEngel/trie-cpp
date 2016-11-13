//
//  main.cpp
//  Scratchpad
//
//  Created by Teddy Engel on 13/11/2016.
//  Copyright © 2016 Teddy Engel. All rights reserved.
//

#include <iostream>
#include <unordered_map>

#include "Trie.h"

int main(int argc, const char * argv[])
{
    Trie trie;
    trie.addString("Teddy");
    trie.addString("Toto");
    trie.addString("Torrence");
    trie.addString("T");
    trie.addString("Ted");
    trie.addString("Ted");
    trie.addString("Ted");
    trie.addString("Te");
    trie.addString("n");
    
    trie.listStrings();
    std::cout << "Partials for To: " << trie.countPartials("To") << std::endl;
    std::cout << "Partials for Te: " << trie.countPartials("Te") << std::endl;
    
    return 0;
}
