/*
 *  Core.h
 *  QtGLEngine
 *
 *  Created by Rob Rau on 12/26/10.
 *  Copyright 2010 Robert F. Rau II. All rights reserved.
 *
 */
#include "Core.h"

Core::Core()
{
	mRenderWindow = NULL;
	mSceneTree = NULL;
}

Core::~Core()
{

}

RenderWindow* Core::createRenderWindow(string name, int width, int height, bool fullScreen)
{
#ifdef __APPLE__
	mRenderWindow = new OSXRenderWindow(name, width, height, fullScreen);
#else
	mRenderWindow = new Win32RenderWindow(name, width, height, fullScreen);
#endif
	return mRenderWindow;
}

SceneTree* Core::createSceneTree()
{
	if(mRenderWindow)
	{
		mSceneTree = new SceneTree(mRenderWindow);
		return mSceneTree;
	}
	return 0;
}

void Core::startRendering()
{
	mRenderWindow->_start();
}

Object* Core::createObject(string _name)
{
	return mRenderWindow->_newObject(_name);
}

void Core::registerObject(string _name, Object* obj)
{
	mRenderWindow->_registerObject(_name, obj);
}

Object* Core::getObject(string _name)
{
	return mRenderWindow->_getObject(_name);
}

Camera* Core::createCamera()
{
	return mRenderWindow->createCamera();
}

void Core::setInputHandler(InputHandler *inputHandler)
{
	mRenderWindow->setInputHandler(inputHandler);
}

void Core::setEventListener(EventListener* eventListener)
{
	if(mRenderWindow)
		mRenderWindow->setEventListener(eventListener);
}