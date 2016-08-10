#include "AlphaCutOff.h"

#include "../../../OpenGL/OpenGL.h"

using namespace guar;
using namespace GFX;

staticShaders::AlphaCutOff::AlphaCutOff() : StaticShaderProgram::StaticShaderProgram("AlphaCutOff",vertexShaderGLSL(),fragmentShaderGLSL()) {}

//
// OpenGL calls
//
void staticShaders::AlphaCutOff::glDrawCalls(void)
{
    glClearColor(1.0f,0.0f,1.0f,0.0f);
    
}

//
// Vertex GLSL
//
std::string staticShaders::AlphaCutOff::vertexShaderGLSL(void)
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

void main() 
{
    gl_Position = _MVP * vec4(a_Position, 1) ;
	
    // Pass some variables to the fragment shader
    fragTexCoord = a_UV       ;
    fragNormal   = a_Normal   ;
    fragVert     = a_Position ;



	
}

)V0G0N";
    
}

//
// Fragment GLSL
//
std::string staticShaders::AlphaCutOff::fragmentShaderGLSL(void)
{
	return
		R"V0G0N(

#version 150

uniform mat4 _ModelMatrix;
uniform sampler2D _Texture;
uniform vec3 _Light1Position;
uniform mat4 _InverseTransposeModelMatrix;

uniform vec3 _CameraPosition;

//uniform struct Light 
//{
//   vec3 position;
//   vec3 intensities; //a.k.a the color of the light
//} light;

in vec2 fragTexCoord;
in vec3 fragNormal;
in vec3 fragVert;

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
		vec4 surfaceColor = texture(_Texture, fragTexCoord);
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

	finalColor = vec4(diffuseComponent.xyz + specularComponent.xyz * 0.5,1.0);

	finalColor = texture(_Texture, fragTexCoord);
	
}

)V0G0N";
    
}
