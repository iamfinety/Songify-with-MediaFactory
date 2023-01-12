#include "Album.h"

Album::Album(const string& a, const string& t){
    artist = a;
    title = t;
    // pointer = new SongArray();
}
// Album::Album(const Album& album){
//     artist = album.artist;
//     title = album.title;
//     pointer = new SongArray();
//     for(int i =0; i<album.pointer->size();++i){
//         Song* song;
//         if(album.pointer -> get(i, &song)){
//             pointer->add(i, new Song(*song));
//         }
//     }
// }
Album::~Album(){
    // delete pointer;
}
// string Album::getArtist(){
//     return artist;
// }
// string Album::getTitle(){
//     return title;
// }
bool Album::matches(const string& artist, const string& title) const{
    if(this->artist.compare(artist) == 0){
        if(this->title.compare(title) == 0){
            return true;
        }
    }
    return false;
 
}
bool Album::lessThan(const Album& alb) const{
    if(artist.compare(alb.artist)<0){
        return true;
    }
    else if(artist.compare(alb.artist) == 0){
        if(title.compare(alb.title)<0){
            return true;
        }
    }
    return false;
}
bool Album::addSong(Song* s){
    if(arr.isFull()){
        return false;
    }
    arr.add(s);
    return true;
}
int Album::getSize(){
    return arr.getSize();
}
Song* Album::operator[](int index){
	if (index < 0 || index >= arr.getSize()) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return arr[index];
}
// bool Album::getSong(const string& t, Song** song){
//     return pointer->get(this->artist, t, song);
// }
// bool Album::getSong(int index, Song** song){
//     return pointer->get(index, song);
// }
bool Album::removeSong(const string& t, Song** song){
    for(int i=0;i<arr.getSize();++i){
        if(t == arr[i]->getTitle()){
            arr -= *song;
            return true;
        }
    }
    return false;
}
// bool Album::removeSong(int index, Song** song){
//     return pointer->remove(index, song);
// }
// void Album::print(){

//     cout<<"Title of the album is: "<<getTitle()<<endl;
//     cout << "Artist of the album is: "<<getArtist()<<endl;
//     pointer->print();

// }
// void Album::printShort(){
//     cout<<"Title of the album is: "<<getTitle()<<endl;
//     cout << "Artist of the album is: "<<getArtist()<<endl;
// }
ostream& operator<<(ostream& ost, Album& album){
    ost<< endl;
    album.print(ost);
    return ost;
}
void Album::print(ostream& ost) const{
    ost<<"Title of the album is: "<<getTitle()<<endl<< "Artist of the album is: "<<getArtist()<<endl;
    for(int i = 0; i<arr.getSize();++i){
        cout<<*arr[i];
    }
}
void Album::printShort(ostream& ost) const{
    ost<<"Title of the album is: "<<getTitle()<<endl<< "Artist of the album is: "<<getArtist()<<endl;
}
