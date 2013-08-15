#include "words.h"

using namespace std ;

Words::Words(char *filename) {

    ifstream fd(filename) ;

    if(!fd.is_open()) {
	throw string("Error opening file: " + string(filename)) ;
    }

    string word ;
    while( getline(fd, word)  ) {
	storage.insert(word) ;
	sortedList.push_back(word) ;
	word.clear();
    }

    fd.close() ;
}

bool Words::isWordInList(string w) {
    return binary_search(sortedList.begin(), sortedList.end(), w) ;
}

void Words::displayStorage() {

    for(storageIterator = storage.begin() ; storageIterator != storage.end() ; storageIterator++) {
	cout << *storageIterator << endl ;
    }
}

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

string Words::findLongestCompoundWord() {
    for(storageIterator = storage.begin() ; storageIterator != storage.end() ; storageIterator++) {
	if(isWordACompound(*storageIterator, (*storageIterator).length() )) {
	    return *storageIterator ;
	}
    }
    return NULL;
}

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

int Words::findCountofAllCompoundedWords() {
    int count = 0 ;
    for(storageIterator = storage.begin() ; storageIterator != storage.end() ; storageIterator++) {
	if(isWordACompound(*storageIterator, (*storageIterator).length() )) {
	    ++count ;
	}
    }
    return count;
}

