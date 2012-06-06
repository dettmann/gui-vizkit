#ifndef MOTIONCOMMANDVISUALIZATION_H
#define MOTIONCOMMANDVISUALIZATION_H
#include <vizkit/Vizkit3DPlugin.hpp>
#include <base/motion_command.h>
#include <base/pose.h>
#include <osg/Shape>
#include <Eigen/Geometry>
#include <osg/Drawable>

namespace vizkit 
{

class MotionCommandVisualization : public Vizkit3DPlugin<base::MotionCommand2D>, public VizPluginAddType<base::Pose>
{
    Q_OBJECT

    public:
	MotionCommandVisualization();	
        ~MotionCommandVisualization();
        
        Q_INVOKABLE void updateData(const base::MotionCommand2D& data)
        { Vizkit3DPlugin<base::MotionCommand2D>::updateData(data); }
        Q_INVOKABLE void updateMotionCommand(const base::MotionCommand2D& data)
        { updateData(data); }
        Q_INVOKABLE void updateData(const base::Pose& data)
        { Vizkit3DPlugin<base::MotionCommand2D>::updateData(data); }
        Q_INVOKABLE void updatePose(const base::Pose& data)
        { updateData(data); }

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode( osg::Node* node );
	void updateDataIntern ( const base::MotionCommand2D& data );
        void updateDataIntern ( const base::Pose& data );

    private:
	double tv;
	double rv;
	osg::Vec3 robotPosition;
	osg::Quat robotOrientation;
	osg::ref_ptr<osg::Cylinder> motionPointer;
	osg::ref_ptr<osg::Cone> motionPointerHead;
	osg::ref_ptr<osg::Vec3Array> pointsOSG;
	osg::ref_ptr<osg::DrawArrays> drawArrays;
	osg::ref_ptr<osg::Geometry> geom;
	osg::ref_ptr<osg::PositionAttitudeTransform> arrowRotation;
	osg::ref_ptr<osg::PositionAttitudeTransform> positionTransformation;
	void drawRotation();
};

}
#endif // MOTIONCOMMANDVISUALIZATION_H
