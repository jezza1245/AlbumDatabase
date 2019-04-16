#include <iostream>
#include <fstream>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"

int main(int argc, char** argv) {


	/*
		Testing Duration



	*/
	/*
		Testing Track



	*/
	/*
		Testing Album



	*/




	/*
		Program
	*/
	// 1) Read in colleciton from albums.txt
	Collection c;
	std::ifstream infile;
	infile.open("albums.txt");
	infile >> c;

	// 2) Display entire album alphabetically
	std::cout << "##########################" << std::endl << "Collection in Ascending Order..." 
		<< std::endl << "##########################" << std::endl;
	c.displayAlbums(Album::ascending); // <-
	std::cout << "##########################" << std::endl << std::endl;
	
	// 3) Display total play time of all Pink Floyd albums in collection
	std::cout << "##########################" << std::endl << "Total Playtime of artist..."
		<< std::endl << "##########################" << std::endl;
	std::cout << c.getTotalArtistPlayTime("Pink Floyd") << std::endl; // <-
	std::cout << "##########################" << std::endl << std::endl;

	// 4) Display album with the largest number of tracks
	std::cout << "##########################" << std::endl << "Album with most tracks..."
		<< std::endl << "##########################" << std::endl;
	std::cout << c.getAlbumWithMostTracks() << std::endl; // <-
	std::cout << "##########################" << std::endl << std::endl;

	// 5) Display details of longest track in collection
	std::cout << "##########################" << std::endl << "Longest track in collection..."
		<< std::endl << "##########################" << std::endl;
	std::cout << c.getLongestTrack() << std::endl; // <-
	std::cout << "##########################" << std::endl << std::endl;


	return EXIT_SUCCESS;
}
