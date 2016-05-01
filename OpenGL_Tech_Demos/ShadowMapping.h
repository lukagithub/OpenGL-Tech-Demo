#ifndef SHADOW_MAPPING_H
#define SHADOW_MAPPING_H

#include "camera.h"
#include "shader.h"
#include "Math\vector3.h"
#include <SOIL\SOIL.h>

class ShadowMapping
{
public:
	ShadowMapping();
	~ShadowMapping();
	void InitalizeScene();
	void UpdateScene();
	Camera camera;

private:
	Shader shaderDepth, shaderShadowMap;
	Shader shaderDebugQuad;
	vector3 lightPosition;
	GLuint floorTexture, cubeTexture;
	int SCREEN_WIDTH = 1100;
	int SCREEN_HEIGHT = 600;
	const GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
	GLuint depthMap, depthMapFBO;
	GLuint planeVAO, planeVBO;

	void RenderScene(Shader &shader);
	void RenderQuad();
	void RenderCube();
	GLuint LoadTexture(GLchar *path, bool gammaCorrection);
	GLuint GenerateMultiSampleTexture(GLuint samples);
};

#endif