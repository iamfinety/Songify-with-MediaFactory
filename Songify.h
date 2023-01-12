#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include "Album.h"
#include "Array.h"
#include "MediaFactory.h"
#include"Song.h"
using namespace std;

class Songify {
		
	public:
		//constructors
		Songify();

		//destructor
		~Songify();
		bool getAlbum(int, Album**);
		const Array<Album*>& getAlbums();
		// add and remove Songs and Albums
		Array<Song*> getPlaylist(string artist, string category, Array<Song*> & playlist);

		bool addAlbum ( const string & artist , const string & albumTitle );
		bool addSong ( const string & artist , const string & songTitle , const string & albumTitle );
		bool removeSong ( const string & artist , const string & songTitle , const string & albumTitle );
		bool removeAlbum ( const string & artist , const string & albumTitle );


	
	private:
		Array<Album*> array;
		MediaFactory medieFactory;
	
};
#endif