/*
#include "Opaque.h"

#include "../../../OpenGL/OpenGL.h"

using namespace guar;

staticShaders::Opaque::Opaque() : StaticShaderProgram::StaticShaderProgram("Opaque",vertexShaderGLSL(),fragmentShaderGLSL()) {}

//
// OpenGL calls
//
void staticShaders::Opaque::glDrawCalls(void)
{
    glClearColor(1.0f,0.0f,1.0f,0.0f);
    
}

//
// Vertex GLSL
//
std::string staticShaders::Opaque::vertexShaderGLSL(void)
{
	return
		R"V0G0N(

#version 330 core

// Input vertex data, different for all executions of this shader.
in vec3 a_Position ; //vertexPosition_modelspace;
in vec2 a_UV       ; //vertexUV;
in vec3 a_Normal   ; //vertexNormal_modelspace;

// Output data ; will be interpolated for each fragment.
out vec2 UV;
out vec4 ShadowCoord;

// Values that stay constant for the whole mesh.
uniform mat4 _MVP;
uniform mat4 _Light1Matrix;


void main()
{
	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  _MVP * vec4(a_Position,1);
	ShadowCoord = _Light1Matrix * vec4(a_Position,1);
	
	// UV of the vertex. No special space for this one.
	UV = a_UV;
}


)V0G0N";
    
}

//
// Fragment GLSL
//
std::string staticShaders::Opaque::fragmentShaderGLSL(void)
{
	return
		R"V0G0N(

#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;
in vec4 ShadowCoord;

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D _Texture;
uniform sampler2D _Light1Map; //sampler2DShadow shadowMap;

//float LinearizeDepth(vec2 uv)
//{
//	uv.y = 1 + uv.y*-1;
//
//	float n = 0.01; // camera z near
//	float f = 1000.0; // camera z far
//	float z = texture2D(_Light1Map, uv).x;.
//	return (2.0 * n) / (f + n - z * (f - n));	
//
//}

void main()
{
	// Light emission properties
	vec3 LightColor = vec3(1,1,1);
	
	// Material properties
	vec3 MaterialDiffuseColor = texture( _Texture, UV ).rgb;

	float bias = 0.005;
	float visibility = 1.0;
	if 
	(
		ShadowCoord.x >= 0 && ShadowCoord.x <= 1 &&
		ShadowCoord.y >= 0 && ShadowCoord.y <= 1
	)
		if ( texture( _Light1Map, ShadowCoord.xy ).z  <  ShadowCoord.z-bias)
		{
		    visibility = 0.5;
		
		}

	color = visibility * MaterialDiffuseColor * LightColor;

}

)V0G0N";
    
}
*/


#include "Opaque.h"

#include "../../../OpenGL/OpenGL.h"

using namespace guar;
using namespace GFX;

staticShaders::Opaque::Opaque() : StaticShaderProgram::StaticShaderProgram("Opaque",vertexShaderGLSL(),fragmentShaderGLSL()) {}

//
// OpenGL calls
//
void staticShaders::Opaque::glDrawCalls(void)
{
glClearColor(1.0f,0.0f,1.0f,0.0f);

}

//
// Vertex GLSL
//
std::string staticShaders::Opaque::vertexShaderGLSL(void)
{
return
R"V0G0N(

#version 150

uniform mat4 _MVP;

in vec3 a_Position;
in vec2 a_UV;
in vec3 a_Normal;

out vec3 fragVert;
out vec2 fragTexCoord;
out vec3 fragNormal;

out vec4 ShadowCoord;
uniform mat4 _Light1Matrix;

void main()
{
gl_Position = _MVP * vec4(a_Position, 1) ;

// Pass some variables to the fragment shader
fragTexCoord = a_UV       ;
fragNormal   = a_Normal   ;
fragVert     = a_Position ;



ShadowCoord = _Light1Matrix * vec4(a_Position,1);

}

)V0G0N";

}

