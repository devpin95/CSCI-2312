#ifndef FINAL_SORT_H
#define FINAL_SORT_H

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Asset.h"

using std::vector;

class Sort {

private:
    struct CompTitle {
        bool operator()( std::shared_ptr<Asset>  asset1, std::shared_ptr<Asset>  asset2 ) {
            return asset1->getTitle() < asset2->getTitle();
        }
    };

    struct CompCreator {
        bool operator()( std::shared_ptr<Asset>  asset1, std::shared_ptr<Asset>  asset2 ) {
            return asset1->getCreator() < asset2->getCreator();
        }
    };

    struct CompGenre {
        bool operator()( std::shared_ptr<Asset>  asset1, std::shared_ptr<Asset>  asset2 ) {
            return asset1->getGenre() < asset2->getGenre();
        }
    };

public:
    Sort( ) = default;
    //void sort( vector<Asset*>& );

    void sortByTitle( vector< std::shared_ptr<Asset> > );
    void sortByAuthor( vector< std::shared_ptr<Asset> > );
    void sortByGenre( vector< std::shared_ptr<Asset> > );
};


#endif //FINAL_SORT_H
