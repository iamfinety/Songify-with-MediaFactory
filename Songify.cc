#include "Songify.h"
#include "Criteria.h"


Songify::Songify(){
}
Songify::~Songify(){
    // delete pointer;
}
bool Songify::getAlbum(int index, Album** album){
    if (index < 0 || index >= array.getSize()) {
        return false;
	}
    *album = array[index];
	return true;
}
bool Songify::addAlbum(const string & artist , const string & albumTitle){
    if(!array.isFull()){
        Album* album;
        medieFactory.createAlbum(albumTitle, artist, &album);
        array.add(album);
        return true;
    }
    cout << "Failed to add album."<<endl;
    return false;
}
bool Songify::removeAlbum(const string & artist , const string & albumTitle){
    for(int i =0;i<array.getSize();++i){
        if(array[i]->matches(artist, albumTitle)){
            array -= array[i];
            return true;
        }
    }
    cout << "Failed to remove album."<<endl;
    return false;
}
bool Songify::addSong(const string & artist , const string & songTitle , const string & albumTitle){
    for(int i=0; i<array.getSize();++i){
        if(array[i]->matches(artist, albumTitle)){
            Song* song;
            medieFactory.createSong(artist, songTitle, &song);
            array[i]->addSong(song);
            return true;
        }
    }
    cout << "Failed to add song."<<endl;
    return false;
}
bool Songify::removeSong(const string & artist , const string & songTitle , const string & albumTitle){
    for(int i=0; i<array.getSize();++i){
        if(array[i]->matches(artist, albumTitle)){
            for(int a= 0; a<array[i]->getSize();++a){
                Song* songPtr = (*(array[i]))[a];
                if(songPtr->matches(artist, songTitle)){
                    array[i]->removeSong(songTitle, &songPtr);
                    return true;
                }
            }
        }
    }
    cout << "Failed to remove song."<<endl;
    return false;
}
const Array<Album*>& Songify::getAlbums(){
    return array;
}
Array<Song*> Songify::getPlaylist(string artist, string category, Array<Song*>  & playlist){
    Criteria* cri;
    medieFactory.createCriteria(artist, category, &cri);

    for(int i=0; i<array.getSize();++i){
        for(int a= 0; a<array[i]->getSize();++a){
            Song* songPtr = (*(array[i]))[a];
            if((*cri).matches(*songPtr)){
                playlist += songPtr;
            }
        }
    }
    return playlist;
}

