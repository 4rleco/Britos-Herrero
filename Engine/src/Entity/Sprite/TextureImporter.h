#pragma once

class TextureImporter
{
private:
	const char* filepath;

	unsigned char* data;

	int texWidth;
	int texHeight;
	int nrChannels;

public:
	TextureImporter();

	TextureImporter(const char* filepath);

	~TextureImporter();

	int& GetWidth();
	int& GetHeight();
	int& GetNrChannels();

	unsigned char* GetTexData();

	const char* GetFilePath();
};