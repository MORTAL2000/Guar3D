#include "StandardUniforms.h"

//GFX inc
#include "../OpenGL/OpenGL.h"
#include "../Graphics.h"
#include "../Texture/Texture.h"
#include "../RenderCamera/RenderCamera.h"
#include "../RenderObject/RenderObject.h"
#include "../RenderLight/RenderLight.h"
#include "../RenderObserver/RenderObserver.h"
#include "../RenderTexture/RenderTexture.h"
#include "../ShaderProgram/ShaderProgram.h"
//Time inc
#include <time/Time.h>
//external inc
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace guar;
using namespace GFX;

//Standard uniform names
const char* StandardUniforms::CameraPosition        = "_CameraPosition"     ;
const char* StandardUniforms::Time                  = "_Time"               ;
const char* StandardUniforms::Texture               = "_Texture"            ;
const char* StandardUniforms::MVP                   = "_MVP"                ;
const char* StandardUniforms::ModelMatrix           = "_ModelMatrix"        ;
const char* StandardUniforms::ModelRotationMatrix   = "_ModelRotationMatrix";
const char* StandardUniforms::ViewMatrix            = "_ViewMatrix"         ;
const char* StandardUniforms::ProjectionMatrix      = "_ProjectionMatrix"   ;
const char* StandardUniforms::ModelViewMatrix       = "_ModelViewMatrix"    ;
const char* StandardUniforms::Normal2WorldMatrix    = "_Normal2WorldMatrix" ;
const char* StandardUniforms::Normal2EyeSpaceMatrix = "_NormalMatrix"       ;

