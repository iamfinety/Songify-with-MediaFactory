#include "Song.h"

Song::Song(const string& artist, const string& title, const string& category, const string& content){
    this->artist = artist;
    this->title = title;
    this->category = category;
    this->content = content;
}

const string& Song::getArtist() const{
    return artist;
}
const string& Song::getTitle() const{
    return title;
}
const string& Song::getCategory() const{
    return category;
}
bool Song::matches(const string& artist, const string& title) const{
    if(this->artist.compare(artist) == 0){
        if(this->title.compare(title) == 0){
            return true;
        }
    }
    return false;
}
ostream& operator<<(ostream& ost, Song& song){
    ost<< endl;
    song.print(ost);
    return ost;
}
void Song::print(ostream& ost) const{
    ost<< "Artist of the song is: "<<getArtist()<<endl;
    ost<< "Title of the song is: "<<getTitle()<<endl<< "Category of the song is: "<<getCategory()<<endl;
}
void Song::play(ostream& ost) const{
    ost<< "Artist of the song is: "<<getArtist()<<endl;
    ost<< "Title of the song is: "<<getTitle()<<endl<< "Category of the song is: "<<getCategory()<<endl;
    ost << "Content of the song is: "<<content <<endl;
}