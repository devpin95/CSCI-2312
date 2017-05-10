#ifndef FINAL_VIDEOBOOKREADER_H
#define FINAL_VIDEOBOOKREADER_H

#include <string>
#include <fstream>
#include "Store.h"
#include "Book.h"
#include "Video.h"
#include "FileException.h"

using std::string;

class Factory {
public:
    Factory() = default;
    void readBooks( Store&, const string& ) throw(FileException);
    void readVideos( Store&, const string& ) throw(FileException);

private:
    string books_file, videos_file;
};


#endif //FINAL_VIDEOBOOKREADER_H