void StandardUniforms::loadStandardUniforms(RenderObject &aRenderObject, RenderObserver* aCamera, std::vector<RenderLight> &aLights, std::map<std::string, std::weak_ptr<GFX::Texture>> aTextureUniforms)
{
	//REFACTOR THIS GARBAGE
	GFXuint aShaderProgramHandle  = aRenderObject.getShaderProgram()._Get()->getProgramHandle();
	Math::Vector3    aPosition    = aRenderObject.getPosition();
	Math::Quaternion aRotation    = aRenderObject.getRotation();
	Math::Vector3    aScale       = aRenderObject.getScale();
	//REFACTOR THIS GARBAGE
	Math::Vector3    aCameraPosition = aCamera->getPosition();
	Math::Quaternion aCameraRotation = aCamera->getRotation();
	float            aNearClipDist   = aCamera->getNearClippingDistance();
	float            aFarClipDist    = aCamera->getFarClippingDistance();
	float            aFOV            = aCamera->getFieldOfView();

	//TIME
	GLHelp::Uniforms::load1Foat  (aShaderProgramHandle, StandardUniforms::Time, Time::getTime());
	
	//TEXTURE UNIFORMS
	if (aTextureUniforms.size() != 0)
		for (std::map<std::string, std::weak_ptr<guar::GFX::Texture>>::iterator i = aTextureUniforms.begin(); i != aTextureUniforms.end(); ++i)
			GLHelp::Uniforms::loadTexture(aShaderProgramHandle, i->first.c_str(), i->second._Get()->getHandle());
	else
	{
		GLHelp::Uniforms::loadTexture(aShaderProgramHandle, StandardUniforms::Texture, Graphics::getTexture("")._Get()->getHandle());
	
	}

	//CAMERA POS
	{
		Math::Vector3 pos = aCameraPosition;
		float* ptr(&pos.x);
		GLHelp::Uniforms::loadVector3f(aShaderProgramHandle, StandardUniforms::CameraPosition, ptr);
		
	}

	//CAMERA VP
	{
		//aCameraRotation


	}

	//MODEL
	glm::mat4x4 model;
	model = glm::translate<>(model, glm::vec3(aPosition.x, aPosition.y, aPosition.z)); //note the backwards mat mul. trs not srt.
	//model = glm::rotate(model, aRotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); //This seems wasteful. Google
	//model = glm::rotate(model, aRotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	//model = glm::rotate(model, aRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::quat rotation;
	rotation.x = aRotation.x;
	rotation.y = aRotation.y;
	rotation.z = aRotation.z;
	rotation.w = aRotation.w;
	model = model * (model, glm::mat4_cast(rotation));


	model = glm::scale(model, glm::vec3(aScale.x, aScale.y, aScale.z));    //not working      
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::ModelMatrix, &model[0][0]);

	glm::mat4x4 view;
	glm::mat4x4 projection;
	aCamera->generateViewProjectionMatrix(&view, &projection, 0);

	//MODELROTATION
	glm::mat4x4 modelRotation;
	modelRotation = glm::rotate(modelRotation, aRotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); //This seems wasteful. Google
	modelRotation = glm::rotate(modelRotation, aRotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	modelRotation = glm::rotate(modelRotation, aRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::ModelRotationMatrix, &modelRotation[0][0]);

	//VIEW
	//glm::mat4x4 view;
	//view = glm::rotate(view, aCameraRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	//view = glm::rotate(view, aCameraRotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	//view = glm::rotate(view, aCameraRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	//view = glm::translate<>(view, glm::vec3(-aCameraPosition.x, -aCameraPosition.y, -aCameraPosition.z));	
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::ViewMatrix, &view[0][0]);

	//PROJECTION
	//float aspectRatio = Graphics::getWindowSize().getAspectRatio();
	//glm::mat4x4 projection = glm::perspective(glm::radians(aFOV), aspectRatio, aNearClipDist, aFarClipDist);
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::ProjectionMatrix, &projection[0][0]);

	//MV
	glm::mat4x4 mv = view * model;
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::ModelViewMatrix, &mv[0][0]);

	//MVP
	glm::mat4x4 mvp = projection * view * model;
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::MVP, &mvp[0][0]);

	//NORMAL MATS				///////////DOUBLE CHECK THESE FOLLOWING MATS
	//Normal2EyeSpaceMatrix
	glm::mat4x4 normal2EyeSpaceMatrix = glm::inverseTranspose(mv);
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, StandardUniforms::Normal2EyeSpaceMatrix, &normal2EyeSpaceMatrix[0][0]);

	//model matrix inverse transpose
	glm::mat4x4 modelMatrixInverseTranspose = glm::inverseTranspose(model);
	const char* name = "_InverseTransposeModelMatrix";
	GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, name, &modelMatrixInverseTranspose[0][0]);
	
	//Normal2WorldMatrix
	
	//FORWARD RENDERING LIGHTS
	//_NumberOfLights

	for (int i = 0; i < aLights.size(); i++)//
	{
		const char* lightPositionUniformName  = "_Light1Position";
		const char* lightMapUniformName		  = "_Light1Map";
		const char* lightMapMatrixUniformName = "_Light1Matrix";

		Math::Vector3 pos = aLights[i].getPosition();
		float* ptr(&pos.x);

		glm::mat4x4 lightview;//_Light1Matrix
		//Vector3 lightPos = aLights[i].getPosition();
		//Vector3 lightRot = aLights[i].getRotation();
		//
		////Light view
		//lightview = glm::rotate(lightview, lightRot.x, glm::vec3(1.0f, 0.0f, 0.0f));
		//lightview = glm::rotate(lightview, lightRot.y, glm::vec3(0.0f, 1.0f, 0.0f));
		//lightview = glm::rotate(lightview, lightRot.z, glm::vec3(0.0f, 0.0f, 1.0f));
		//lightview = glm::translate<>(lightview, glm::vec3(-lightPos.x, -lightPos.y, -lightPos.z));
		//Light projection
		//float aspectRatio = Graphics::getWindowSize().getAspectRatio();
		glm::mat4x4 lightProjection;// = glm::perspective(glm::radians(aFOV), aspectRatio, aNearClipDist, aFarClipDist);
		//glm::mat4x4 lightProjection = glm::perspective(glm::radians(aLights[i].getFieldOfView()), aspectRatio, aLights[i].getNearClippingDistance(), aLights[i].getFarClippingDistance());
		
		aLights[i].generateViewProjectionMatrix(&lightview, &lightProjection, 0);

		glm::mat4 biasMatrix(
			0.5, 0.0, 0.0, 0.0,
			0.0, 0.5, 0.0, 0.0,
			0.0, 0.0, 0.5, 0.0,
			0.5, 0.5, 0.5, 1.0
		);

		glm::mat4x4 lightmat = biasMatrix * lightProjection * lightview * model;


		/* pointlight, spotlight, shadowcaster */
		//_Light1Type
		GLHelp::Uniforms::loadVector3f(aShaderProgramHandle, lightPositionUniformName, ptr); //_Light1Position
		//_Light1Intensity
		//
		/* spotlight, shadowcaster */
		//_Light1Rotation
		//
		/* shadowcaster */
		GLHelp::Uniforms::loadTexture(aShaderProgramHandle, lightMapUniformName, aLights[i].getRenderTexture()._Get()->getDepthTextureHandle(),1);//_Light1Map
		GLHelp::Uniforms::loadMatrix4x4(aShaderProgramHandle, lightMapMatrixUniformName, &lightmat[0][0]); //_Light1WorldToLightMap

	}



}