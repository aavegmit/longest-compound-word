#include "words.h"
#include<string>

using namespace std ;

int main(int argc, char **argv) {

    if(argc != 2) {
	cout << "Usage: solution <filename>" << endl ;
	exit(0) ;
    }

    try {
	Words w(argv[1]) ;
	vector<string> res = w.findNLongestCompoundWord(2) ;
	if(res.size() == 2) {
	    cout << "First Longest Compounded Word   : " << res.front() << endl ;
	    cout << "Second Longest Compounded Word  : " << res.back() << endl << endl ;
	}
	cout << "Total number of compounded words: " << w.findCountofAllCompoundedWords() << endl ;
    }
    catch (string s) {
	cout << "Exception: " << s << endl ;
    }
} // end of main function
