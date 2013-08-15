#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std ;

/*
 * Comparision structure to be passed in the set,
 * such that the words are inserted into the list
 * in an ordered way based on their length
 *
 */
struct compare {
    bool operator() (const string& lhs, const string& rhs) const
    {
	return lhs.length() >= rhs.length() ;
    }
};


class Words {
    private:
	set<string, compare> storage ;			// Container for storing the words
							// in order based on the length of
							// the word.
	
	set<string, compare>::iterator storageIterator; // Iterator on the storage container
	
	vector<string> sortedList ;			// Container for storing the words.
							// Assumes that the list is already
							// sorted.

	bool isWordInList(string w) ;			// Finds if the word is present
							// in the list. It assumes that 
							// the list is sorted and uses
							// binay search.
							//
							// Returns true/false
	
	bool isWordACompound(string w, int len) ;	// Finds if the word is a combination
							// of smaller words present in the file
							//
							// Returns true/false
    
    public:
	Words(char *filename) ;				// Constructor
	void displayStorage() ;				// Debugging method to print out the contents
							// of the storage container
	
	vector<string> findNLongestCompoundWord(int num) ;
	int findCountofAllCompoundedWords() ;

};
