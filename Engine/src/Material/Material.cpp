#include "Material.h"

Material::Material()
{

}

Material::~Material()
{

}

Material Material::ParseShader()
{
	ifstream stream(shaderFilepath);

	if (!stream.is_open())
	{
		cout << "ERROR: Could not open shader file: "
			<< shaderFilepath << endl;

		return Material();
	}

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	string line;
	stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("shader") != string::npos)
		{
			if (line.find("vertex") != string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
			ss[(int)type] << line << "\n";
	}

	Material newmaterial;

	newmaterial.vertexSource = ss[0].str();
	newmaterial.fragmentSource = ss[1].str();
	newmaterial.shaderFilepath = shaderFilepath;

	return newmaterial;
}

unsigned int Material::CompileShader(unsigned int type, const char* source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source;
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
			<< " shader" << std::endl;
		cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

unsigned int Material::CreateShader(string vertexShader, string fragmentShader)
{
	unsigned int  program = glCreateProgram();
	unsigned int vS = CompileShader(GL_VERTEX_SHADER, vertexShader.c_str());
	unsigned int fS = CompileShader(GL_FRAGMENT_SHADER, fragmentShader.c_str());

	glAttachShader(program, vS);
	glAttachShader(program, fS);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vS);
	glDeleteShader(fS);

	return program;
}

void Material::SetShader()
{
	shader = CreateShader(vertexSource, fragmentSource);
}

unsigned int Material::GetShader()
{
	return shader;
}

void Material::UseShader()
{
	glUseProgram(shader);
}

void Material::SetFilepath(const char* filepath)
{
	shaderFilepath = filepath;
}

void Material::DeleteShader()
{
	glDeleteShader(shader);
}
