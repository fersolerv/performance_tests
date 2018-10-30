#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome
from std_msgs.msg import Float64

p_time = 0
pub = rospy.Publisher('rate', Float64, queue_size = 1000)

def callback(data):
    global p_time
    #begintime = data.data
    #begintimef= float(begintime)

    #endtime = "%s" % rospy.get_time()
    #endtimef = float(endtime)
    #rospy.loginfo('Receiving %f', endtimef-begintimef) 
    now = rospy.get_time()
    el_time = now - p_time
    p_time = now
    freq_rate = 1 / el_time
    
    rospy.loginfo("Rate %f", freq_rate)

def listener():

    rospy.init_node('subscriber', anonymous = True)
    rospy.Subscriber('chatter', SuperAwesome, callback)
    rospy.spin()

if __name__ == '__main__':
  listener()