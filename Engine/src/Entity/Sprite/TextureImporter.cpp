#include "TextureImporter.h"

TextureImporter::TextureImporter()
{
	
}

TextureImporter::TextureImporter(const char* filepath)
{
	this-> filepath = filepath;
	texWidth = 0;
	texHeight = 0;
	nrChannels = 0;
}

TextureImporter::~TextureImporter()
{

}

int& TextureImporter::GetWidth()
{
	return texWidth;
}

int& TextureImporter::GetHeight()
{
	return texHeight;
}

int& TextureImporter::GetNrChannels()
{
	return nrChannels;
}

unsigned char* TextureImporter::GetTexData()
{
	return data;
}

const char* TextureImporter::GetFilePath()
{
	return filepath;
}

