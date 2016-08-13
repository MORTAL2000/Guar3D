#include "Physics.h"

//phy inc
#include "SceneGraphCollection\SceneGraphCollection.h"

using namespace guar;

//Data members
static PHY::SceneGraphCollection m_SceneGraphs;

void Physics::init(GLFWwindow* aWindowHandle)
{


}

void Physics::update(void) 
{


}

void Physics::terminate(void) 
{


}

std::weak_ptr<PHY::SceneGraph> Physics::getScene(const std::string &aName) 
{
	return m_SceneGraphs.find(aName);

}

std::weak_ptr<PHY::SceneGraph> Physics::createScene(const std::string &aName) 
{
	return m_SceneGraphs.createScene(aName);

}