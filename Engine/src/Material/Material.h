#pragma once

#include "GL/glew.h"

#include <iostream>
#include<fstream>
#include <sstream>

using namespace std;

class Material
{
private:
	string vertexSource;
	string fragmentSource;

	string shaderFilepath;

	unsigned int shader;

public:
	Material();
	~Material();

	Material ParseShader();

	static unsigned int CompileShader(unsigned int type, 
		const char* source);

	static unsigned int CreateShader(string vertexShader,
		string fragmentShader);

	void SetShader();

	unsigned int GetShader();

	void UseShader();

	void SetFilepath(const char* filepath);

	void DeleteShader();
};