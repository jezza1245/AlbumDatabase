#include <iostream>
#include <fstream>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"

int main(int argc, char** argv) {


	/*
		TESTING DURATION


	try {
		Duration d = Duration(0, 70, 0);
		Duration d1 = Duration(1, 10, 0);
		std::cout << "d: " << d << std::endl;
		std::cout << "d1: " << d1 << std::endl;
		if (d == d1) {
			std::cout << "Equal" << std::endl;
		}
		if (d != d1) {
			std::cout << "Not Equal" << std::endl;
		}
		if (d < d1) {
			std::cout << "Less Than" << std::endl;
		}
		if (d > d1) {
			std::cout << "Greater Than" << std::endl;
		}
		if (d <= d1) {
			std::cout << "Less Than, Or Equal" << std::endl;
		}
		if (d >= d1) {
			std::cout << "Greater Than, Or Equal" << std::endl;
		}
		std::cout << "d-d1 : " << d - d1 << std::endl;
		std::cout << "d+d1 : " << d + d1 << std::endl;

	}
	catch (Duration::DurationConstructorException& e) {
		std::cout << e.what() << std::endl;
	}

	Duration d = Duration(0, 1, 60);
	std::cout << d << std::endl;
	Track t = Track("Mappa Mundi", d);
	std::cout << t << std::endl;

	Track t1 = Track("Mappa Mundi", Duration(0, 2, 34));
	Track t2 = Track("Matal", Duration(0, 4, 11));
	std::vector<Track> albumCollection = { t1,t2 };

	Album alb = Album("Album Title", "Artist", &albumCollection);
	std::cout << alb;
	std::vector<Album> albums = {alb};
	Collection col = Collection(&albums);
	std::cout << col;
	*/

	/*
		Testing Input Streams
	*/
	/*duration
	Duration d;
	std::cin >> d;
	std::cout << d;
	*/
	/*track
	Track t;
	std::cin >> t;
	std::cout << t;


	Album a = Album("test_title", "test_artist");


	Track t;
	Duration d;

	std::cout << "ENTER DURATION: ";
	std::cin >> d;
	std::cout << "DURATION d: " << d << std::endl;


	std::cout << "ENTER Track: ";
	std::cin >> t;
	std::cout << "Track t: " << t << std::endl;

	a.addTrack(t);

	std::cout << "Album a: " << a << std::endl;

	Collection c;
	*/
	Collection c;
	std::ifstream infile;
	std::string line;
	infile.open("albums.txt");


	infile >> c;

	//std::cout << c << std::endl << "================" << std::endl;


	//Album::ascending(c.getAlbums().at(0), c.getAlbums().at(1));

	//std::cout << c;

	//Album::descending(c.getAlbums().at(0), c.getAlbums().at(1));

	//std::cout << c << std::endl << "################" <<std::endl;
	//c.displayAlbums();
	//std::cout << c << std::endl << "################" << std::endl;
	//std::cout << c.getTotalArtistPlayTime("Pink Floyd") << std::endl;
	c.displayAlbums(Album::ascending);
	return EXIT_SUCCESS;
}
