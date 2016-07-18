import rospy
from std_msgs.msg import String


class BoilerPlate(object):
    def __init__(self):
        self._pub = rospy.Publisher('/foo', String, queue_size=10)
        self._sub = rospy.Subscriber('/foo', String, self.string_cb)
        self._x = 0


    def string_cb(self, msg):
        rospy.loginfo('Received {}'.format(msg.data))
        pass

    def run_once(self):
        self._x += 1
        self._pub.publish('Hello world #{}'.format(self._x))
        pass
