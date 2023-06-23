// Project UID af1f95f547e44c8ea88730dfb185559ds
#include "Matrix.h"
#include "Image.h"
#include "processing.h"
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char* argv[]) {
	if (argc < 4 || 5 < argc) {
		cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" << 
			"WIDTH and HEIGHT must be less than or equal to original" << endl; 
		return 1;
	}
	ifstream fin; fin.open(argv[1]);
	if (!fin.is_open()) {
		cout << "Error opening file: " << argv[1] << endl; 
		return 1;
	}
	Image* img = new Image; Image_init(img, fin);
	int newWidth, newHeight;
	stringstream w_input(argv[3]);
	w_input >> newWidth;
	if (argc == 5) {
		stringstream h_input(argv[4]); h_input >> newHeight;
	}
	else {
		newHeight = Image_height(img);
	}
	if (newWidth <= 0 || newWidth > Image_width(img) 
		|| newHeight <= 0 || newHeight > Image_height(img)) {
		cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" <<
			"WIDTH and HEIGHT must be less than or equal to original" << endl; 
		return 1;
	}
	seam_carve(img, newWidth, newHeight);
	ofstream fout(argv[2]); Image_print(img, fout);
	delete img; return 0;
}