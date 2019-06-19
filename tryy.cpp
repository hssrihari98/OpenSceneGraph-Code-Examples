// tryy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <osg/ShapeDrawable>
#include <osg/Geode>
#include <osg/BlendFunc>
#include <osg/Texture2D>
#include <osg/Geometry>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	
	osg::ref_ptr<osg::Group> myRoot = new osg::Group();
	
	osg::ref_ptr<osg::Node> body  = osgDB::readNodeFile("C:/EXAMPLE/tryy/tryy/cessna.osg");

	//osg::ref_ptr<osg::Node> body1 = osgDB::readNodeFile("textures/WING_BLUE.png");

	

	
	/*osg::ref_ptr<osg::Drawable> quad =
		osg::createTexturedQuadGeometry(osg::Vec3(),
		osg::Vec3(1.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 1.0f, 0.0f));*/
	

	//osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	//geode->addDrawable(quad.get());
	/*osg::ref_ptr<osg::ShapeDrawable> shape1 = new osg::ShapeDrawable;
	shape1->setShape(new osg::Box(osg::Vec3(-20.0f, 0.0f, 0.0f),
		10.0f, 10.0f, 10.0f));*/

	/*osg::ref_ptr<osg::ShapeDrawable> shape2 = new osg::ShapeDrawable;
	shape2->setShape(new osg::Sphere(osg::Vec3(3.0f, 0.0f, 0.0f),
	15.0f));*/
	//shape2->setColor(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));

	osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	osg::ref_ptr<osg::Image> image = osgDB::readImageFile("C:/EXAMPLE/tryy/tryy/pat1.bmp");
	texture->setImage(image.get());
	osg::ref_ptr<osg::StateSet> state = body->getOrCreateStateSet();
	state->setTextureAttributeAndModes(0, texture.get(), osg::StateAttribute::ON);

	/*osg::ref_ptr<osg::ShapeDrawable> shape3 = new osg::ShapeDrawable;
	shape3->setShape(new osg::Cone(osg::Vec3(0.0f, 0.0f, 0.0f),
		1.0f, 1.0f));
	shape3->setColor(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));*/




	//osg::ref_ptr<osg::Geode> root = new osg::Geode;
	myRoot->addChild(body.get());
	//myRoot->addChild(body1.get());
	//root->addDrawable(shape2.get());
	//root->addDrawable(shape3.get());
	osgViewer::Viewer viewer;
	viewer.setSceneData(myRoot.get());
	viewer.setUpViewOnSingleScreen(0);
	return viewer.run();
	return 0;
}

