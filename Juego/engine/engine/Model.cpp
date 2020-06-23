#include "Model.h"

void Model::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	for (Triangle* triangle : this->triangles)
	{
		triangle->Render();
	}
	glPopMatrix();
}

void Model::LoadModel(const string& filename)
{
	string line;
	ifstream modelFile(filename.c_str());
	if (modelFile.is_open())
	{
		while (modelFile.good())
		{
			getline(modelFile, line);
			if (line.c_str()[0] == 'v' && line.c_str()[1] == 't')
			{
				cout << ">>> Esto es una coordenada de textura de un vértice: \n";
				cout << line << "\n";
				line[0] = ' ';
				line[1] = ' ';
				this->textures.push_back(this->parseLineToVector3D(line));
				cout << ">>>>> tamaño de texture: " << this->textures.size() << "\n";
			}
			else if (line.c_str()[0] == 'v' && line.c_str()[1] == 'n')
			{
				cout << ">>> Esto es la normal de un vértice: \n";
				cout << line << "\n";
				line[0] = ' ';
				line[1] = ' ';
				this->normals.push_back(this->parseLineToVector3D(line));
				cout << ">>>>> tamaño de normals: " << this->normals.size() << "\n";
			}
			else if (line.c_str()[0] == 'v')
			{
				cout << ">>> Esto es un vértice: \n";
				cout << line << "\n";
				line[0] = ' ';
				this->vertexes.push_back(this->parseLineToVector3D(line));
				cout << ">>>>> tamaño de vertexes: " << this->vertexes.size() << "\n";

			}
			else if (line.c_str()[0] == 'f')
			{
				cout << ">>> Esto es una cara: \n";
				cout << line << "\n";

				line[0] = ' ';
				this->triangles.push_back(this->parseFace(line));

			}
			else if (line.c_str()[0] == '#')
			{
				cout << ">>> Esto es un comentario: \n";
				cout << line << "\n";
			}
			else
			{
				cout << ">>> Esto no se sabe lo que es: \n";
				cout << line << "\n";
			}
		}
		modelFile.close();
	}
}

Vector3D* Model::parseLineToVector3D(string& line)
{
	istringstream lineManager(line);
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	lineManager >> x;
	lineManager >> y;
	lineManager >> z;
	Vector3D* vector = new(nothrow) Vector3D(x, y, z);
	return vector;
}

Triangle* Model::parseFace(string& line)
{
	istringstream lineManager(line);
	int firstVertexIndex = 0;
	//int firstVertexTexture = 0;
	int firstVertexNormal = 0;

	int secondVertexIndex = 0;
	//int secondVertexTexture = 0;
	int secondVertexNormal = 0;

	int thirdVertexIndex = 0;
	//int thirdVertexTexture = 0;
	int thirdVertexNormal = 0;

	char c;
	lineManager >> firstVertexIndex >> c >> c >> firstVertexNormal;
	lineManager >> secondVertexIndex >> c >> c >> secondVertexNormal;
	lineManager >> thirdVertexIndex >> c >> c >> thirdVertexNormal;

	cout << firstVertexIndex << "/" << "/" << firstVertexNormal << endl;
	cout << secondVertexIndex << "/" << "/" << secondVertexNormal << endl;
	cout << thirdVertexIndex << "/" << "/" << thirdVertexNormal << endl;

	Vector3D triangleVertex1 = *this->vertexes[--firstVertexIndex];
	Vector3D triangleVertex2 = *this->vertexes[--secondVertexIndex];
	Vector3D triangleVertex3 = *this->vertexes[--thirdVertexIndex];
	Vector3D triangleNormal = *this->normals[--firstVertexNormal];
	Triangle* triangle = new(nothrow) Triangle(
		triangleVertex1,
		triangleVertex2,
		triangleVertex3,
		triangleNormal);
	return triangle;
}
