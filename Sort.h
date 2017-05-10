#ifndef FINAL_SORT_H
#define FINAL_SORT_H

#include <string>
#include <vector>
#include <algorithm>
#include "Asset.h"

using std::vector;

class Sort {

private:
    struct CompTitle {
        bool operator()( Asset* asset1, Asset* asset2 ) {
            return asset1->getTitle() < asset2->getTitle();
        }
    };

    struct CompCreator {
        bool operator()( Asset* asset1, Asset* asset2 ) {
            return asset1->getCreator() < asset2->getCreator();
        }
    };

    struct CompGenre {
        bool operator()( Asset* asset1, Asset* asset2 ) {
            return asset1->getGenre() < asset2->getGenre();
        }
    };

public:
    Sort( ) = default;
    //void sort( vector<Asset*>& );

    void sortByTitle( vector<Asset*>& );
    void sortByAuthor( vector<Asset*>& );
    void sortByGenre( vector<Asset*>& );
};


#endif //FINAL_SORT_H
