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

    # Umbralización para resaltar objetos de interés (por ejemplo, el pájaro)
    threshold = cv2.threshold(frame_new_np, 100, 255, cv2.THRESH_BINARY_INV)[1]
    #cv2.imshow('image', threshold)
    #cv2.waitKey(0)
    # Detección de contornos
    contours, _ = cv2.findContours(threshold, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Dibujar contornos en la imagen original
    cv2.drawContours(frame_new_np, contours, -1, (0, 255, 0), 2)
    
    for i, contour in enumerate(contours):
        
        # find player height via object localization
        if cv2.contourArea(contour) == 24*24:
            player_height_old = player_height_new
            player_height_new = 360 - 13 - contour[1][0][1]
            continue
        
        # find tube thresholds via object localization
        else:
            #if it's a pipe
            if cv2.contourArea(contour) != 3344 and cv2.contourArea(contour) != 3648:
                # if it's the lower pipe
                if contour[1][0][1] == 346:
                    block_jump_threshold = 360 - 13 - contour[0][0][1] + 30
                    continue

    if player_height_new <= block_jump_threshold or player_height_new <= 30:
        pyautogui.click(x=715, y=380)
        time.sleep(0.15)
        #break
        continue         