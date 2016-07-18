#! /usr/bin/env python

import rospy

def run():
    rospy.init_node('boilerplate')

    rospy.loginfo('Node started')

    rospy.sleep(0.5)


    rospy.loginfo('Running until shutdown (Ctrl-C).')
    while not rospy.is_shutdown():
        rospy.sleep(0.1)

    rospy.loginfo('Node finished')

if __name__ == '__main__':
    run()
