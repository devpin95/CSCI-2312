#include "Search.h"

vector< std::shared_ptr< Asset > > Search::searchByTitle( const Store& store, const string& title ) {
    CompTitle comparator;
    comparator.title = title;
    store.search( comparator );

    sorter.sortByTitle( comparator.list );

    return comparator.list;
}

vector< std::shared_ptr< Asset > > Search::searchByAuthor( const Store& store, const string& author ) {
    CompCreator comparator;
    comparator.creator = author;
    store.search( comparator );

    sorter.sortByAuthor( comparator.list );

    return comparator.list;
}

vector< std::shared_ptr< Asset > > Search::searchByGenre( const Store& store, const string& genre ) {
    CompGenre comparator;
    comparator.genre = genre;
    store.search( comparator );

    sorter.sortByGenre( comparator.list );

    return comparator.list;
}