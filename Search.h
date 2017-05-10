#ifndef FINAL_SEARCH_H
#define FINAL_SEARCH_H

#include <vector>
#include <string>
#include <memory>
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
        vector< std::shared_ptr<Asset> > list;
        void operator()( std::shared_ptr<Asset> asset ) {
            if ( (*asset).getTitle().find( title ) != string::npos ) {
                list.push_back( asset );
            }
        }
    };

    struct CompCreator {
        string creator;
        vector< std::shared_ptr<Asset> > list;
        void operator()( std::shared_ptr<Asset> asset ) {
            if ( (*asset).getCreator().find( creator ) != string::npos ) {
                list.push_back( asset );
            }
        }
    };

    struct CompGenre {
        string genre;
        vector< std::shared_ptr<Asset> > list;
        void operator()( std::shared_ptr<Asset> asset ) {
            if ( (*asset).getGenre().find( genre ) != string::npos ) {
                list.push_back( asset );
            }
        }
    };

public:
    Search( ) = default;
    //void sort( vector<Asset*>& );

    vector< std::shared_ptr< Asset > > searchByTitle( const Store&, const string& );
    vector< std::shared_ptr< Asset > > searchByAuthor( const Store&, const string& );
    vector< std::shared_ptr< Asset > > searchByGenre( const Store&, const string& );

};


#endif //FINAL_SEARCH_H
