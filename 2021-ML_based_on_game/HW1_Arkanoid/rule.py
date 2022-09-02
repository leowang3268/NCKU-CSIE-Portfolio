"""
The template of the main script of the machine learning process
"""
import os
import pickle
import random
import numpy as np

class MLPlay:
    def __init__(self):
        """
        Constructor
        """
        self.ball_served = False
        self.previous_ball = (0, 0)
        self.plat_init_pos = 75
        self.has_arrived = False

    def update(self, scene_info):
        """
        Generate the command according to the received `scene_info`.
        """
        # Make the caller to invoke `reset()` for the next round.
        if (scene_info["status"] == "GAME_OVER" or
                scene_info["status"] == "GAME_PASS"):
            return "RESET"

        if not self.ball_served:

            if scene_info["platform"][0] < self.plat_init_pos:
                command = "MOVE_RIGHT"
            elif scene_info["platform"][0] > self.plat_init_pos:
                command = "MOVE_LEFT"
            else:
                self.has_arrived = True
                command = "NONE"

            if self.has_arrived == True:
                self.ball_served = True
                command = "SERVE_TO_RIGHT"

        else:

            ball_x = scene_info["ball"][0]
            ball_y = scene_info["ball"][1]
            ball_speed_x = scene_info["ball"][0] - self.previous_ball[0]
            ball_speed_y = scene_info["ball"][1] - self.previous_ball[1]
            platform_center = scene_info["platform"][0] + 20
            ball_destination = 0

            for i in range(len(scene_info["bricks"])):
                brick_left = scene_info["bricks"][i][0]
                brick_top = scene_info["bricks"][i][1]
                brick_height = 10
                brick_width = 25
                brick_right = brick_left + brick_width
                brick_bottom = brick_top + brick_height

                for j in range(0, 58):

                    ball_vector_x = ball_x + j * ball_speed_x
                    ball_vector_y = ball_y + j * ball_speed_y

                    if ball_speed_x > 0 and ball_vector_x >= brick_left and ball_vector_x <= brick_right:
                        if ball_speed_y != 0 and ball_vector_y >= brick_top and ball_vector_y <= brick_bottom:
                            ball_x = brick_left
                            ball_speed_x *= -1
                            break

                    elif ball_speed_x < 0 and ball_vector_x >= brick_left and ball_vector_x <= brick_right:
                        if ball_speed_y != 0 and ball_vector_y >= brick_top and ball_vector_y <= brick_bottom:
                            ball_x = brick_right
                            ball_speed_x *= -1
                            break

                for k in range(0, 58):

                    ball_vector_x = ball_x + k * ball_speed_x
                    ball_vector_y = ball_y + k * ball_speed_y

                    if ball_speed_y > 0 and ball_vector_y >= brick_top and ball_vector_y <= brick_bottom:
                        if ball_speed_x != 0 and ball_vector_x >= brick_left and ball_vector_x <= brick_right:
                            ball_y = brick_top
                            ball_speed_y *= -1
                            break

                    if ball_speed_y < 0 and ball_vector_y >= brick_top and ball_vector_y <= brick_bottom:
                        if ball_speed_x != 0 and ball_vector_x >= brick_left and ball_vector_x <= brick_right:
                            ball_y = brick_bottom
                            ball_speed_y *= -1
                            break

            if ball_speed_y != 0:
                ball_destination = ball_x + ((395 - ball_y) / ball_speed_y) * ball_speed_x

                if ball_destination >= 195:
                    ball_destination = 390 - ball_destination

                elif ball_destination <= 0:
                    ball_destination = -ball_destination

            else:
                ball_destination = platform_center

            if platform_center < ball_destination:
                command = "MOVE_RIGHT"
            elif platform_center > ball_destination:
                command = "MOVE_LEFT"
            else:
                command = "NONE"

        self.previous_ball = scene_info["ball"]
        return command

    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False