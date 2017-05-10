#ifndef FINAL_SEARCH_H
#define FINAL_SEARCH_H

#include <vector>
#include <string>
#include "Asset.h"
#include "Store.h"
#include "Sort.h"

using std::vector;
using std::string;

class Store;
//class Sort;

class Search {

private:
    Sort sorter;
    struct CompTitle {
        string title;
        vector<Asset*> list;
        void operator()( Asset* asset ) {
            if ( (*asset).getTitle().find( title ) != string::npos ) {
                list.push_back( asset );
            }
        }
    };

    struct CompCreator {
        string creator;
        vector<Asset*> list;
        void operator()( Asset* asset ) {
            if ( (*asset).getCreator().find( creator ) != string::npos ) {
                list.push_back( asset );
            }
        }
    };

    struct CompGenre {
        string genre;
        vector<Asset*> list;
        void operator()( Asset* asset ) {
            if ( (*asset).getGenre().find( genre ) != string::npos ) {
                list.push_back( asset );
            }
        }
    };

public:
    Search( ) = default;
    //void sort( vector<Asset*>& );

    vector<Asset*> searchByTitle( const Store&, const string& );
    vector<Asset*> searchByAuthor( const Store&, const string& );
    vector<Asset*> searchByGenre( const Store&, const string& );

};


#endif //FINAL_SEARCH_H