//
// Fragment GLSL
//
std::string staticShaders::Opaque::fragmentShaderGLSL(void)
{
return
R"V0G0N(

#version 330

uniform mat4 _ModelMatrix;
uniform sampler2D _Texture;
uniform vec3 _Light1Position;
uniform mat4 _InverseTransposeModelMatrix;

uniform vec3 _CameraPosition;

//Shadowmaps
uniform sampler2D _Light1Map;
uniform mat4 _Light1Matrix;

//uniform struct Light
//{
//   vec3 position;
//   vec3 intensities; //a.k.a the color of the light
//} light;

in vec2 fragTexCoord;
in vec3 fragNormal;
in vec3 fragVert;

in vec4 ShadowCoord;

out vec4 finalColor;

void main()
{
vec3 position    = _Light1Position;
vec3 intensities = vec3(1.0);

float surfaceColora = 1.0;

//calculate normal in world coordinates
mat3 normalMatrix =  transpose(inverse(mat3(_ModelMatrix)));
vec3 normal = normalize(normalMatrix * fragNormal);

vec3 surfacePos = vec3(_ModelMatrix * vec4(fragVert, 1));

//calculate the location of this fragment (pixel) in world coordinates
vec3 fragPosition = vec3(_ModelMatrix * vec4(fragVert, 1));

//********
// AMBIENT
//********
vec3 ambient = vec3(1.0);//light.ambientCoefficient * surfaceColor.rgb * light.intensities;

//********
// DIFFUSE
//********
vec4 diffuseComponent;
{
//calculate the vector from this pixels surface to the light source
vec3 surfaceToLight = position - fragPosition;

//calculate the cosine of the angle of incidence
float brightness = dot(normal, surfaceToLight) / (length(surfaceToLight) * length(normal));
brightness = clamp(brightness, 0, 1);

//calculate final color of the pixel, based on:
// 1. The angle of incidence: brightness
// 2. The color/intensities of the light: intensities
// 3. The texture and texture coord: texture(tex, fragTexCoord)
vec4 surfaceColor = texture(_Texture, fragTexCoord);//texture(_Texture, fragTexCoord);//_Light1Map
diffuseComponent = vec4(brightness * intensities * surfaceColor.rgb, surfaceColor.a);

}

//*********
// SPECULAR
//*********
vec4 specularComponent;
{
float mymaterialshininess = 2.0;

vec3 surfaceToLight  = normalize(_Light1Position - fragPosition);
vec3 surfaceToCamera = normalize(_CameraPosition - fragPosition);

//vec3 viewDirection = normalize(vec3(v_inv * vec4(0.0, 0.0, 0.0, 1.0) - m * v_coord));

vec3 specularReflection;

if (dot(normal, surfaceToLight) < 0.0) // light source on the wrong side?
{
specularReflection = vec3(0.0, 0.0, 0.0); // no specular reflection
}
else
{
specularReflection =
vec3(pow(max(0.0, dot(reflect(-surfaceToLight, normal), surfaceToCamera)),mymaterialshininess));//mymaterial.shininess
}

specularComponent = vec4(specularReflection,1.0);

}

//************
// ATTENUATION
//************
{
//		//attenuation
//		//vec3 surfacePos = vec3(_ModelMatrix * vec4(fragVert, 1));
//		float lightattenuation = 1.0;
//
//		float distanceToLight = length(position - surfacePos);
//		float attenuation = 1.0 / (1.0 + lightattenuation * pow(distanceToLight, 2));
//
//		//linear color (color before gamma correction)
//		vec3 linearColor = ambient + attenuation*(diffuseComponent.xyz + specularComponent.xyz);
//
//		////final color (after gamma correction)
//		vec3 gamma = vec3(1.0/2.2);
//		finalColor = vec4(pow(linearColor, gamma), surfaceColora);

}

//finalColor = vec4(diffuseComponent.xyz + specularComponent.xyz * 0.5,1.0);//_Light1Map
vec3 ADSFinal = vec3(diffuseComponent.xyz + specularComponent.xyz * 0.5);//_Light1Map



	float bias = 0.005;
	float visibility = 1.0;
	if 
	(
	ShadowCoord.x >= 0 && ShadowCoord.x <= 1 &&
	ShadowCoord.y >= 0 && ShadowCoord.y <= 1
	)
	if ( texture( _Light1Map, ShadowCoord.xy ).z  <  ShadowCoord.z-bias)
	{
		visibility = 0.5;
	
	}
	//color = visibility * MaterialDiffuseColor * LightColor;


	finalColor = vec4(visibility*ADSFinal,1.0);

}

)V0G0N";

}


