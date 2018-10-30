#!/usr/bin/env python
import rospy
from performance_tests.msg import SuperAwesome

def talker():
    pub = rospy.Publisher('chatter', SuperAwesome, queue_size = 10)
    rospy.init_node('publisher', anonymous = True)
    
    loop_rate= 10 
    count = 0
    
    while not rospy.is_shutdown():
        rate = rospy.Rate(loop_rate) 
        begin_str = "%s" % rospy.get_time() #time when message is sent
        rospy.loginfo('Sending %d',loop_rate)
        pub.publish(begin_str)
        count += 1

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:  
      pass
