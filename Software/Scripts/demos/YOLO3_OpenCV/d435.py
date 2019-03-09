 ===============================================================================
# PROGRAM METADATA
# ===============================================================================
__author__ = 'Pedro Machado'
__contact__ = 'pedro.baptistamachado@ntu.ac.uk'
__copyright__ = 'Enhanced grasping project can not be copied and/or distributed \
without the express permission of Prof. Martin McGinnity <martin.mcginnity@ntu.ac.uk'
__license__ = '2019 (C) CNCR@NTU, All rights reserved'
__date__ = '13/02/2019'
__version__ = '0.1'
__file_name__ = 'd435.py'
__description__ = 'Intel D435 class'


#===============================================================================
# IMPORT STATEMENTS
#===============================================================================
import pyrealsense2 as rs
#===============================================================================
# GLOBAL VARIABLES DECLARATIONS
#===============================================================================

#===============================================================================
# METHODS
#===============================================================================

class d435():
    def __init__(self):
        self.__fps__ = [6, 15, 25, 30, 60, 90] # 3 - default
        self.__resolution__ = [[424, 240],
					  [480, 270],
					  [640, 360],
					  [640, 400],
					  [640, 480],
					  [848, 480],  # USB3 only - default
					  [1280, 720],  # USB3 only
					  [1280, 800]]  # USB3 only
        self.__fps_index__ = 3  # 3 - default
        self.__resolution_index__ = 4  # 4 - default
        self.__nir__ = False

    def getConfiguration(self):
        return self.__resolution__[self.__resolution_index__], self.__fps__[self.__fps_index__], self.__nir__

    def setConfiguration(self,fps,resolution,nir):
        if -1<fps<len(self.__fps__) and -1<resolution<len(self.__resolution__) and isinstance(nir,(bool)):
            self.__fps_index__=fps
            self.__resolution_index__=resolution
            self.__nir__=nir
            return 0
        else:
            return -1

    def setup(self):
        # Configure depth and color streams
        pipeline = rs.pipeline()
        config = rs.config()
        config.enable_stream(rs.stream.depth, self.__resolution__[self.__resolution_index__][0], self.__resolution__[self.__resolution_index__][1],
                             rs.format.z16, self.__fps__[self.__fps_index__])
        config.enable_stream(rs.stream.color, self.__resolution__[self.__resolution_index__][0], self.__resolution__[self.__resolution_index__][1],
                             rs.format.bgr8, self.__fps__[self.__fps_index__])
        if self.__nir__:
            config.enable_stream(rs.stream.infrared, 1, self.__resolution__[self.__resolution_index__][0],
                                 self.__resolution__[self.__resolution_index__][1], rs.format.y8, self.__fps__[self.__fps_index__])
            config.enable_stream(rs.stream.infrared, 2, self.__resolution__[self.__resolution_index__][0],
                                 self.__resolution__[self.__resolution_index__][1], rs.format.y8, self.__fps__[self.__fps_index__])

        # Start streaming
        try:
            profile = pipeline.start(config)
        except:
            print("Incorrect profile. (1) Check the USB connectivity! (2) Check the parameters.")
        # Getting the depth sensor's depth scale (see rs-align example for explanation)
        depth_sensor = profile.get_device().first_depth_sensor()
        depth_scale = depth_sensor.get_depth_scale()
        # print("Depth Scale is: ", depth_scale)

        # We will be removing the background of objects more than
        #  clipping_distance_in_meters meters away
        clipping_distance_in_meters = 1  # 1 meter
        clipping_distance = clipping_distance_in_meters / depth_scale
        align_to = rs.stream.color
        align = rs.align(align_to)
        return pipeline, align, clipping_distance, self.__nir__

    def resetConfiguration(self):
        self.__fps_index__ = 3
        self.__resolution_index__ = 4
        self.__nir__=False

    def listParameters(self):
        return self.__fps__, self.__resolution__

    def __del__(self):
        print("Camera closed with success!")
