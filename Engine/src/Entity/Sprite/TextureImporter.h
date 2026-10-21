#pragma once
#include <iostream>


class TextureImporter
{
private:
	int width;
	int height;
	int nrChannels;

public:
	TextureImporter();

	TextureImporter(std::string filepath);

	~TextureImporter();

	int GetWidth();
	int GetHeight();
	int GetNrChannels();
};