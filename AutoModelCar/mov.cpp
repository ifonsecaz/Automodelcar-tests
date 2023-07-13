#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointField.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointField.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/UInt16MultiArray.h>
#include <std_msgs/UInt8MultiArray.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Int16.h>
#include <std_msgs/String.h>
#include <stdint.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <unistd.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/conversions.h>
#include <boost/foreach.hpp>

//ros::NodeHandle nh;

//ros::Subscriber sub


ros::Publisher velocity_publisher; 
ros::Publisher steering_publisher; 

int carril=2; //3 c
int ncarril=2;
int termino=0;
int evadir;
int f1=0;
sensor_msgs::PointCloud2 msg2;
int16_t esquiva;

void camaraRGBCallback(const sensor_msgs::PointCloud2& msg)
{
  msg2=msg;
  
}

void esquivaCallback(const std_msgs::Int16& msg)
{	
  esquiva=msg.data;
  ROS_INFO_STREAM("Esquivar: ");
  //suscribe a detecciones dan el centro
  //3 carriles->2 rectas
  //ec1 m -1.17, b 619
  //y0 x0
  //yC=m*x0+b
  //ec2 m 1.16, b -405.28
  //yC2=m*x0+b
  //if(y0>yC and y0<yC2)
  //obs en carril 2
  //if(y0<yC)
  //carril 1
  //if(y0>yC2)
  //carril 3
  if(termino==0){
  	evadir=0;
  	termino=1;
  }
}

void movimiento(int cont){
	ros::NodeHandle nh ("~");
	velocity_publisher = nh.advertise<std_msgs::Int16>("/AutoNOMOS_mini/manual_control/speed", 1);
        steering_publisher = nh.advertise<std_msgs::Int16>("/AutoNOMOS_mini/manual_control/steering", 1);
	std_msgs::Int16 velocity_message;
  	std_msgs::Int16 steering_message;
	if(cont<160){
		if(esquiva==carril && evadir<40){
		    	ROS_INFO_STREAM("CambiandoCarril");
			if(carril==1){
				if(f1==0){
					velocity_message.data=-80;
					steering_message.data=20;
					ncarril=2;	
					if(evadir>20){
						f1=1;
					}
				}
				else{
					velocity_message.data=-80;
					steering_message.data=160;
				}
			}
			else{
				if(carril==3){
					if(f1==0){
						velocity_message.data=-80;
						steering_message.data=160;	
						ncarril=2;
						if(evadir>20){
							f1=1;
						}
					}
					else{
						velocity_message.data=-80;
						steering_message.data=20;
					}
				}
				else{
					if(f1==0){
						velocity_message.data=-80;
						steering_message.data=20;	
						ncarril=1;
						if(evadir>20){
							f1=1;
						}
					}
					else{
						velocity_message.data=-80;
						steering_message.data=160;
					}
				}
			}
		}
		else{
		velocity_message.data=-100;
    		steering_message.data=90;
    		termino=0;
    		carril=ncarril;
    		f1=0;
    		}
	}
	else{
		if(carril==1){
			velocity_message.data=-80;
    			steering_message.data=20;
    		}
    		else{
    			if(carril==2){
				velocity_message.data=-70;
    				steering_message.data=10;
    			}
    			else{
    				velocity_message.data=-60;
    				steering_message.data=0;
    			}
    		}
    		
	}
	velocity_publisher.publish(velocity_message);
    	steering_publisher.publish(steering_message);
    	evadir=evadir+1;
    	ROS_INFO_STREAM("Velocidad: " << velocity_message << " Steering: " << steering_message);
}


int main(int argc, char** argv){
  ros::init(argc, argv, "mov_carro");

  ros::NodeHandle nh("~");
  ros::Subscriber camara_sub = nh.subscribe("/depth/points", 10, camaraRGBCallback);
  ros::Subscriber esquiva = nh.subscribe("/obs", 10, esquivaCallback);

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
  
  //ros::Publisher velocity_publisher = nh.advertise<std_msgs::Int16>("/AutoNOMOS_mini/manual_control/speed", 1);
  //ros::Publisher steering_publisher = nh.advertise<std_msgs::Int16>("/AutoNOMOS_mini/manual_control/steering", 1);

  //std_msgs::Int16 velocity_message;
  //std_msgs::Int16 steering_message;
  
  int cont=0;

  ros::Rate r(5);
  sleep(2);
  while(nh.ok()){
  
    if(cont>340){
    	cont=0;
    }
    ros::spinOnce();               // check for incoming messages
    current_time = ros::Time::now();
    last_time = current_time;
    
    movimiento(cont);
    ROS_INFO_STREAM("Contador " << cont);
    /*
    velocity_message.data=-100;
    steering_message.data=90;
    velocity_publisher.publish(velocity_message);
    steering_publisher.publish(steering_message);
    ROS_INFO_STREAM("Velocidad: " << velocity_message << " Steering: " << steering_message);
    sleep(10);
    
    velocity_message.data=-80;
    steering_message.data=30;
    velocity_publisher.publish(velocity_message);
    steering_publisher.publish(steering_message);
    ROS_INFO_STREAM("Velocidad: " << velocity_message << " Steering: " << steering_message);
    sleep(15);
 	*/
    cont=cont+1;	  
    r.sleep();
  }
}
