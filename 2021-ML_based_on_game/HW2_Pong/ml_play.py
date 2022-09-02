"""
The template of the script for the machine learning process in game pingpong
"""
import os
import pickle
import random
import numpy as np

class MLPlay:
    def __init__(self, side):
        """
        Constructor

        @param side A string "1P" or "2P" indicates that the `MLPlay` is used by
               which side.
        """
        self.ball_served = False
        self.previous_ball = (0, 0)
        self.side = side
        with open(os.path.join(os.path.dirname(__file__), 'model_1P.pickle'), 'rb') as f:
            self.model1 = pickle.load(f)
        with open(os.path.join(os.path.dirname(__file__), 'model_2P.pickle'), 'rb') as f1:
            self.model2 = pickle.load(f1)

    def update(self, scene_info):
        """
        Generate the command according to the received scene information
        """

        if scene_info["status"] != "GAME_ALIVE":
            print(scene_info["ball_speed"])
            return "RESET"

        if not self.ball_served:
            self.ball_served = True
            served_dir = random.randint(0, 1)
            if served_dir == 0:
                return "SERVE_TO_LEFT"
            else:
                return "SERVE_TO_RIGHT"
        else:
            # set the position and direction of ball
            ball_x = scene_info["ball"][0]
            ball_y = scene_info["ball"][1]
            ball_speed_x = scene_info["ball_speed"][0]
            ball_speed_y = scene_info["ball_speed"][1]
            platform_posx1 = scene_info["platform_1P"][0]
            platform_posx2 = scene_info["platform_2P"][0]
            # blocker_x = scene_info['blocker'][0]

            if ball_speed_x > 0:
                if ball_speed_y > 0:
                    Direction = 0
                else:
                    Direction = 1
            else:
                if ball_speed_y > 0:
                    Direction = 2
                else:
                    Direction = 3

            if self.side == "1P":
                x = np.array([ball_x, ball_y, platform_posx1, ball_speed_x, ball_speed_y, Direction]).reshape((1, -1))
                y = self.model1.predict(x)
            else:
                x = np.array([ball_x, ball_y, platform_posx2, ball_speed_x, ball_speed_y, Direction]).reshape((1, -1))
                y = self.model2.predict(x)

            # if ball_y >= 375:
            if y == -1:
                return "MOVE_LEFT"
            if y == 1:
                return "MOVE_RIGHT"
            if y == 0:
                return "NONE"
            # else:
            #     if y1 == -1:
            #         return "MOVE_LEFT"
            #     if  y1 == 1:
            #         return "MOVE_RIGHT"
            #     if y1 == 0:
            #         return "NONE"
            # if ball_x > platform_center + 20:
            #     ball_destination += 5

            #     if platform_posx + 20 > predicted_ball_pos:
            #         return "MOVE_LEFT"
            #     elif platform_posx + 20 < predicted_ball_pos:
            #         return "MOVE_RIGHT"
            #     elif platform_posx + 20 == predicted_ball_pos:
            #         return "NONE"
            # else:
            #     if platform_posx + 20 > predicted_ball_pos1:
            #         return "MOVE_LEFT"
            #     elif platform_posx + 20 < predicted_ball_pos1:
            #         return "MOVE_RIGHT"
            #     elif platform_posx + 20 == predicted_ball_pos1:
            #         return "NONE"
        self.previous_ball = scene_info["ball"]

    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False
