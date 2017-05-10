#ifndef FINAL_ASSET_H
#define FINAL_ASSET_H

#include <string>

using std::string;

class Asset {
public:

    static int tag;

    //generic age ratings
    enum age_rating {
        ALL = 0,
        CHILDREN,
        TEENS,
        ADULTS
    };

    //static age_rating ratings;

    Asset() : asset_tag(++tag) {  };
    Asset( const string& t ) : title(t), asset_tag(tag) { ++tag; };
    virtual ~Asset() {
        title = "";
        genre= "";
        creator = "";
        count = "";
        release_date = "";
        availability = false;
        rating = ALL;
    };

    //mutators
    void setTitle( const string& t )  { title = t; };
    void setGenre( const string& g ) { genre = g; };
    void setAuthor( const string& a ) { creator = a; };
    void setCount( const string& c ) { count = c; }
    void setReleaseDate( const string& r ) { release_date = r; };
    void setAvailability( bool set ) { availability = set; };
    virtual void setAgeRating( age_rating r ) { rating = r; };

    //accessors
    virtual string getTitle( void ) const  { return title; };
    virtual string getGenre( void ) const  { return genre; };
    virtual string getCreator( void ) const  { return creator; };
    virtual string getCount( void ) const = 0; //pure virtual
    string getAssetTag( void ) const { return std::to_string( asset_tag ); };
    virtual age_rating getAgeRating( void ) const  { return rating; };
    string getReleaseDate( void ) const  { return release_date; };

    //helper functions
    virtual void readAssetFromFile( std::ifstream& ) = 0; //pure virtual
    bool isAvailable() const { return availability; };
    bool operator<( Asset* asset ) {
      return this->asset_tag < asset->asset_tag;
    };

protected:
    int asset_tag;
    bool availability;
    string creator, title, genre, release_date, count;
    age_rating rating;
};


#endif //FINAL_ASSET_H
