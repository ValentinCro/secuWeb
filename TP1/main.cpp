#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> buffer;

typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef struct tagBITMAPFILEHEADER {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

int main() {
    int LENGTH = 54;
    ifstream fileEnc ("chiffre_mystere.bmp", ios::binary);
    ifstream file ("new.bmp", ios::binary | ios::in);
    fstream fileDec ("decrypt.bmp", ios::binary | ios::out | ios::app);

    /*char* buffer = new char [LENGTH];
    file.read(buffer, LENGTH);
    fileDec.write(buffer, LENGTH);*/

    fileEnc.seekg(0, fileEnc.end);
    int length = fileEnc.tellg();
    cout << length << endl;
    buffer.resize(length);
    fileEnc.read(&buffer[0],length);

    file_header = (PBITMAPFILEHEADER)(&buffer[0]);
    info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));

    cout << buffer[0] << buffer[1] << endl;
    cout << file_header->bfSize << endl;
    cout << info_header->biWidth << " " << info_header->biHeight << endl;
    /*char* enc = new char [length];
    fileEnc.seekg(0, fileEnc.beg);
    fileEnc.read(enc,length);
    fileDec.write(enc, length);*/

    file.close();
    fileEnc.close();
    fileDec.close();

    return 0;
}