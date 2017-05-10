#include "Sort.h"

void Sort::sortByTitle( vector<Asset*>& list ) {
    CompTitle comparitor;
    std::sort( list.begin(), list.end(), comparitor );
}

void Sort::sortByAuthor( vector<Asset*>& list ) {
    CompCreator comparitor;
    std::sort( list.begin(), list.end(), comparitor );
}

void Sort::sortByGenre( vector<Asset*>& list ) {
    CompGenre comparitor;
    std::sort( list.begin(), list.end(), comparitor );
}