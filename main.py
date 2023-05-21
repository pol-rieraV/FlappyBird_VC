import pyautogui
import numpy as np
import time
import cv2
import copy
import PIL
import time

player_pos_x = 40
player_size = 25
pipe_width = 250
ground_height = 13

block_jump_threshold = 25

player_color_gray = 99
block_color_gray = 80
background_color = 245

player_height_old = 180
player_height_new = 0

time_old = 0
time_new = time.time()

while(True):
    #frame_new = pyautogui.screenshot(region=(635,340,1285,740))
    frame_new = pyautogui.screenshot(region=(705,375,305,360))
    #frame_new.save("./screenshot.png")
    frame_new_g = PIL.ImageOps.grayscale(frame_new)
    frame_new_np = np.asarray(frame_new.convert('L'))

    # calculate new player height
    for i, pixel in enumerate(frame_new_np[:,player_pos_x]):           
        if pixel == player_color_gray:
            player_height_old = player_height_new
            player_height_new = 360 - i - player_size - 13
            time_old = time_new
            time_new = time.time()
            break
    
    # calc block_jump_threshold
    pipe_location = -1
    block_jump_threshold = 30
    for j, pixel in enumerate(frame_new_np[25, :]):
        if pixel == block_color_gray and (j + pipe_width) > (player_pos_x + player_size):
            pipe_location = j 
            break
        
    #print(pipe_location)
    if pipe_location != -1:
        for k, pixel in enumerate(frame_new_np[:,pipe_location]):
            if pixel == background_color or pixel == player_color_gray:
                block_jump_threshold = 360 - 150 - k - 13 + 30
                if block_jump_threshold < 30:
                    block_jump_threshold = 30
                break
    #print(block_jump_threshold)
    #print()
    
    # decide player actions
    
    if player_height_new <= block_jump_threshold or player_height_new <= 30:
        pyautogui.click(x=715, y=380)
        time.sleep(0.15)
        continue
#    else:
        # calc player_height_next 
        # previous  60
        # new       70
        # next = (70 - 60) / time_difference
#        player_height_next = player_height_new + (player_height_new - player_height_old) / (time_new - time_old + 0.15)
#        if player_height_next <= block_jump_threshold:
#            pyautogui.click(x=715, y=380)
#            time.sleep(0.15)
#            continue
                