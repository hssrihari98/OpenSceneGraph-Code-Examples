#include "stdafx.h"
#include <osg/Geode>
#include <osg/Geometry>
#include <osgViewer/Viewer>
#include <osg/ref_ptr>
#include <osgDB/Registry>
#include <osgDB/WriteFile>
#include <osg/Notify>
#include <iostream>
#include <osg/ShapeDrawable>
#include <osg/BlendFunc>
#include <osg/Material>
#include <osg/PolygonMode>
#include <osg/LightSource>
#include <osg/Point>

using std::endl;

osg::ref_ptr<osg::Node> createSceneGraph()
{
	// Create an object to store geometry in.
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	// Create an array of four vertices.
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
	geom->setVertexArray(v.get());
	v->push_back(osg::Vec3(1.f, 1.f, 0.f));
	v->push_back(osg::Vec3(3.f, 1.f, 0.f));
	v->push_back(osg::Vec3(3.f, 3.f, 0.f));
	v->push_back(osg::Vec3(1.f, 3.f, 0.f));

	/*v->push_back(osg::Vec3(1.f, 1.f, 0.f));
	v->push_back(osg::Vec3(3.f, 1.f, 0.f));
	v->push_back(osg::Vec3(3.f, 3.f, 0.f));
	v->push_back(osg::Vec3(2.f, 4.f, 0.f));
	v->push_back(osg::Vec3(1.f, 3.f, 0.f));*/
	

	// Create an array of four colors.
	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	c->push_back(osg::Vec4(1.f, 0.f, 0.f, 1.f));
	c->push_back(osg::Vec4(0.f, 1.f, 0.f, 1.f));
	c->push_back(osg::Vec4(0.f, 0.f, 1.f, 1.f));
	c->push_back(osg::Vec4(1.f, 1.f, 1.f, 1.f));


	// Create an array for the single normal.
	osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array;
	geom->setNormalArray(n.get());
	geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
	n->push_back(osg::Vec3(0.f, 0.f, -1.f));

	osg::ref_ptr<osg::ShapeDrawable> shape1 = new osg::ShapeDrawable;
	shape1->setShape(new osg::Box(osg::Vec3(2.0f, 2.0f, 1.0f),
		2.0f, 2.0f, 2.0f));
	shape1->setColor(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));

	osg::StateSet* state2 = shape1->getOrCreateStateSet(); //Creating material
	osg::ref_ptr<osg::Material> mat2 = new osg::Material;

	mat2->setAlpha(osg::Material::FRONT_AND_BACK, 0.1); //Making alpha channel
	state2->setAttributeAndModes(mat2.get(),
		osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);

	osg::BlendFunc* bf = new                        //Blending
		osg::BlendFunc(osg::BlendFunc::SRC_ALPHA,
		osg::BlendFunc::ONE_MINUS_DST_COLOR);
	state2->setAttributeAndModes(bf);

	osg::ref_ptr<osg::ShapeDrawable> shape2 = new osg::ShapeDrawable;
	shape2->setShape(new osg::Sphere(osg::Vec3(6.0f, 2.0f, 1.0f),
	2.0f));
	shape2->setColor(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));

	// Draw a four-vertex quad from the stored data.
	geom->addPrimitiveSet(
		new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
	// Add the Geometry (Drawable) to a Geode and
	// return the Geode.
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(geom.get());
	geode->addDrawable(shape1.get());
	geode->addDrawable(shape2.get());
	return geode.get();
}

int main(int, char**)
{
	//do this if you want to write to .osg file rather than using a viewer
	/*osg::ref_ptr<osg::Node> root = createSceneGraph();
	if (!root.valid())
		osg::notify(osg::FATAL) <<
		"Failed in createSceneGraph()." << endl;
	bool result = osgDB::writeNodeFile(
		*(root.get()), "Simple.osg");
	if (!result)
		osg::notify(osg::FATAL) <<
		"Failed in osgDB::writeNodeFile()." << endl;
		getchar();
	return 0;*/

	osgViewer::Viewer v;
	v.setSceneData(createSceneGraph());
	return v.run();

	getchar();
}

