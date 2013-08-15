#include "words.h"

using namespace std ;

/*
 * Constructor
 */
Words::Words(char *filename) {

    ifstream fd(filename) ;

    if(!fd.is_open()) {
	throw string("Error opening file: " + string(filename)) ;
    }

    string word ;
    while( getline(fd, word)  ) {
	if(!word.empty()) {
	    storage.insert(word) ;
	    sortedList.push_back(word) ;
	    word.clear();
	}
    }

    fd.close() ;
}

/* 
 * search if the word is in the list or not
 * It assumes that the list is sorted and uses 
 * binary search.
 *
 * Other alternative is to use Trie as the storage, 
 * thus reducing the search time complexity
 */
bool Words::isWordInList(string w) {
    return binary_search(sortedList.begin(), sortedList.end(), w) ;
}

/*
 * Debugging method to display all the words
 * in the storage member, sorted by length of
 * the word
 */
void Words::displayStorage() {

    for(storageIterator = storage.begin() ; storageIterator != storage.end() ; storageIterator++) {
	cout << *storageIterator << endl ;
    }
}

/*
 * Method to find if a word is compound or not.
 */
bool Words::isWordACompound(string s, int origLen) {
    if(s.length() == 0) {
	return true ;
    }
    for(unsigned int i = 0 ; i <= s.length()  ; ++i) {
	if(i < (unsigned int)origLen && 
		isWordInList(s.substr(0,i)) && 
		isWordACompound(s.substr(i, s.length()) , origLen )  ) {
	    return true ;
	}
    }
    return false ;

}

/*
 * Method to return a set of N longest compound strings
 *
 * arg: int N
 * returns: vector
 */
vector<string> Words::findNLongestCompoundWord(int num) {
    vector<string> result ;
    int count = 0 ;
    for(storageIterator = storage.begin() ; storageIterator != storage.end() ; storageIterator++) {
	if(count >= num)
	    break ;
	if(isWordACompound(*storageIterator, (*storageIterator).length() )) {
	    result.push_back(*storageIterator) ;
	    ++count ;
	}
    }
    return result;
}

/*
 * Count the number of compunded strings in the list
 *
 */
int Words::findCountofAllCompoundedWords() {
    int count = 0 ;
    for(storageIterator = storage.begin() ; storageIterator != storage.end() ; storageIterator++) {
	if(isWordACompound(*storageIterator, (*storageIterator).length() )) {
	    ++count ;
	}
    }
    return count;
}

