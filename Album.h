#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Song.h"
using namespace std;

class Album {
	friend ostream& operator<<(ostream&, Album&);
		
	public:
		//constructors
		Album(const string& artist, const string& albumTitle);
		Album(const Album&);

		//destructor
		~Album();

		//getters
		const string& getTitle()const{return title;}
		const string& getArtist()const{return artist;}

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		bool lessThan(const Album&) const;

		//add and remove
		bool addSong(Song*);
		// bool addSong(int, Song*);
		int getSize();
		//bool getSong(const string& songTitle, Song**) const;
		//bool getSong(int, Song**) const;
		bool removeSong(const string& songTitle, Song**);
		// bool removeSong(int, Song**);
		Song* operator[](int index);
		void printShort(ostream&) const;
		void print(ostream&) const;
	
	private:
		string title;
		string artist;
		Array<Song*> arr;
	
};
#endif