#include "Sort.h"

void Sort::sortByTitle( vector< std::shared_ptr<Asset> > list ) {
    CompTitle comparitor;
    std::sort( list.begin(), list.end(), comparitor );
}

void Sort::sortByAuthor( vector< std::shared_ptr<Asset> > list ) {
    CompCreator comparitor;
    std::sort( list.begin(), list.end(), comparitor );
}

void Sort::sortByGenre( vector< std::shared_ptr<Asset> > list ) {
    CompGenre comparitor;
    std::sort( list.begin(), list.end(), comparitor );
}